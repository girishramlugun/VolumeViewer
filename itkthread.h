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

class itkthread
{
public:
	itkthread();
	void process(vtkImageData *inputimage, double sigma, double alpha1, double alpha2);


 



};

