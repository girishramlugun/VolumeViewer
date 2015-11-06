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

using namespace std;

itkthread::itkthread()
{
	threshimg = vtkSmartPointer <vtkImageData>::New();
}


void itkthread::process(std::string fullprefix,int zlb, int zub, double sigma, double alpha1, double alpha2)
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
