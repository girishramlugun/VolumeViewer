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

	volumeColor->AddRGBPoint(0, 0, 0, 0);
	volumeColor->AddRGBPoint(255, 1, 1,1);



	//Adjust Rotation Style of Camera

	GetInteractor()->SetInteractorStyle(style);

	
	//Set volumeProperty parameters
	if (input->GetNumberOfScalarComponents() < 3)
    {
		volumeScalarOpacity->AddPoint(0, 0.00);
		volumeScalarOpacity->AddPoint(255, 1.00);

		volumeProperty->SetColor(volumeColor);
		volumeProperty->SetScalarOpacity(volumeScalarOpacity);
	
    }
      else

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



	render();

}

void vtkwidget::render()
{
	
	mapper->SetBlendModeToComposite();
	//mapper->SetInputConnection(reader->GetOutputPort());

		//mapper->SetRequestedRenderModeToRayCast();
	//if (input->GetActualMemorySize() > 0.8*(mapper->GetMaxMemoryInBytes())/1024)
	//{
	//	mapper->SetRequestedRenderModeToRayCast();
	//}
	

	leftRenderer->ResetCamera();
	//rcmapper->SetInteractiveUpdateRate(2);
	
	//mapper->SetMaxMemoryFraction(0.5);
	volume->SetMapper(mapper);
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

void vtkwidget::renderactor()
{
	

}

void vtkwidget::setbg(double bg_r, double bg_g, double bg_b)
{
	leftRenderer->SetBackground(bg_r, bg_g, bg_b);
	GetRenderWindow()->Render();
}

void vtkwidget::setdims(double dim_x,  double dim_y, double dim_z)
{
	volpropchange->SetInputData(input);
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
	resample(rvti->GetOutput(),1);
	rvti->Delete();
	
}

void vtkwidget::readtif(string inputFilename)
{
	vtkTIFFReader *rtiff = vtkTIFFReader::New();
	rtiff->SetFileName(inputFilename.c_str());
	rtiff->SetOrientationType(ORIENTATION_LEFTTOP);
	rtiff->Update();
	
	
	resample(rtiff->GetOutput(),1);
	rtiff->Delete();

}

void vtkwidget::resample(vtkImageData *imgdata, int sf)
{
	/*
	//Get the Graphics memory and find a scaling factor to match that, otherwise, render the imagedata without scaling
	double memsize = imgdata->GetActualMemorySize();
	vtkGPUInfo *gpi = vtkGPUInfo::New();
	long vram = gpi->GetDedicatedVideoMemory();
	if (vram = 134217728){
	mapper->SetMaxMemoryInBytes(805306368);
}
	//double gpumem = mapper->GetMaxMemoryInBytes();
	double sf =ceil(memsize / mapper->GetMaxMemoryInBytes());
	
	if (sf>=1 && sf<2){

	vtkSmartPointer <vtkImageResample> imgrs =vtkSmartPointer <vtkImageResample>::New();
	imgrs->SetInputData(imgdata);
	imgrs->SetInterpolationModeToNearestNeighbor();
	imgrs->SetAxisMagnificationFactor(0, 0.5);
	imgrs->SetAxisMagnificationFactor(1, 0.5);
	imgrs->SetAxisMagnificationFactor(2, 0.5);
	imgrs->Update();
	buildhist(imgrs->GetOutput());
	initialize(imgrs->GetOutput());
	}
	else if (sf >= 2 && sf < 4)

	{
		vtkSmartPointer <vtkImageResample> imgrs = vtkSmartPointer <vtkImageResample>::New();
		imgrs->SetInputData(imgdata);
		imgrs->SetInterpolationModeToNearestNeighbor();
		imgrs->SetAxisMagnificationFactor(0, 0.25);
		imgrs->SetAxisMagnificationFactor(1, 0.25);
		imgrs->SetAxisMagnificationFactor(2, 0.25);
		imgrs->Update();
		buildhist(imgrs->GetOutput());
		initialize(imgrs->GetOutput());
	}
	else if (sf >= 4 && sf < 8)

	{
		vtkSmartPointer <vtkImageResample> imgrs = vtkSmartPointer <vtkImageResample>::New();
		imgrs->SetInputData(imgdata);
		imgrs->SetInterpolationModeToNearestNeighbor();
		imgrs->SetAxisMagnificationFactor(0, 0.125);
		imgrs->SetAxisMagnificationFactor(1, 0.125);
		imgrs->SetAxisMagnificationFactor(2, 0.125);
		imgrs->Update();
		buildhist(imgrs->GetOutput());
		initialize(imgrs->GetOutput());
	}
	else if (sf<1)
	{
	*/
	//vtkSmartPointer <vtkImageResample> imgrs = vtkSmartPointer <vtkImageResample>::New();
	//imgrs->SetInputData(imgdata);
	//imgrs->SetInterpolationModeToNearestNeighbor();
	//imgrs->SetAxisMagnificationFactor(0, sf);
	//imgrs->SetAxisMagnificationFactor(1, sf);
	//imgrs->SetAxisMagnificationFactor(2, sf);
		buildhist(imgdata);
		initialize(imgdata);
	//}
	



}

void vtkwidget::readimseq(vtkStringArray *filenames, int N)
{

	vtkSmartPointer<vtkTIFFReader>readimg = vtkSmartPointer<vtkTIFFReader>::New();
	readimg->SetFileName(filenames->GetValue(0));

	readimg->Update();
	int dims[3]; 
	readimg->GetOutput()->GetDimensions(dims);
	dims[2] = N;
	
	int cols = readimg->GetOutput()->GetNumberOfScalarComponents();
	
	vtkTIFFReader *imgseq = vtkTIFFReader::New();
	imgseq->SetFileNames(filenames);
	imgseq->Update();
	
	
	vtkImageData *imse = vtkImageData::New();
	imse->AllocateScalars(VTK_INT, cols);
	imse->SetDimensions(dims);
	imse->GetPointData()->SetScalars(imgseq->GetOutput()->GetPointData()->GetScalars());

	resample(imse,1);

	imgseq->Delete();

	imse->Delete();
	
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