#ifndef VTKWIDGET_H
#define VTKWIDGET_H

#include <QVTKWidget.h>
#include<QtCore>
#include <vtkPolyDataMapper.h>
#include <vtkQtTableView.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkPlanes.h>
#include<vtkPlane.h>
#include <vtkBoxWidget.h>
#include <vtkRenderer.h>
#include <vtkActor.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkGPUVolumeRayCastMapper.h>
#include <vtkXMLImageDataReader.h>
#include <vtkDataSetMapper.h>
#include <vtkVolume.h>
#include <vtkVolumeProperty.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include<vtkBoxWidget.h>
#include <vtkCommand.h>
#include <qfiledialog.h>
#include <qstring.h>
#include<vtkStructuredPointsReader.h>
#include<vtkImageDataGeometryFilter.h>
#include<vtkGPUVolumeRayCastMapper.h>
#include<vtkSmartVolumeMapper.h>
#include <vtkVolumeTextureMapper3D.h>
#include <vtkLightKit.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkInteractorStyleImage.h>
#include <vtkTIFFReader.h>
#include <QLabel>
#include <vtkWindowToImageFilter.h>
#include <vtkPNGWriter.h>
#include <vtkImageChangeInformation.h>
#include <QMessageBox>
#include <vtkImageResliceMapper.h>
#include <vtkImageProperty.h>
#include <vtkImageSlice.h>
#include<vtkCamera.h>
#include<vtkScalarsToColors.h>
#include <vtkCallbackCommand.h>
#include <vtkPolyDataMapper.h>
#include<vtkContourFilter.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataNormals.h>
#include <QMainWindow>
#include<vtkImageDataGeometryFilter.h>
#include<vtkActor.h>
#include <vtkProperty.h>
#include<vtkLookupTable.h>
#include<vtkImageMapToColors.h>
#include<vtkImageActor.h>
#include<vtkImageReader.h>
#include<vtkImageData.h>
#include<vtkAlgorithm.h>
#include<vtkMatlabMexAdapter.h>


using namespace std;

class vtkwidget : public QVTKWidget
{
    Q_OBJECT
public:

	void initialize();

	
	void render();

	void renderpoly();

    explicit vtkwidget(QWidget *parent = 0);

	void renderactor();
    
	vtkSmartPointer<vtkImageChangeInformation> volpropchange;

    vtkSmartPointer<vtkXMLImageDataReader> readervti ;

    vtkSmartPointer<vtkTIFFReader> readertiff ;

    vtkSmartPointer<vtkVolume> volume;

    vtkSmartPointer<vtkRenderer> leftRenderer;

    vtkSmartPointer<vtkSmartVolumeMapper> mapper;

    vtkSmartPointer<vtkColorTransferFunction> volumeColor ;

    vtkSmartPointer<vtkLightKit> LightKit;

    vtkSmartPointer<vtkVolumeProperty> volumeProperty;

    vtkSmartPointer<vtkPiecewiseFunction> volumeScalarOpacity;

   vtkSmartPointer<vtkInteractorStyleTrackballCamera> style;

   vtkSmartPointer<vtkPiecewiseFunction> volumeGradientOpacity;

   vtkSmartPointer<vtkCallbackCommand> progressCallback;

   vtkSmartPointer<vtkPolyDataMapper> poly_mapper;

   vtkSmartPointer<vtkGPUVolumeRayCastMapper> rcmapper;

   vtkSmartPointer<vtkImageActor> actor;

   vtkSmartPointer<vtkTIFFReader>imseq;

   vtkSmartPointer<vtkImageData>imgdata;

   vtkSmartPointer<vtkDataSetMapper>dsmapper;
   
   vtkSmartPointer<vtkImageData> input;

   vtkSmartPointer<vtkAlgorithm> reader;

   


signals:

   public slots :
	   
   void setbg(double, double, double);
   void setdims(double, double, double);
   void updatelights(double, double, double, double, double, double, double, double, double, double, double, double, double, double);
   void updatevolcol(double);
   void updatewincol(double);

	   

};

#endif // VTKWIDGET_H
