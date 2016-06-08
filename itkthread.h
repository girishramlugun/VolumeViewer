#pragma once
#include <vtkImageData.h>
#include <QDialog>
#include <itkHessian3DToVesselnessMeasureImageFilter.h>
#include <itkHessianRecursiveGaussianImageFilter.h>
#include <itkImageFileReader.h>
#include <itkImageFileWriter.h>
#include <itkCastImageFilter.h>
#include <itkRescaleIntensityImageFilter.h>
#include <itkThresholdImageFilter.h>
#include <itkVTKImageToImageFilter.h>
#include <itkImageToVTKImageFilter.h>
#include<vtkSmartPointer.h>
#include <itkImage.h>
#include <itkImageSeriesReader.h>
#include <itkImageSeriesWriter.h>
#include <itkNumericSeriesFileNames.h>
#include <itkTIFFImageIO.h>
#include <itkExtractImageFilter.h>
#include<string>


using namespace std;

class itkthread : public QWidget
{

	Q_OBJECT

public:
	itkthread();
    void process(std::string fullprefix,int zlb, int zub, double sigma, double alpha1, double alpha2);

	void threshold(vtkImageData *inputimage, double lthreshold, double uthreshold);
 
	vtkSmartPointer <vtkImageData> threshimg;

	void display(char * imagefilename);

	void itkthread::displaytimeseq(char * imagefilename);
	
signals:



};

