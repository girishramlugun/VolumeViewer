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





itkthread::itkthread()
{
	threshimg = vtkSmartPointer <vtkImageData>::New();
}


void itkthread::process(vtkImageData *inputimage, double sigma, double alpha1, double alpha2)
{
	const   unsigned int        Dimension = 3;
	typedef unsigned char              InputPixelType;
	
	typedef float               OutputPixelType;
	typedef itk::Image< InputPixelType, Dimension >   InputImageType;
	typedef itk::Image< OutputPixelType, Dimension >  OutputImageType;

	
	typedef itk::VTKImageToImageFilter<InputImageType> VTKImageToImageType;
	VTKImageToImageType::Pointer vtkImageToImageFilter = VTKImageToImageType::New();
	vtkImageToImageFilter->SetInput(inputimage);
	vtkImageToImageFilter->Update();
	
	/*
	typedef itk::ImageFileReader< InputImageType >  ReaderType;
	ReaderType::Pointer reader = ReaderType::New();
	reader->SetFileName("LAABlock.tif");
	*/
	

	//First threshold the volume
	double lowerThreshold = 20;
	typedef itk::ThresholdImageFilter <InputImageType>
		ThresholdImageFilterType;
	ThresholdImageFilterType::Pointer thresholdFilter
		= ThresholdImageFilterType::New();
	thresholdFilter->SetInput(vtkImageToImageFilter->GetOutput());
	thresholdFilter->ThresholdBelow(lowerThreshold);
	thresholdFilter->SetOutsideValue(0);

	//Compute Hessian
	typedef itk::HessianRecursiveGaussianImageFilter< InputImageType >
		HessianFilterType;
	HessianFilterType::Pointer hessianFilter = HessianFilterType::New();
	hessianFilter->SetInput(thresholdFilter->GetOutput());
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
	
	//write images to .tif file
	typedef itk::ImageFileWriter< UnsignedCharImageType > WriterType;
	WriterType::Pointer writer = WriterType::New();
	writer->SetInput(castFilter->GetOutput());
	writer->SetFileName("Seg.tif");

	try
	{
		writer->Update();
	}
	catch (itk::ExceptionObject & error)
	{
		std::cerr << "Error: " << error << std::endl;
		return ;
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

	/*
	typedef itk::ImageFileReader< InputImageType >  ReaderType;
	ReaderType::Pointer reader = ReaderType::New();
	reader->SetFileName("LAABlock.tif");
	*/


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


	/*
	//write images to .tif file
	typedef itk::ImageFileWriter< UnsignedCharImageType > WriterType;
	WriterType::Pointer writer = WriterType::New();
	writer->SetInput(thresholdFilter->GetOutput());
	writer->SetFileName("Threshold.tif");

	try
	{
		writer->Update();
	}
	catch (itk::ExceptionObject & error)
	{
		std::cerr << "Error: " << error << std::endl;
		return;
	}
	*/

	typedef itk::Image<UnsignedCharPixelType, 3> ImageType;
	typedef itk::ImageToVTKImageFilter<ImageType>       ConnectorType;

	ConnectorType::Pointer connector = ConnectorType::New();
	connector->SetInput(thresholdFilter->GetOutput());
	connector->Update();
	threshimg = connector->GetOutput();

}