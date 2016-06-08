#include "itkthread.h"
#include <itkHessian3DToVesselnessMeasureImageFilter.h>
#include <itkHessianRecursiveGaussianImageFilter.h>
#include <itkImageFileReader.h>
#include <itkImageFileWriter.h>
#include <itkCastImageFilter.h>
#include <itkRescaleIntensityImageFilter.h>
#include <itkThresholdImageFilter.h>
#include <vtkImageData.h>
#include <vtkSmartPointer.h>
#include <itkVTKImageToImageFilter.h>
#include <itkImageToVTKImageFilter.h>
#include <vtkPointData.h>
#include<QFileDialog>
#include <itkImage.h>
#include <QuickView.h>
#include <vtkVersion.h>
#include <vtkAssemblyPath.h>
#include <vtkCell.h>
#include <vtkCommand.h>
#include <vtkCornerAnnotation.h>
#include <vtkImageActor.h>
#include <vtkImageData.h>
#include <vtkImageViewer2.h>
#include <vtkInteractorStyleImage.h>
#include <vtkTIFFReader.h>
#include <vtkPointData.h>
#include <vtkPropPicker.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkTextProperty.h>
#include <vtkImageNoiseSource.h>
#include <vtkImageCast.h>
#include <vtkMath.h>
#include<vtkImageReslice.h>
#include <vtkImageResliceMapper.h>

using namespace std;

// Template for image value reading
template<typename T>
void vtkValueMessageTemplate(vtkImageData* image, int* position,
	std::string& message)
{
	T* tuple = ((T*)image->GetScalarPointer(position));
	int components = image->GetNumberOfScalarComponents();
	for (int c = 0; c < components; ++c)
	{
		message += vtkVariant(tuple[c]).ToString();
		if (c != (components - 1))
		{
			message += ", ";
		}
	}
	message += " )";
}

// The mouse motion callback, to pick the image and recover pixel values
class vtkImageInteractionCallback : public vtkCommand
{
public:
	static vtkImageInteractionCallback *New()
	{
		return new vtkImageInteractionCallback;
	}

	vtkImageInteractionCallback()
	{
		this->Viewer = NULL;
		this->Picker = NULL;
		this->Annotation = NULL;
	}

	~vtkImageInteractionCallback()
	{
		this->Viewer = NULL;
		this->Picker = NULL;
		this->Annotation = NULL;
	}

	void SetPicker(vtkPropPicker *picker)
	{
		this->Picker = picker;
	}

	void SetAnnotation(vtkCornerAnnotation *annotation)
	{
		this->Annotation = annotation;
	}

	void SetViewer(vtkImageViewer2 *viewer)
	{
		this->Viewer = viewer;
	}

	virtual void Execute(vtkObject *, unsigned long vtkNotUsed(event), void *)
	{
		vtkRenderWindowInteractor *interactor =
			this->Viewer->GetRenderWindow()->GetInteractor();
		vtkRenderer* renderer = this->Viewer->GetRenderer();
		vtkImageActor* actor = this->Viewer->GetImageActor();
		vtkImageData* image = this->Viewer->GetInput();
		vtkInteractorStyle *style = vtkInteractorStyle::SafeDownCast(
			interactor->GetInteractorStyle());

		// Pick at the mouse location provided by the interactor
		this->Picker->Pick(interactor->GetEventPosition()[0],
			interactor->GetEventPosition()[1],
			0.0, renderer);

		// There could be other props assigned to this picker, so 
		// make sure we picked the image actor
		vtkAssemblyPath* path = this->Picker->GetPath();
		bool validPick = false;

		if (path)
		{
			vtkCollectionSimpleIterator sit;
			path->InitTraversal(sit);
			vtkAssemblyNode *node;
			for (int i = 0; i < path->GetNumberOfItems() && !validPick; ++i)
			{
				node = path->GetNextNode(sit);
				if (actor == vtkImageActor::SafeDownCast(node->GetViewProp()))
				{
					validPick = true;
				}
			}
		}

		if (!validPick)
		{
			this->Annotation->SetText(0, "Off Image");
			interactor->Render();
			// Pass the event further on
			style->OnMouseMove();
			return;
		}

		// Get the world coordinates of the pick
		double pos[3];

		this->Picker->GetPickPosition(pos);


		int image_coordinate[3];

		int axis = this->Viewer->GetSliceOrientation();
		switch (axis)
		{
		case vtkImageViewer2::SLICE_ORIENTATION_XZ:
			image_coordinate[0] = vtkMath::Round(pos[0]);
			image_coordinate[1] = this->Viewer->GetSlice();
			image_coordinate[2] = vtkMath::Round(pos[2]);
			break;
		case vtkImageViewer2::SLICE_ORIENTATION_YZ:
			image_coordinate[0] = this->Viewer->GetSlice();
			image_coordinate[1] = vtkMath::Round(pos[0]);
			image_coordinate[2] = vtkMath::Round(pos[1]);
			break;
		default:  // vtkImageViewer2::SLICE_ORIENTATION_XY
			image_coordinate[0] = vtkMath::Round(pos[0]);
			image_coordinate[1] = vtkMath::Round(pos[1]);
			image_coordinate[2] = this->Viewer->GetSlice();
			break;
		}

		std::string message = "Location: ( ";
		message += vtkVariant(image_coordinate[0]).ToString();
		message += ", ";
		message += vtkVariant(image_coordinate[1]).ToString();
		message += ", ";
		message += vtkVariant(image_coordinate[2]).ToString();
		message += " )\nValue: ( ";

		switch (image->GetScalarType())
		{
			vtkTemplateMacro((vtkValueMessageTemplate<VTK_TT>(image,
				image_coordinate,
				message)));

		default:
			return;
		}

		this->Annotation->SetText(0, message.c_str());
		interactor->Render();
		style->OnMouseMove();
	}

private:
	vtkImageViewer2*      Viewer;      // Pointer to the viewer
	vtkPropPicker*        Picker;      // Pointer to the picker
	vtkCornerAnnotation*  Annotation;  // Pointer to the annotation
};

itkthread::itkthread()
{
	threshimg = vtkSmartPointer <vtkImageData>::New();
}


void itkthread::process(string fullprefix,int zlb, int zub, double sigma, double alpha1, double alpha2)
{
    typedef unsigned char PixelType;
    const unsigned int Dimension = 3;
    typedef itk::Image< PixelType, Dimension >    ImageType;
    // Software Guide : EndCodeSnippet
    // Software Guide : BeginLatex
    //
    // The image type is used as a template parameter to instantiate
    // the series reader and the volumetric writer.
    //
    // \index{itk::ImageSeriesReader!RGB Image}
    // \index{itk::ImageFileWriter!RGB Image}
    //
    // Software Guide : EndLatex
    // Software Guide : BeginCodeSnippet
    typedef itk::ImageSeriesReader< ImageType >  SeriesReaderType;
    //typedef itk::ImageFileWriter<   ImageType >  WriterType;
    SeriesReaderType::Pointer seriesReader = SeriesReaderType::New();
    //WriterType::Pointer       writer = WriterType::New();
    // Software Guide : EndCodeSnippet
    const unsigned int first = zlb;
    const unsigned int last = zub-1;
    std::cout<<last;
    //const char * outputFilename = argv[3];
    // Software Guide : BeginLatex
    //
    // We use a NumericSeriesFileNames class in order to generate the filenames of
    // the slices to be read. Later on in this example we will reuse this object in
    // order to generate the filenames of the slices to be written.
    //
    // Software Guide : EndLatex
    // Software Guide : BeginCodeSnippet
    typedef itk::NumericSeriesFileNames    NameGeneratorType;
    NameGeneratorType::Pointer nameGenerator = NameGeneratorType::New();
    nameGenerator->SetStartIndex(first);
    nameGenerator->SetEndIndex(last);
    nameGenerator->SetIncrementIndex(1);

    nameGenerator->SetSeriesFormat(fullprefix.c_str());
    // Software Guide : EndCodeSnippet
    //  Software Guide : BeginLatex
    //
    //  The ImageIO object that actually performs the read process
    //  is now connected to the ImageSeriesReader.
    //

    seriesReader->SetImageIO(itk::TIFFImageIO::New());


    //  The filenames of the input slices are taken from the names generator and
    //  passed to the series reader.
    //

    seriesReader->SetFileNames(nameGenerator->GetFileNames());






    //	const   unsigned int        Dimension = 3;
        typedef unsigned char              InputPixelType;

        typedef float                OutputPixelType;
        typedef itk::Image< InputPixelType, Dimension >   InputImageType;
        typedef itk::Image< OutputPixelType, Dimension >  OutputImageType;
    //    typedef itk::Image<float , Dimension>  OutputPixelType;


    //Convert output to float
    typedef itk::CastImageFilter<  InputImageType ,OutputImageType> CastFilterType1;
    CastFilterType1::Pointer castFilter1 = CastFilterType1::New();
    castFilter1->SetInput(seriesReader->GetOutput());



	

    //Rescale intensity of the output of vesselness filter to uchar (0-255)
    typedef itk::RescaleIntensityImageFilter< OutputImageType, OutputImageType >
        RescaleType1;
    RescaleType1::Pointer rescale1 = RescaleType1::New();
    rescale1->SetInput(castFilter1->GetOutput());
    rescale1->SetOutputMinimum(0);
    rescale1->SetOutputMaximum(itk::NumericTraits< OutputPixelType >::max());
/*
    //Threshold the volume
    double lowerThreshold = 0;
    typedef itk::ThresholdImageFilter <ImageType>
		ThresholdImageFilterType;
	ThresholdImageFilterType::Pointer thresholdFilter
		= ThresholdImageFilterType::New();
    thresholdFilter->SetInput(seriesReader->GetOutput());
    thresholdFilter->ThresholdBelow(lowerThreshold);
	thresholdFilter->SetOutsideValue(0);
*/
	//Compute Hessian
    typedef itk::HessianRecursiveGaussianImageFilter< OutputImageType >
		HessianFilterType;
	HessianFilterType::Pointer hessianFilter = HessianFilterType::New();
    hessianFilter->SetInput(rescale1->GetOutput());
	if (sigma)
	{
        hessianFilter->SetSigma(sigma);
	}


	//Apply vesselness filter
    typedef itk::Hessian3DToVesselnessMeasureImageFilter< OutputPixelType >
		VesselnessMeasureFilterType;
	VesselnessMeasureFilterType::Pointer vesselnessFilter = VesselnessMeasureFilterType::New();
	vesselnessFilter->SetInput(hessianFilter->GetOutput());

	if (alpha1)
	{
		vesselnessFilter->SetAlpha1(alpha1);
	}
	if (alpha2)
	{
		vesselnessFilter->SetAlpha2(alpha2);
	}

	typedef unsigned char              UnsignedCharPixelType;
	typedef itk::Image<UnsignedCharPixelType, 3>  UnsignedCharImageType;

	//Rescale intensity of the output of vesselness filter to uchar (0-255)
    typedef itk::RescaleIntensityImageFilter< OutputImageType, OutputImageType >
		RescaleType;
	RescaleType::Pointer rescale = RescaleType::New();
	rescale->SetInput(vesselnessFilter->GetOutput());
	rescale->SetOutputMinimum(0);
	rescale->SetOutputMaximum(itk::NumericTraits< UnsignedCharPixelType >::max());

	//Convert output to 8-bit uchar
	typedef itk::CastImageFilter< OutputImageType, UnsignedCharImageType > CastFilterType;
	CastFilterType::Pointer castFilter = CastFilterType::New();
	castFilter->SetInput(rescale->GetOutput());

    typedef itk::Image< PixelType, 2 >     Image2DType;
    typedef itk::ImageSeriesWriter< ImageType, Image2DType > SeriesWriterType;
    SeriesWriterType::Pointer seriesWriter = SeriesWriterType::New();
    seriesWriter->SetInput(castFilter->GetOutput());

    // We now reuse the filename generator in order to produce the list of
    // filenames for the output series. In this case we just need to modify the
    // format of the filename generator. Then, we pass the list of output
    // filenames to the series writer.

    QString Dir_Str = QFileDialog::getExistingDirectory(this, tr("Set Directory"), "");


    nameGenerator->SetStartIndex(0);
    nameGenerator->SetEndIndex(last);
    nameGenerator->SetIncrementIndex(1);

    nameGenerator->SetSeriesFormat(Dir_Str.toStdString()+"//Tracks%04d.tif");
    seriesWriter->SetFileNames(nameGenerator->GetFileNames());

    // Finally we trigger the execution of the series writer from inside a
    // try/catch block.

    try
    {
        seriesWriter->Update();
    }
    catch (itk::ExceptionObject & excp)
    {
        std::cerr << "Error reading the series " << std::endl;
        std::cerr << excp << std::endl;
    }


	
	
	
}



void itkthread::threshold(vtkImageData *inputimage, double lthreshold, double uthreshold)
{
	const   unsigned int        Dimension = 3;
	typedef unsigned char              InputPixelType;

	//typedef float               OutputPixelType;
	typedef itk::Image< InputPixelType, Dimension >   InputImageType;
	//typedef itk::Image< OutputPixelType, Dimension >  OutputImageType;


	typedef itk::VTKImageToImageFilter<InputImageType> VTKImageToImageType;
	VTKImageToImageType::Pointer vtkImageToImageFilter = VTKImageToImageType::New();
	vtkImageToImageFilter->SetInput(inputimage);
	vtkImageToImageFilter->Update();

	//First threshold the volume
	
	typedef itk::ThresholdImageFilter <InputImageType>
		ThresholdImageFilterType;
	ThresholdImageFilterType::Pointer thresholdFilter
		= ThresholdImageFilterType::New();
	thresholdFilter->SetInput(vtkImageToImageFilter->GetOutput());
	thresholdFilter->ThresholdOutside(lthreshold, uthreshold);
	thresholdFilter->SetOutsideValue(0);
	thresholdFilter->Update();


	typedef unsigned char              UnsignedCharPixelType;
	typedef itk::Image<UnsignedCharPixelType, 3>  UnsignedCharImageType;
	threshimg->AllocateScalars(VTK_UNSIGNED_CHAR, inputimage->GetNumberOfPoints());


	QString fileNameSave = QFileDialog::getSaveFileName(this,
		tr("Save Volume"), "",
		tr("TIFF File (*.tif)"));
	string volname = fileNameSave.toStdString();
	if (!volname.empty()){
		//write images to .tif file
		typedef itk::ImageFileWriter< UnsignedCharImageType > WriterType;
		WriterType::Pointer writer = WriterType::New();
		writer->SetInput(thresholdFilter->GetOutput());
		writer->SetFileName(volname.c_str());

		try
		{
			writer->Update();
		}
		catch (itk::ExceptionObject & error)
		{
			std::cerr << "Error: " << error << std::endl;
			return;
		}
	}

}

void itkthread::display(char * imagefilename)
{
	typedef itk::Image<signed short, 2>  ImageType;

	ImageType::Pointer image;
	typedef itk::ImageFileReader<ImageType> ReaderType;
	ReaderType::Pointer reader = ReaderType::New();
	reader->SetFileName(imagefilename);
	image = reader->GetOutput();

	QuickView viewer;
	
	viewer.AddImage(image.GetPointer());
	viewer.Visualize();
	
}


void itkthread::displaytimeseq(char * imagefilename)
{
	vtkSmartPointer<vtkImageViewer2> imageViewer =
		vtkSmartPointer<vtkImageViewer2>::New();
	vtkSmartPointer<vtkTIFFReader> tiffReader =
		vtkSmartPointer<vtkTIFFReader>::New();
	tiffReader->SetFileName(imagefilename);
	tiffReader->Update();
	int dims[3];
	tiffReader->GetOutput()->GetDimensions(dims);
	vtkSmartPointer<vtkImageReslice> imageReslice =
		vtkSmartPointer<vtkImageReslice>::New();
	imageReslice->SetInputData(tiffReader->GetOutput());
	imageReslice->SetOutputExtent(0, dims[0] - 1, 0, dims[1] - 1, 0, 0);
	imageReslice->SetOutputDimensionality(2);
	imageReslice->Update();
	vtkSmartPointer<vtkImageData> DispImage = vtkSmartPointer<vtkImageData>::New();
	DispImage->SetDimensions(dims[0], dims[1], 1);
	DispImage = imageReslice->GetOutput();

	// connect to image viewer pipeline
	imageViewer->SetInputData(DispImage);
	imageViewer->SetColorWindow(tiffReader->GetOutput()->GetScalarTypeMax());
	imageViewer->SetColorLevel(tiffReader->GetOutput()->GetScalarTypeMax() / 2);


// Picker to pick pixels
vtkSmartPointer<vtkPropPicker> propPicker =
vtkSmartPointer<vtkPropPicker>::New();
propPicker->PickFromListOn();

// Give the picker a prop to pick
vtkImageActor* imageActor = imageViewer->GetImageActor();

propPicker->AddPickList(imageActor);

// disable interpolation, so we can see each pixel
imageActor->InterpolateOff();

// Visualize
vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
vtkSmartPointer<vtkRenderWindowInteractor>::New();
imageViewer->SetupInteractor(renderWindowInteractor);
imageViewer->SetSize(600, 400);

vtkRenderer* renderer = imageViewer->GetRenderer();

renderer->ResetCamera();
renderer->SetBackground(0.8, 0.8, 0.8);

renderer->GetRenderWindow()->SetCurrentCursor(VTK_CURSOR_CROSSHAIR);

// Annotate the image with window/level and mouse over pixel
// information
vtkSmartPointer<vtkCornerAnnotation> cornerAnnotation =
vtkSmartPointer<vtkCornerAnnotation>::New();
cornerAnnotation->SetLinearFontScaleFactor(1);
cornerAnnotation->SetNonlinearFontScaleFactor(1);
cornerAnnotation->SetMaximumFontSize(16);
cornerAnnotation->SetText(0, "Off Image");
// cornerAnnotation->SetText(3, "<window>\n<level>");
cornerAnnotation->GetTextProperty()->SetColor(1, 1, 1);
cornerAnnotation->GetTextProperty()->SetFontFamilyToTimes();

imageViewer->GetRenderer()->AddViewProp(cornerAnnotation);

// Callback listens to MouseMoveEvents invoked by the interactor's style
vtkSmartPointer<vtkImageInteractionCallback> callback =
vtkSmartPointer<vtkImageInteractionCallback>::New();
callback->SetViewer(imageViewer);
callback->SetAnnotation(cornerAnnotation);
callback->SetPicker(propPicker);

// InteractorStyleImage allows for the following controls:
// 1) middle mouse + move = camera pan
// 2) left mouse + move = window/level
// 3) right mouse + move = camera zoom
// 4) middle mouse wheel scroll = zoom
// 5) 'r' = reset window/level
// 6) shift + 'r' = reset camera
vtkInteractorStyleImage* imageStyle =
imageViewer->GetInteractorStyle();
imageStyle->AddObserver(vtkCommand::MouseMoveEvent, callback);
// imageStyle->AddObserver(vtkCommand::LeftButtonPressEvent, plot);

renderWindowInteractor->Initialize();
renderWindowInteractor->Start();
}