#include "vtkwidget.h"
#include<vtkMarchingCubes.h>
#include<vtkPolyDataConnectivityFilter.h>
#include<vtkImageResample.h>
#include<vtkTIFFReader.h>
#include<vtk_tiff.h>
#include <math.h> 
#include <vtkGPUInfo.h>
#include <vtkGPUInfoList.h>
#include<vtkStringArray.h>
#include <vtkPointData.h>
#include<vtkImageAccumulate.h>
#include<QVector>
#include<vtkImageMagnitude.h>
#include<math.h>
#include<qprogressdialog.h>
#include<vtkImageAppend.h>
#include<vtkGlyph3DMapper.h>
#include<vtkGlyph3D.h>
#include<vtkArrowSource.h>
#include<vtkScalarBarActor.h>
#include <vtkSmoothPolyDataFilter.h>
#include <vtkTextProperty.h>
#include<vtkImageAppend.h>
#include<vtkBMPReader.h>
#include<vtkAbstractImageInterpolator.h>





vtkwidget::vtkwidget(QWidget *parent) :
    QVTKWidget(parent)
{
    volpropchange = vtkSmartPointer<vtkImageChangeInformation>::New();

    readervti = vtkSmartPointer<vtkXMLImageDataReader>::New();

    readertiff = vtkSmartPointer<vtkTIFFReader> ::New();

    volume = vtkSmartPointer<vtkVolume>::New();

    leftRenderer = vtkSmartPointer<vtkRenderer>::New();

    mapper = vtkSmartPointer<vtkSmartVolumeMapper>::New();

	rcmapper = vtkSmartPointer<vtkGPUVolumeRayCastMapper>::New();
	 
    volumeColor = vtkSmartPointer<vtkColorTransferFunction>::New();

    LightKit = vtkSmartPointer<vtkLightKit> ::New();

    volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New() ;

    volumeScalarOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();

	volumeScalarOpacity1 = vtkSmartPointer<vtkPiecewiseFunction>::New();

	volumeScalarOpacity2 = vtkSmartPointer<vtkPiecewiseFunction>::New();

	volumeScalarOpacity3 = vtkSmartPointer<vtkPiecewiseFunction>::New();

    style = vtkSmartPointer <vtkInteractorStyleTrackballCamera>::New();

	volumeGradientOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();

	poly_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();

	actor = vtkSmartPointer<vtkImageActor>::New();

	imseq = vtkSmartPointer<vtkTIFFReader>::New();

	//imgdata = vtkSmartPointer<vtkImageData>::New();

	dsmapper = vtkSmartPointer<vtkDataSetMapper>::New();

	input = vtkSmartPointer<vtkImageData>::New();

	reader = vtkSmartPointer<vtkAlgorithm>::New();

	widget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();

	

}

void vtkwidget::initialize(vtkImageData *input)
{

	leftRenderer->RemoveAllViewProps();

	//Set default light parameters

	LightKit->SetKeyLightWarmth(0.6); LightKit->SetKeyLightIntensity(0.75); LightKit->SetKeyLightElevation(50); LightKit->SetKeyLightAzimuth(10);
	LightKit->SetFillLightWarmth(0.40); LightKit->SetKeyToFillRatio(3); LightKit->SetFillLightElevation(-75); LightKit->SetFillLightAzimuth(-10);
	LightKit->SetBackLightWarmth(0.5); LightKit->SetKeyToBackRatio(3.5); LightKit->SetBackLightElevation(0); LightKit->SetBackLightAzimuth(110);
	LightKit->SetHeadLightWarmth(0.5); LightKit->SetKeyToHeadRatio(3);


	//Add Volume Gradient Opacity
	//vtkwid->volumeGradientOpacity->AddPoint(0,0);
	//vtkwid->volumeGradientOpacity->AddPoint(100,1);

	// The opacity transfer function is used to control the opacity
	// of different tissue types.



	// The color transfer function maps voxel intensities to colors.
	// It is modality-specific, and often anatomy-specific as well.
	// The goal is to one color for flesh (between 500 and 1000)
	// and another color for bone (1150 and over).





	//Adjust Rotation Style of Camera

	GetInteractor()->SetInteractorStyle(style);

	int ncol = input->GetNumberOfScalarComponents();
	//Set volumeProperty parameters
	if (ncol < 3 )
    {
		volumeColor->AddRGBPoint(0, 0, 0, 0);
		volumeColor->AddRGBPoint(255, 1, 1, 1);

		volumeScalarOpacity->AddPoint(0, 0.00);
		volumeScalarOpacity->AddPoint(255, 1.00);

		volumeProperty->SetColor(volumeColor);
		volumeProperty->SetScalarOpacity(volumeScalarOpacity);
		
	
    }
	
	else if (ncol= 3)

   {
	vtkSmartPointer <vtkColorTransferFunction> c1 = vtkSmartPointer<vtkColorTransferFunction>::New();
	c1->AddRGBPoint(0, 0, 0, 0);
	c1->AddRGBPoint(255, 1, 0, 0);
	vtkSmartPointer <vtkColorTransferFunction> c2 = vtkSmartPointer<vtkColorTransferFunction>::New();

	c2->AddRGBPoint(0, 0, 0, 0);
	c2->AddRGBPoint(255, 0, 1, 0);
	vtkSmartPointer <vtkColorTransferFunction> c3 = vtkSmartPointer<vtkColorTransferFunction>::New();

	c3->AddRGBPoint(0, 0, 0, 0);
	c3->AddRGBPoint(255, 0, 0, 1);


	volumeProperty->SetColor(0,c1);
	volumeProperty->SetColor(1,c2);
	volumeProperty->SetColor(2,c3);


	volumeScalarOpacity1->AddPoint(0, 0.00);
	volumeScalarOpacity1->AddPoint(255, 1.00);
	volumeScalarOpacity2->AddPoint(0, 0.00);
	volumeScalarOpacity2->AddPoint(255, 1.00);
	volumeScalarOpacity3->AddPoint(0, 0.00);
	volumeScalarOpacity3->AddPoint(255, 1.00);
	volumeProperty->SetScalarOpacity(0,volumeScalarOpacity1);
	volumeProperty->SetScalarOpacity(1,volumeScalarOpacity2);
	volumeProperty->SetScalarOpacity(2,volumeScalarOpacity3);

    }

	
	
	
	// volumeProperty->SetGradientOpacity(volumeGradientOpacity);
	//volumeProperty->SetInterpolationType(VTK_NEAREST_INTERPOLATION);
	//volumeProperty->ShadeOff();
	LightKit->AddLightsToRenderer(leftRenderer);
	mapper->SetInputData(input);
	

	input->RemoveAllObservers();

	render();

}

void vtkwidget::render()
{
	
	mapper->SetBlendModeToComposite();
	volumeProperty->SetInterpolationType(VTK_CUBIC_INTERPOLATION);
	//mapper->SetInputConnection(reader->GetOutputPort());

        //mapper->SetRequestedRenderModeToRayCast();
	//if (input->GetActualMemorySize() > 0.8*(mapper->GetMaxMemoryInBytes())/1024)
	//{
	//	mapper->SetRequestedRenderModeToRayCast();
	//}
	mapper->SetMaxMemoryFraction(0.75);

	leftRenderer->ResetCamera();
	//mapper->SetInteractiveUpdateRate(2);
	
	//mapper->SetMaxMemoryFraction(0.5);
	volume->SetMapper(mapper);
	mapper->ReleaseDataFlagOn();
	volume->SetProperty(volumeProperty);
	
	// Add Volume to renderer
	//leftRenderer->SetUseDepthPeeling(1);
	//leftRenderer->SetMaximumNumberOfPeels(100);
	leftRenderer->AddVolume(volume);
	volume->SetOrigin(volume->GetCenter());
	//this->qvtkWidgetLeft->GetRenderWindow()->AddRenderer(leftRenderer);
	//   vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
	//     vtkSmartPointer<vtkRenderWindowInteractor>::New();
	// renderWindowInteractor->SetRenderWindow(qvtkWidgetLeft->GetRenderWindow());
	// VTK/Qt wedded

	
	// Render and interact
	//  vtkwid-> renderWindow->Render();
	// renderer->AutomaticLightCreationOn();
	//   vtkwid-> renderWindow->SetWindowName("Volume Viewer");
	//  vtkwid-> renderWindowInteractor->Start();
	GetRenderWindow()->AddRenderer(leftRenderer);
	this->show();
	// Set up axes widget
	


}


void vtkwidget::renderpoly()
{
	
	// Create a 3D model using marching cubes
	vtkSmartPointer<vtkMarchingCubes> mc =
		vtkSmartPointer<vtkMarchingCubes>::New();
	mc->SetInputConnection(readertiff->GetOutputPort());
	mc->ComputeNormalsOn();
	mc->ComputeGradientsOn();
	mc->SetValue(1, 100);
	
// second value acts as threshold

	// To remain largest region
	vtkSmartPointer<vtkPolyDataConnectivityFilter> confilter =
		vtkSmartPointer<vtkPolyDataConnectivityFilter>::New();
	confilter->SetInputConnection(mc->GetOutputPort());
	//confilter->SetExtractionModeToLargestRegion();
	//confilter->SetExtractionModeToAllRegions();



	//imageDataGeometryFilter->SetInputConnection(input->);
	//imageDataGeometryFilter->SetInputData(readertiff->GetOutput());
	//imageDataGeometryFilter->Update();

	vtkSmartPointer<vtkContourFilter> contour_filter = vtkSmartPointer<vtkContourFilter>::New();
	poly_mapper->SetInputConnection(confilter->GetOutputPort());
	
	//poly_mapper->SetColorModeToMapScalars();
	
	leftRenderer->RemoveAllViewProps();
	volume->Delete();
	vtkSmartPointer<vtkActor> poly_actor =
		vtkSmartPointer<vtkActor>::New();
	
	poly_actor->SetMapper(poly_mapper);
	leftRenderer->AddActor(poly_actor);
	GetRenderWindow()->AddRenderer(leftRenderer);
	GetInteractor()->Render();
	
	
}

void vtkwidget::renderpol(vtkPolyData *pol)
{
	poly_mapper->SetInputData(pol);
	vtkSmartPointer<vtkActor> poly_actor = vtkSmartPointer<vtkActor>::New();
	poly_mapper->SetColorModeToMapScalars();
	poly_actor->SetMapper(poly_mapper);
	poly_actor->GetProperty()->EdgeVisibilityOff();



	vtkSmartPointer<vtkScalarBarActor> scalarBar = vtkSmartPointer<vtkScalarBarActor>::New();

	scalarBar->SetTitle("Inclination angle");
	scalarBar->SetNumberOfLabels(2);
	scalarBar->SetDisplayPosition(0, 0);
	scalarBar->SetHeight(0.0625);
	scalarBar->SetWidth(0.4);
	scalarBar->SetOrientationToHorizontal();


	vtkSmartPointer<vtkLookupTable> hueLut = vtkSmartPointer<vtkLookupTable>::New();
	hueLut->SetTableRange(0, 90);
	hueLut->SetHueRange(0.708333, 0);
	hueLut->SetSaturationRange(1, 1);
	hueLut->SetValueRange(1, 1);
	hueLut->Build();

	scalarBar->SetLookupTable(hueLut);
	poly_mapper->SetColorModeToMapScalars();
	poly_mapper->SetScalarRange(0, 255);
	poly_mapper->ImmediateModeRenderingOn();
	leftRenderer->AddActor(poly_actor);
	leftRenderer->AddActor2D(scalarBar);
	GetRenderWindow()->AddRenderer(leftRenderer);
	GetInteractor()->Render();
	this->show();
	
	
}

void vtkwidget::renderactor(vtkImageData *img)
{
	vtkSmartPointer<vtkGlyph3D> glyph3D =
		vtkSmartPointer<vtkGlyph3D>::New();
	vtkSmartPointer<vtkPolyDataMapper> glyph3DMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	vtkSmartPointer<vtkArrowSource> arrowSource =
		vtkSmartPointer<vtkArrowSource>::New();

	vtkSmartPointer<vtkActor> glyph_actor =
		vtkSmartPointer<vtkActor>::New();
	glyph3D->SetSourceConnection(arrowSource->GetOutputPort());
	glyph3D->SetVectorModeToUseVector();
	glyph3D->SetInputData(img);
	glyph3D->SetScaleFactor(0.1);
	glyph3D->Update();

	glyph3DMapper->SetInputConnection(glyph3D->GetOutputPort());
	glyph_actor->SetMapper(glyph3DMapper);
	leftRenderer->AddActor(glyph_actor);
	GetRenderWindow()->AddRenderer(leftRenderer);
	GetInteractor()->Render();
	this->show();

}

void vtkwidget::setbg(double bg_r, double bg_g, double bg_b)
{
	leftRenderer->SetBackground(bg_r, bg_g, bg_b);
	GetRenderWindow()->Render();
}

void vtkwidget::setvram(int vramVal)
{
	vtkIdType vram = 0.75* vramVal * 1024 * 1024;
	mapper->SetMaxMemoryInBytes(vram);
}

void vtkwidget::setdims(double dim_x,  double dim_y, double dim_z)
{
	volpropchange->SetInputData(mapper->GetInput());
    volpropchange->SetOutputSpacing(dim_x, dim_y, dim_z);
	volpropchange->Update();
	mapper->SetInputData(volpropchange->GetOutput());
	//leftRenderer->ResetCamera();
	//GetRenderWindow()->Render();
	render();
}

void vtkwidget::updatelights(double kw, double ki, double ke, double ka, double fw, double fkf, double fe, double fa, double bw, double bkb, double be, double ba, double hw, double hkh)
{
	LightKit->SetKeyLightWarmth(kw); LightKit->SetKeyLightIntensity(ki); LightKit->SetKeyLightElevation(ke); LightKit->SetKeyLightAzimuth(ka);
	LightKit->SetFillLightWarmth(fw); LightKit->SetKeyToFillRatio(fkf); LightKit->SetFillLightElevation(fe); LightKit->SetFillLightAzimuth(fa);
	LightKit->SetBackLightWarmth(bw); LightKit->SetKeyToBackRatio(bkb); LightKit->SetBackLightElevation(be); LightKit->SetBackLightAzimuth(ba);
	LightKit->SetHeadLightWarmth(hw); LightKit->SetKeyToHeadRatio(hkh);
	LightKit->AddLightsToRenderer(leftRenderer);
	GetInteractor()->Render();
}

void vtkwidget::updatevolcol(double vc)
{

	mapper->SetFinalColorLevel(vc);
	GetInteractor()->Render();

}


void vtkwidget::updatewincol(double wcol)
{
	mapper->SetFinalColorWindow(wcol);
	GetInteractor()->Render();
}


void vtkwidget::readvti(string inputFilename)
{
	vtkXMLImageDataReader *rvti = vtkXMLImageDataReader::New();
	rvti->SetFileName(inputFilename.c_str());
	rvti->Update();
	resample(rvti->GetOutput());
	rvti->Delete();
	
}

void vtkwidget::readtif(string inputFilename)
{
	//vtkTIFFReader *rtiff = vtkTIFFReader::New();
	readertiff->SetFileName(inputFilename.c_str());
	readertiff->SetOrientationType(ORIENTATION_LEFTTOP);
	readertiff->Update();
	resample(readertiff->GetOutput());
	//rtiff->Delete();

}

void vtkwidget::resample(vtkImageData *imgdata)
{
	
	
	//Get the Graphics memory and find a scaling factor to match that, otherwise, render the imagedata without scaling
	vtkIdType memsize = imgdata->GetActualMemorySize()*1024;
	double sf =ceil(memsize / mapper->GetMaxMemoryInBytes());

    if (sf>=1 && sf<8){
		sample_rate = 0.5;
	vtkSmartPointer <vtkImageResample> imgrs =vtkSmartPointer <vtkImageResample>::New();
	imgrs->SetInputData(imgdata);
	imgrs->SetInterpolationModeToNearestNeighbor();
	imgrs->SetAxisMagnificationFactor(0, sample_rate);
	imgrs->SetAxisMagnificationFactor(1, sample_rate);
	imgrs->SetAxisMagnificationFactor(2, sample_rate);
	imgrs->Update();
	buildhist(imgrs->GetOutput());
	initialize(imgrs->GetOutput());
	}
    else if (sf >= 8 && sf < 16)

	{
		sample_rate = 0.25;
	vtkSmartPointer <vtkImageResample> imgrs = vtkSmartPointer <vtkImageResample>::New();
	imgrs->SetInputData(imgdata);
	imgrs->SetInterpolationModeToNearestNeighbor();
	imgrs->SetAxisMagnificationFactor(0, sample_rate);
	imgrs->SetAxisMagnificationFactor(1, sample_rate);
	imgrs->SetAxisMagnificationFactor(2, sample_rate);
	imgrs->Update();
	buildhist(imgrs->GetOutput());
	initialize(imgrs->GetOutput());
	}
    else if (sf >= 16 && sf < 24)

	{
		sample_rate = 0.125;
	vtkSmartPointer <vtkImageResample> imgrs = vtkSmartPointer <vtkImageResample>::New();
	imgrs->SetInputData(imgdata);
	imgrs->SetInterpolationModeToNearestNeighbor();
	imgrs->SetAxisMagnificationFactor(0, sample_rate);
	imgrs->SetAxisMagnificationFactor(1, sample_rate);
	imgrs->SetAxisMagnificationFactor(2, sample_rate);
	imgrs->Update();
	buildhist(imgrs->GetOutput());
	initialize(imgrs->GetOutput());
	}
	else if (sf<1)
	{
		sample_rate = 1;
	buildhist(imgdata);
	initialize(imgdata);
	}

}

void vtkwidget::readimseq(vtkStringArray *filenames, int N)
{


	vtkSmartPointer<vtkTIFFReader>readimg = vtkSmartPointer<vtkTIFFReader>::New();
	readimg->SetFileName(filenames->GetValue(0));

	readimg->Update();
	int cols = readimg->GetOutput()->GetNumberOfScalarComponents();
	int dims[3]; 
	readimg->GetOutput()->GetDimensions(dims);
	dims[2] = N;
	double size = (double(dims[0]) * double(dims[1]) * double(dims[2])* double(cols)) / (1024*1024*1024);
	double sf = size / 0.75;
	cout << sf;
	vtkSmartPointer<vtkImageAppend> appendmag = vtkSmartPointer<vtkImageAppend>::New();

	
	int mf; double f;
	
	appendmag->SetAppendAxis(2);
	if (sf >= 1 && sf < 8){ mf = 2; f = 0.5; }
	else if (sf >= 8 && sf< 64){ mf = 4; f = 0.25; }
	else if (sf < 1){ mf = 1; f = 1; }
	
		int m = 0;
		int num = ceil(N / mf) - 1;
		QProgressDialog progress("Loading files...", "Abort", 0, num, this);
		progress.setWindowModality(Qt::WindowModal);

		

		//imgrs->Update();
		//imgrs->ReleaseDataFlagOn();



		

		for (int i = 0; i < num; i++)
		{

			progress.setValue(i);
			if (progress.wasCanceled())
			{
				return;
				this->deleteLater();
			}
			//	vtkSmartPointer<vtkTIFFReader>readimg1 = vtkSmartPointer<vtkTIFFReader>::New();

			vtkSmartPointer<vtkTIFFReader>readimg0 = vtkSmartPointer<vtkTIFFReader>::New();
			vtkSmartPointer<vtkImageAppend> append = vtkSmartPointer<vtkImageAppend>::New();
			append->SetAppendAxis(2);
						
			for (int sc = 0; sc < mf; sc++)
			{

				readimg0->SetFileName(filenames->GetValue(mf*i + sc));
				readimg0->Update();
				append->AddInputConnection(readimg0->GetOutputPort());
				append->Update();


			}

			m++;

			vtkSmartPointer <vtkImageResample> imgrs = vtkSmartPointer <vtkImageResample>::New();
			imgrs->SetInterpolationModeToCubic();
			imgrs->SetAxisMagnificationFactor(0, f);
			imgrs->SetAxisMagnificationFactor(1, f);
			imgrs->SetAxisMagnificationFactor(2, f);
			imgrs->SetInputConnection(append->GetOutputPort());
			imgrs->Update();
			
			
			
			appendmag->AddInputData(imgrs->GetOutput());

			


		}

		progress.setValue(num);


		appendmag->Update();
		
		//buildhist(appendmag->GetOutput());
	//	vtkSmartPointer <vtkImageData>  imser = vtkSmartPointer <vtkImageData> ::New();
		//	imser->AllocateScalars(VTK_INT, cols);
		//	imser->SetDimensions(appendmag->GetOutput()->GetDimensions());
			//imser->SetDimensions(dims[0]/2,dims[1]/2,N/2);
			//imser->GetPointData()->SetScalars(appendmag->GetOutput()->GetPointData()->GetScalars());
		//	imser = appendmag->GetOutput();
		//initialize(appendmag->GetOutput());
			initialize(appendmag->GetOutput());


		//appendmag->Delete();
		//
		/*
		vtkTIFFReader *imgseq = vtkTIFFReader::New();
		imgseq->SetFileNames(filenames);
		imgseq->Update();


		vtkImageData *imse = vtkImageData::New();
		imse->AllocateScalars(VTK_INT, cols);
		imse->SetDimensions(dims);
		imse->GetPointData()->SetScalars(imgseq->GetOutput()->GetPointData()->GetScalars());

		resample(imse);
		//renderactor(imse);

		imgseq->Delete();

		imse->Delete();


		*/
	
}

void vtkwidget::buildhist(vtkImageData* imgdata)
{
	vtkSmartPointer<vtkImageAccumulate> histogram =
		vtkSmartPointer<vtkImageAccumulate>::New();
	histogram->SetInputData(imgdata);
	histogram->SetComponentExtent(0, 255, 0, 0, 0, 0);
	histogram->SetComponentOrigin(0, 0, 0);
	histogram->SetComponentSpacing(1, 0, 0);
	histogram->IgnoreZeroOn();
	histogram->Update();
	QVector<double> freq(256);
	int* output = static_cast<int*>(histogram->GetOutput()->GetScalarPointer());
	
	for (int j = 0; j < 256; ++j)
	{

		freq[j] = *output++;
				
	}
	freq[0] = 0;
	
	emit sendhist(freq);
}

