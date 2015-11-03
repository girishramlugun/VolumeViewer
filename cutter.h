#ifndef CUTTER_H
#define CUTTER_H


#include <itkImage.h>
#include <itkImageSeriesReader.h>
#include <itkImageSeriesWriter.h>
#include <itkNumericSeriesFileNames.h>
#include <itkTIFFImageIO.h>
#include <itkExtractImageFilter.h>
#include<string>
#include <QDialog>


class Cutter : public QWidget
{

	Q_OBJECT


public:
	Cutter();
	void Run(std::string,int,int,int,int,int,int,int,int);
};

#endif // CUTTER_H
