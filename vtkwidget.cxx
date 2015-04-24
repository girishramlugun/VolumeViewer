#include "vtkwidget.h"




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

    style = vtkSmartPointer <vtkInteractorStyleTrackballCamera>::New();

	volumeGradientOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();

	poly_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();

	actor = vtkSmartPointer<vtkImageActor>::New();

	imseq = vtkSmartPointer<vtkTIFFReader>::New();

	imgdata = vtkSmartPointer<vtkImageData>::New();

	dsmapper = vtkSmartPointer<vtkDataSetMapper>::New();

	

}

void vtkwidget::initialize()
{
	//Set default light parameters
	
	LightKit->SetKeyLightWarmth(0.6);LightKit->SetKeyLightIntensity(0.75); LightKit->SetKeyLightElevation(50); LightKit->SetKeyLightAzimuth(10);
	LightKit->SetFillLightWarmth(0.40); LightKit->SetKeyToFillRatio(3); LightKit->SetFillLightElevation(-75); LightKit->SetFillLightAzimuth(-10);
	LightKit->SetBackLightWarmth(0.5); LightKit->SetKeyToBackRatio(3.5); LightKit->SetBackLightElevation(0); LightKit->SetBackLightAzimuth(110);
	LightKit->SetHeadLightWarmth(0.5); LightKit->SetKeyToHeadRatio(3);
	
	
	//Add Volume Gradient Opacity
	//vtkwid->volumeGradientOpacity->AddPoint(0,0);
	//vtkwid->volumeGradientOpacity->AddPoint(100,1);

	// The opacity transfer function is used to control the opacity
	// of different tissue types.

	volumeScalarOpacity->AddPoint(0, 0.00);
	volumeScalarOpacity->AddPoint(255, 1.00);

	// The color transfer function maps voxel intensities to colors.
	// It is modality-specific, and often anatomy-specific as well.
	// The goal is to one color for flesh (between 500 and 1000)
	// and another color for bone (1150 and over).

	volumeColor->AddRGBPoint(0, 0, 0, 0);
	volumeColor->AddRGBPoint(255, 1, 1, 1);

	//Adjust Rotation Style of Camera
	
	GetInteractor()->SetInteractorStyle(style);

	
	//Set volumeProperty parameters
	volumeProperty->SetColor(volumeColor);
	volumeProperty->SetScalarOpacity(volumeScalarOpacity);
	
	// volumeProperty->SetGradientOpacity(volumeGradientOpacity);
	//volumeProperty->SetInterpolationType(VTK_NEAREST_INTERPOLATION);
	//volumeProperty->ShadeOff();

	render();

}

void vtkwidget::render()
{
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

	LightKit->AddLightsToRenderer(leftRenderer);
	// Render and interact
	//  vtkwid-> renderWindow->Render();
	// renderer->AutomaticLightCreationOn();
	//   vtkwid-> renderWindow->SetWindowName("Volume Viewer");
	//  vtkwid-> renderWindowInteractor->Start();
	GetRenderWindow()->AddRenderer(leftRenderer);
	this->show();
}


void vtkwidget::renderpoly()
{
	vtkSmartPointer<vtkImageDataGeometryFilter> imageDataGeometryFilter =
		vtkSmartPointer<vtkImageDataGeometryFilter>::New();
	



	imageDataGeometryFilter->SetInputConnection(readertiff->GetOutputPort());
	//imageDataGeometryFilter->SetInputData(readertiff->GetOutput());
	imageDataGeometryFilter->Update();

	vtkSmartPointer<vtkContourFilter> contour_filter = vtkSmartPointer<vtkContourFilter>::New();
	contour_filter->SetInputData(imageDataGeometryFilter->GetOutput());
	contour_filter->GenerateValues(10, 0, 255);
	poly_mapper->SetInputData(contour_filter->GetOutput());
	
	//poly_mapper->SetColorModeToMapScalars();
	
	leftRenderer->RemoveAllViewProps();
	volume->Delete();
	vtkSmartPointer<vtkActor> poly_actor =
		vtkSmartPointer<vtkActor>::New();
	
	
	
	poly_actor->GetProperty()->SetColor(100, 10, 100);
	poly_actor->GetProperty()->SetOpacity(1);
	poly_actor->SetMapper(poly_mapper);
	LightKit->AddLightsToRenderer(leftRenderer);
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
	volpropchange->SetInputData(readertiff->GetOutput());
    volpropchange->SetOutputSpacing(dim_x, dim_y, dim_z);
	volpropchange->Update();
	mapper->SetInputData(volpropchange->GetOutput());
	//render();
	leftRenderer->ResetCamera();
	GetRenderWindow()->Render();
		
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


