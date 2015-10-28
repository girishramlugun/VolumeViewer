#ifndef CUTTER_H
#define CUTTER_H


#include <itkImage.h>
#include <itkImageSeriesReader.h>
#include <itkImageSeriesWriter.h>
#include <itkNumericSeriesFileNames.h>
#include <itkTIFFImageIO.h>
#include <itkExtractImageFilter.h>


class Cutter
{
public:
	Cutter();
	void Run(int,int,int,int,int,int,int,int);
};

#endif // CUTTER_H
