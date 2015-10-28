#include "cutter.h"
#include<string>
#include <QFileDialog>
#include<qstring.h>



Cutter::Cutter()
{

}


void Cutter::Run(std::string fullprefix, int zlb, int zub, int x, int x1, int y, int y1, int z, int z1)
{

	// Software Guide : BeginLatex
	//
	// The \doxygen{RGBPixel} class is templated over the type used to
	// represent each one of the Red, Green and Blue components. A typical
	// instantiation of the RGB image class might be as follows.
	//
	//  \index{itk::RGBPixel!Instantiation}
	//
	// Software Guide : EndLatex
	// Software Guide : BeginCodeSnippet
	typedef unsigned char PixelType;
	const unsigned int Dimension = 3;
	typedef itk::Image< PixelType, Dimension >    ImageType;
	// Software Guide : EndCodeSnippet
	// Software Guide : BeginLatex
	//
	// The image type is used as a template parameter to instantiate
	// the series reader and the volumetric writer.
	//
	// \index{itk::ImageSeriesReader!RGB Image}
	// \index{itk::ImageFileWriter!RGB Image}
	//
	// Software Guide : EndLatex
	// Software Guide : BeginCodeSnippet
	typedef itk::ImageSeriesReader< ImageType >  SeriesReaderType;
	//typedef itk::ImageFileWriter<   ImageType >  WriterType;
	SeriesReaderType::Pointer seriesReader = SeriesReaderType::New();
	//WriterType::Pointer       writer = WriterType::New();
	// Software Guide : EndCodeSnippet
	const unsigned int first = zlb;
	const unsigned int last = zub;
	//const char * outputFilename = argv[3];
	// Software Guide : BeginLatex
	//
	// We use a NumericSeriesFileNames class in order to generate the filenames of
	// the slices to be read. Later on in this example we will reuse this object in
	// order to generate the filenames of the slices to be written.
	//
	// Software Guide : EndLatex
	// Software Guide : BeginCodeSnippet
	typedef itk::NumericSeriesFileNames    NameGeneratorType;
	NameGeneratorType::Pointer nameGenerator = NameGeneratorType::New();
	nameGenerator->SetStartIndex(first);
	nameGenerator->SetEndIndex(last);
	nameGenerator->SetIncrementIndex(1);
	
	nameGenerator->SetSeriesFormat(fullprefix);
	// Software Guide : EndCodeSnippet
	//  Software Guide : BeginLatex
	//
	//  The ImageIO object that actually performs the read process
	//  is now connected to the ImageSeriesReader.
	//

	seriesReader->SetImageIO(itk::TIFFImageIO::New());


	//  The filenames of the input slices are taken from the names generator and
	//  passed to the series reader.
	//
	
	seriesReader->SetFileNames(nameGenerator->GetFileNames());


	// The name of the volumetric output image is passed to the image writer, and
	// we connect the output of the series reader to the input of the volumetric
	// writer.

	//Filter

	itk::Index<3> processIndex;
	processIndex[0] = x;
	processIndex[1] = y;
	processIndex[2] = z;

	int maxbound[3];
	maxbound[0] = x1;
	maxbound[1] = y1;
	maxbound[2] = z1;

	itk::Size<3> processSize;
	processSize[0] = maxbound[0] - processIndex[0];
	processSize[1] = maxbound[1] - processIndex[1];
	processSize[2] = maxbound[2] - processIndex[2];


	itk::ImageRegion<3> cropregion(processIndex, processSize);



	typedef itk::ExtractImageFilter< ImageType, ImageType > FilterType;
	FilterType::Pointer cropfilter = FilterType::New();
	cropfilter->SetExtractionRegion(cropregion);
	cropfilter->SetInput(seriesReader->GetOutput());
	cropfilter->Update();

	// writer->SetFileName( outputFilename );
	// writer->SetInput( cropfilter->GetOutput() );

	//  Finally, execution of the pipeline can be triggered by invoking the
	//  \code{Update()} method in the volumetric writer. This, of course, is done
	//  from inside a try/catch block.

	//try
	//{
		//writer->Update();
	//}
	//catch (itk::ExceptionObject & excp)
	//{
		//std::cerr << "Error reading the series " << std::endl;
		//std::cerr << excp << std::endl;
	//}

	// We now proceed to save the same volumetric dataset as a set of slices. This
	// is done only to illustrate the process for saving a volume as a series of 2D
	// individual datasets. The type of the series writer must be instantiated
	// taking into account that the input file is a 3D volume and the output files
	// are 2D images.  Additionally, the output of the series reader is connected
	// as input to the series writer.

	typedef itk::Image< PixelType, 2 >     Image2DType;
	typedef itk::ImageSeriesWriter< ImageType, Image2DType > SeriesWriterType;
	SeriesWriterType::Pointer seriesWriter = SeriesWriterType::New();
	seriesWriter->SetInput(cropfilter->GetOutput());

	// We now reuse the filename generator in order to produce the list of
	// filenames for the output series. In this case we just need to modify the
	// format of the filename generator. Then, we pass the list of output
	// filenames to the series writer.

	nameGenerator->SetStartIndex(0);
	nameGenerator->SetEndIndex(processSize[2] - 1);
	nameGenerator->SetIncrementIndex(1);
	nameGenerator->SetSeriesFormat("P:\\Segmented\\Rabbit\\RabbitSeg%04d.tif");
	seriesWriter->SetFileNames(nameGenerator->GetFileNames());

	// Finally we trigger the execution of the series writer from inside a
	// try/catch block.

	try
	{
		seriesWriter->Update();
	}
	catch (itk::ExceptionObject & excp)
	{
		std::cerr << "Error reading the series " << std::endl;
		std::cerr << excp << std::endl;
	}


}


