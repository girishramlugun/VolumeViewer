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

class itkthread : public QWidget
{

	Q_OBJECT

public:
	itkthread();
	void process(vtkImageData *inputimage, double sigma, double alpha1, double alpha2);

	void threshold(vtkImageData *inputimage, double lthreshold, double uthreshold);
 
	vtkSmartPointer <vtkImageData> threshimg;
	
signals:



};

