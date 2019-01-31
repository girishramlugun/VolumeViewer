#include "VolumeViewer.h"
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkPlanes.h>
#include <vtkPlane.h>
#include <vtkBoxWidget2.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkXMLImageDataReader.h>
#include <vtkDataSetMapper.h>
#include <vtkVolume.h>
#include <vtkVolumeProperty.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkCommand.h>
#include <qfiledialog.h>
#include <qstring.h>
#include <vtkImageDataGeometryFilter.h>
#include <vtkGPUVolumeRayCastMapper.h>
#include <vtkSmartVolumeMapper.h>
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
#include<QTimer>
#include <qprogressdialog.h>
#include<vtkCallbackCommand.h>
#include<vtkTIFFWriter.h>
#include<vtkDirectory.h>
#include<vtkArray.h>
#include<vtkStringArray.h>
#include<vtkImageReader2.h>
#include<vtkIdTypeArray.h>
#include<vtkImageActor.h>
#include<vtkImageReader.h>
#include<vtkUnsignedShortArray.h>
#include<vtkDataArray.h>
#include<vtkImageData.h>
#include <vtkPointData.h>
#include <vtkClipVolume.h>
#include <vtkDataSetMapper.h>
#include<vtkDoubleArray.h>
#include<vtkTypedArray.h>
#include<vtkArrayIterator.h>
#include<vtkUnsignedShortArray.h>
#include<QStringList>
#include<vtkXMLImageDataReader.h>
#include<vtkXMLImageDataWriter.h>
#include <cstdio>
#include <ctime>
#include<vtkDenseArray.h>
#include<vtkDataArrayIteratorMacro.h>
#include <vtkImplicitPlaneWidget.h>
#include<vtkOrientationMarkerWidget.h>
#include<vtkAxesActor.h>
#include<vtk_tiff.h>
#include<vtk_hdf5.h>
#include<vtkArrayIteratorIncludes.h>
#include<vtkBMPReader.h>
#include<vtkDenseArray.h>
#include<vtkImageResample.h>
#include <vtkGPUInfo.h>
#include <vtkGPUInfoList.h>
#include <QInputDialog>
#include<vtkExtractVOI.h>
#include<qtablewidget.h>
#include<vtkArrowSource.h>
#include <vtkGlyph3D.h>
#include <vtkGlyph3DMapper.h>
#include <vtkTIFFWriter.h>
#include<vtkBoxRepresentation.h>
#include<vtkPoints.h>
#include<vtkVariant.h>
#include<vtkCellArray.h>
#include<vtkVariantExtract.h>
#include<vtkPolyLine.h>
#include<vtkCellData.h>
#include <vtkXMLPolyDataWriter.h>
#include<vtkXMLPolyDataReader.h>
#include<vtkLine.h>
#include<vtkParametricSpline.h>
#include<vtkParametricFunctionSource.h>
#include<QDesktopServices>
#include <vtkThreshold.h>
#include <QSettings>
#include<vtkImageReslice.h>
#include<vtkAbstractTransform.h>
#include<vtkMatrix4x4.h>
#include<vtkMatrixToLinearTransform.h>
#include<vtkTypeInt16Array.h>
#include <vtkImageChangeInformation.h>
#include<vtkTransform.h>
#include<vtkTransformFilter.h>
#include<vtkXMLUnstructuredGridWriter.h>
#include<vtkUnstructuredGrid.h>
#include<vtkTransformPolyDataFilter.h>
#include<vtkTubeFilter.h>
#include<vtkSplineFilter.h>
#include<vtkDICOMImageReader.h>
#include<vtkTypedArray.h>
#include<vtkFloatArray.h>
#include<vtkCharArray.h>
#include<vtkTypeInt8Array.h>
#include<vtkTypeUInt8Array.h>
#include<vtkTypeUInt16Array.h>
#include<vtkTypeUInt32Array.h>
#include<vtkTypeUInt64Array.h>
#include<vtkTypeInt32Array.h>
#include<vtkTypeInt64Array.h>



using namespace std;
std::string inputFilename;
QString ext;
bool wrmv=0;
int VRAM;
int vol_id;
int vramval;



//string fullprefix;
//template <typename Iterator > void setval(Iterator begin, Iterator end) {  }

template <typename T>
string ToString(T val)
{
    stringstream stream;
    stream << val;
    return stream.str();
}


#ifdef _WIN32
#include<vtkAVIWriter.h>
//vtkSmartPointer<vtkAVIWriter> movie = vtkSmartPointer <vtkAVIWriter>::New();
//#else
//#include<vtkFFMPEGWriter.h>
//vtkSmartPointer<vtkFFMPEGWriter> movie = vtkSmartPointer<vtkFFMPEGWriter>::New();
#endif


vtkSmartPointer <vtkWindowToImageFilter> w2i = vtkSmartPointer <vtkWindowToImageFilter>::New();



//create callback for clipping 
class vtkBoxWidgetCallback : public vtkCommand
{
public:

	static vtkBoxWidgetCallback *New()
	{
		return new vtkBoxWidgetCallback;
	}
	virtual void Execute(vtkObject *caller, unsigned long, void*)

	{
		vtkBoxWidget2 *widget = reinterpret_cast<vtkBoxWidget2*>(caller);


		if (this->Mapper)
		{
			vtkPlanes *planes = vtkPlanes::New();
			static_cast<vtkBoxRepresentation*>(widget->GetRepresentation())->GetPlanes(planes);
			//widget->OutlineCursorWiresOff();
			//widget->GetPlanes(planes);


			this->Mapper->SetClippingPlanes(planes);
			planes->Delete();
		}
	}


	void SetMapper(vtkSmartVolumeMapper* m)
	{
		this->Mapper = m;
	}

protected:
	vtkBoxWidgetCallback()
	{
		this->Mapper = 0;
	}

	vtkSmartVolumeMapper *Mapper;

};


//create callback for clipping 
class vtkPolyClipCallback : public vtkCommand
{
public:

	static vtkPolyClipCallback *New()
	{
		return new vtkPolyClipCallback;
	}
	virtual void Execute(vtkObject *caller, unsigned long, void*)

	{
		vtkBoxWidget2 *widget = reinterpret_cast<vtkBoxWidget2*>(caller);


		if (this->PolyMapper)
		{
			vtkPlanes *planes = vtkPlanes::New();
			static_cast<vtkBoxRepresentation*>(widget->GetRepresentation())->GetPlanes(planes);
			//widget->OutlineCursorWiresOff();
			//widget->GetPlanes(planes);


			this->PolyMapper->SetClippingPlanes(planes);
			planes->Delete();
		}
	}


	void SetMapper(vtkPolyDataMapper* m)
	{
		this->PolyMapper = m;
	}

protected:
	vtkPolyClipCallback()
	{
		this->PolyMapper = 0;
	}

	vtkPolyDataMapper *PolyMapper;

};



class vtkIPWCallback : public vtkCommand
{
public:
	static vtkIPWCallback *New()
	{
		return new vtkIPWCallback;
	}
	virtual void Execute(vtkObject *caller, unsigned long, void*)
	{
		vtkImplicitPlaneWidget *planeWidget =
			reinterpret_cast<vtkImplicitPlaneWidget*>(caller);
		planeWidget->GetPlane(this->Plane);
		
		
	}
	vtkIPWCallback() :Plane(0)  {}
	vtkPlane *Plane;
};


// Constructor

VolumeViewer::VolumeViewer() 
{
	this->ui = new Ui_VolumeViewer;

    this->ui->setupUi(this);

    //Load custom transfer function dialog
    diatfn = new dialog_tfn(this);

    //Load Dialog for background
    diabg =new  Dialog_Bg(this);

    //Load dialog for lights
    dialight = new dialog_light(this);

    //Load dialog for volume scale

    diavolprop = new dialog_vol_prop(this);

    //Load dialog for opacity

    diaopa = new dialog_opacity(this);

    //Load rotation dialog

	//Load color dialog

	diacol = new dialog_color(this);

	//Load Hessian filter dialog
	diahessian = new dialog_hessian(this);

	//Load threshold filter dialog
	diathresh = new Dialog_threshold(this);

	//gpu settings
	diagpu = new Dialog_gpu(this);

	diafibre = new Dialog_Fibre(this);


    appsettings = new QSettings(this);


    connect(this, SIGNAL(gpinf(int)), this, SLOT(getgpuinfo(int)));
    connect(this, SIGNAL(gpinf(int)), diagpu, SLOT(setvram(int)));
    string line;
    ifstream vram ("vram.info");
    if (vram.is_open())
    {
      while ( getline (vram,line) )
      {
          vramval = atoi(line.c_str());
         // ui->vram_val->setCurrentIndex((vramval/1024)-1);
          emit gpinf(vramval);

      }
      vram.close();
    }

  // Set up action signals and slots
  connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
  connect(diatfn,SIGNAL(sendtfn(int)),this,SLOT(setvolcol(int)));
  
  connect(diaopa,SIGNAL(sendopa(int,bool)),this,SLOT(updateopacity(int,bool)));
  connect(diahessian, SIGNAL(sendhessparams(double, double, double)), this, SLOT(doHessian(double, double, double)));
  connect(diathresh, SIGNAL(sendthreshold(double, double)), this, SLOT(setthresh(double, double)));
  connect(diafibre, SIGNAL(sendfibreparams(int, int)), this, SLOT(setfibres(int, int)));


  }

void VolumeViewer::slotExit() 
{
    if (vtkwid->isVisible())
    {
        vtkwid->close();
    }
	QApplication::quit();

}




void VolumeViewer::on_clear_clicked()
{
	if (vtkwid->isVisible())
    {
		vtkwid->GetRenderWindow()->Finalize();
        vtkwid->GetInteractor()->TerminateApp();
         vtkwid->close();
		 vtkwid->deleteLater();
         ui->actionAxes->setChecked(0);
         ui->actionClip->setChecked(0);
    }

    else
    {

        QMessageBox::critical(0, QObject::tr("Error"), "No Render Window Open");
    }
    //leftRenderer->RemoveAllViewProps();
}

void VolumeViewer::on_actionOpen_triggered()
{
	if (!inputFilename.empty())
    {

      qDebug("Not empty");
    }

    QString Filename = QFileDialog::getOpenFileName(this, tr("Open Volume"), "", tr("TIFF (*.tif);;VTK Files (*.vti);; MATLAB Files(*.mat);; PolyData Files(*.vtp);; HDF5 Files(*.h5)"));
    if (Filename.isEmpty()==0){
    QFileInfo fi(Filename);
    ext = fi.suffix();
	
    //ui->label->setText(ext);

    inputFilename=Filename.toStdString();
	openvol(inputFilename);
  //  if (ext==QString("tif")){
      //  diavolprop->show();
	//}
   }
}

void VolumeViewer::on_actionImage_triggered()
{
	QString Filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("TIFF (*.tif);;PNG Files (*.png);;BMP Files (*.bmp)"));
	if (Filename.isEmpty() == 0){
		string inputimgname = Filename.toStdString();
		openimg(inputimgname);
	}
}

void VolumeViewer::openimg(string inputimgname)
{

	
}

void VolumeViewer::on_actionImage_Sequence_triggered()
{
	//QString Filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("TIFF (*.tif);;BITMAP Files (*.bmp)"));

	QString Dir_Str = QFileDialog::getExistingDirectory(this, tr("Set Directory"), "");

	int vol_id = 0;

	if (!Dir_Str.isEmpty()){

		// set path to user chosen folder
		QDir dir = QDir(Dir_Str);

		// set filter to only search for tif files
		QStringList filters;
		filters << "*.tiff" << "*.tif" << "*.bmp" << "*.dcm";
		dir.setNameFilters(filters);

		// Create list of all *.tif filenames
        QStringList filelist = dir.entryList();
		vtkSmartPointer<vtkStringArray> filenames = vtkSmartPointer<vtkStringArray>::New();
        filenames->SetNumberOfValues(filelist.size());
		
		QString ffile = Dir_Str + "/" + filelist.at(0);
		QFileInfo f(ffile);
		QString filetype = f.suffix();

		//ui->label->setText(QString::fromStdString(str1));

        if (filelist.size() == 0) { QMessageBox::critical(0, QObject::tr("Error"), "No tiff Files Found"); }
		else
		{
			// if there exist tiff files in directory, create vector containing them all

			//filenames->SetNumberOfValues(list.size());
			filenames->SetName("List_of_Filenames");
            for (int i = 0; i < filelist.size(); i++)
			{
                QString temp = Dir_Str + "/" + filelist.at(i);
				QByteArray tempbyte = temp.toUtf8();

				//to assign data use setnumberofvalues and setvalue or insertnextvalue
				filenames->SetValue(i, tempbyte.data());

				
			}

            appsettings->setValue("Numfiles",filelist.size());
            getfileprefix(ffile);
            int Numfiles = filelist.size();

            ui->label->setNum(Numfiles);
			//Read first image to extract dimensions 


			//Create new render window and connect signals to slots
			vtkwid = new vtkwidget;
			ui->actionClip->setChecked(false);
			vtkwid->setGeometry(50, 50, 800, 800);
			vtkwid->setWindowTitle("Render Window");
			connect(diabg, SIGNAL(sendbgparams(double, double, double)), vtkwid, SLOT(setbg(double, double, double)));
			connect(diavolprop, SIGNAL(send_dims(double, double, double)), vtkwid, SLOT(setdims(double, double, double)));
			connect(dialight, SIGNAL(sendlights(double, double, double, double, double, double, double, double, double, double, double, double, double, double)), vtkwid,
			SLOT(updatelights(double, double, double, double, double, double, double, double, double, double, double, double, double, double)));
			connect(diacol, SIGNAL(volcol(double)), vtkwid, SLOT(updatevolcol(double)));
			connect(diacol, SIGNAL(wincol(double)), vtkwid, SLOT(updatewincol(double)));
			connect(vtkwid, SIGNAL(sendhist(QVector<double>)), diatfn, SLOT(plothist(QVector<double>)));
            vtkwid->setvram();
			
            vtkwid->readimseq(filetype, filenames, Numfiles);
			//ui->label->setText(filetype);

		}
		
	}
	
}

void VolumeViewer::on_actionTime_Sequence_triggered()
{
	QString Filename = QFileDialog::getOpenFileName(this, tr("Open Time Sequence Image"), "", tr("TIFF (*.tif)"));
	if (Filename.isEmpty() == 0){
		string inputimgname = Filename.toStdString();
		opentimeseq(inputimgname);
	}
}

void VolumeViewer::opentimeseq(string inputimagename)
{

}

void VolumeViewer::on_actionHessian_triggered()
{

	
	diahessian->show();
}

void VolumeViewer::doHessian(double sigma,double alpha1,double alpha2)
{


}

void VolumeViewer::on_actionAdd_triggered()
{



}

void VolumeViewer::process (vtkMultiProcessController* controller, void* vtkNotUsed(arg))
{
    int myId = controller->GetLocalProcessId();
    std::cout << "My process id is ";
    std::cout << myId << "." << std::endl;
}

void VolumeViewer::openvol(string inputFilename)
{
	if (!inputFilename.empty())
	{
		
		//Create new render window and connect signals to slots
		vtkwid = new vtkwidget;
		ui->actionClip->setChecked(false);
		vtkwid->setGeometry(50, 50, 800, 800);
		vtkwid->setWindowTitle("Render Window");
		connect(diabg, SIGNAL(sendbgparams(double, double, double)), vtkwid, SLOT(setbg(double, double, double)));
		connect(diavolprop, SIGNAL(send_dims(double, double, double)), vtkwid, SLOT(setdims(double, double, double)));
		connect(dialight, SIGNAL(sendlights(double, double, double, double, double, double, double, double, double, double, double, double, double, double)), vtkwid,
			SLOT(updatelights(double, double, double, double, double, double, double, double, double, double, double, double, double, double)));
		connect(diacol, SIGNAL(volcol(double)), vtkwid, SLOT(updatevolcol(double)));

		connect(diacol, SIGNAL(wincol(double)), vtkwid, SLOT(updatewincol(double)));
		connect(vtkwid, SIGNAL(sendhist(QVector<double>)), diatfn, SLOT(plothist(QVector<double>)));
        vtkwid->setvram();


		if (ext == QString("vti"))
		{
			vol_id = 0;
			vtkwid->readvti(inputFilename);
			
		}

        else if (ext == QString("tif"))
		{
			vol_id = 1;
			vtkwid->readtif(inputFilename);
			

			
		}
		else if (ext == QString("mat")|| ext == QString("h5"))
		{
			vol_id = 2;
			diafibre->show();
					
		}

		

		
		

	
    else if (ext == QString("vtp"))
	{
		vol_id = 3;
		vtkSmartPointer <vtkXMLPolyDataReader> poly_read = vtkSmartPointer <vtkXMLPolyDataReader>::New();
		poly_read->SetFileName(inputFilename.c_str());
		poly_read->Update();

		ui->label->setText(QString::number(poly_read->GetOutput()->GetActualMemorySize()));
		vtkwid->renderpol(poly_read->GetOutput());
	}
	else
		QMessageBox::critical(0, QObject::tr("Error"), "Cannot Render; Wrong format!");

	}

	else
	{
		return;
        //	QMessageBox::critical(0, QObject::tr("Error"), "No File Loaded");
	}



}

void VolumeViewer::on_actionExit_2_triggered()
{
    if (vtkwid->isVisible())
    {
        vtkwid->close();
		vtkwid->deleteLater();
    }
    this->close();
}

void VolumeViewer::on_actionOptions_triggered()
{
	diagpu->show();
}

void VolumeViewer::on_actionBackground_triggered()
{
	
diabg->show();
}

void VolumeViewer::on_actionCustom_triggered()
{
 diatfn->show();
}

void VolumeViewer::on_actionLoadLUT_triggered()
{
	QString Filename = QFileDialog::getOpenFileName(this, tr("Load Transfer Function"), "", tr("CSV (*.csv)"));
	if (!Filename.isEmpty()){
		QFile flut(Filename); QStringList listA;
		if (flut.open(QIODevice::ReadOnly)){
			while (!flut.atEnd()){
				QString line = flut.readLine();
				listA.append(line.split(","));
			}

		}
		
		

flut.close();

diatfn->loadlut(listA);
	}
}

void VolumeViewer::on_actionFibrosis_triggered()
{
	
    vtkwid->volumeColor->RemoveAllPoints();
	vtkwid->volumeColor->SetColorSpaceToRGB();
	vtkwid->volumeColor->AddRGBPoint(0,0, 0.0, 0.0,1,1);
    vtkwid->volumeColor->AddRGBPoint(10, 0.0509, 0, 0.0,1,1);
	vtkwid->volumeColor->AddRGBPoint(25, 0.18039, 0.0078, 0.0156863,1,1);
	vtkwid->volumeColor->AddRGBPoint(40, 0.321569, 0.0235294, 0.0235294,1,1);
	vtkwid->volumeColor->AddRGBPoint(50, 0.407843, 0.0392157, 0.0235294,1,1);
	vtkwid->volumeColor->AddRGBPoint(60, 0.498039, 0.0627451, 0.0196078,1,1);
	vtkwid->volumeColor->AddRGBPoint(70, 0.580392, 0.0941176, 0.0392157,1,1);
	vtkwid->volumeColor->AddRGBPoint(80, 0.65098, 0.12549, 0.0392157,1,1);
	vtkwid->volumeColor->AddRGBPoint(90, 0.713725, 0.164706, 0.0352941,1,1);
	vtkwid->volumeColor->AddRGBPoint(100, 0.764706, 0.215686, 0.0313725,1,1);
	vtkwid->volumeColor->AddRGBPoint(110, 0.811765, 0.278431, 0.0313725,1,1);
	vtkwid->volumeColor->AddRGBPoint(120, 0.847059, 0.341176, 0.027451,1,1);
	vtkwid->volumeColor->AddRGBPoint(130, 0.87451, 0.427451, 0.0235294,1,1);
	vtkwid->volumeColor->AddRGBPoint(140, 0.898039, 0.501961, 0.0470588,1,1);
	vtkwid->volumeColor->AddRGBPoint(150, 0.917647, 0.576471, 0.0901961,1,1);
	vtkwid->volumeColor->AddRGBPoint(160, 0.933333, 0.643137, 0.133333,1,1);
	vtkwid->volumeColor->AddRGBPoint(170, 0.94902, 0.694118, 0.180392,1,1);
	vtkwid->volumeColor->AddRGBPoint(180, 0.964706, 0.752941, 0.27451,1,1);
	vtkwid->volumeColor->AddRGBPoint(190, 0.960784, 0.807843, 0.345098,1,1);
	vtkwid->volumeColor->AddRGBPoint(200, 0.976471, 0.862745, 0.431373,1,1);
	vtkwid->volumeColor->AddRGBPoint(210, 0.976471, 0.898039, 0.529412,1,1);
	vtkwid->volumeColor->AddRGBPoint(220, 0.992157, 0.937255, 0.627451,1,1);
	vtkwid->volumeColor->AddRGBPoint(230, 0.992157, 0.968627, 0.752941,1,1);
	vtkwid->volumeColor->AddRGBPoint(240, 0.992157, 0.984314, 0.823529,1,1);
    vtkwid->volumeColor->AddRGBPoint(255, 0.992157, 0.992157, 0.980392,1,1);
   
   vtkwid->  volumeProperty->SetColor(vtkwid->volumeColor);
   vtkwid->GetRenderWindow()->Render();
}

void VolumeViewer::on_actionR_to_B_triggered()
{
    vtkwid->volumeColor->RemoveAllPoints();
    vtkwid->volumeColor->AddRGBPoint(0,1, 0.0, 0.0);
    vtkwid->volumeColor->AddRGBPoint(255,0, 0.0, 1);
    vtkwid-> volumeProperty->SetColor(vtkwid->volumeColor);
    vtkwid->GetRenderWindow()->Render();
}

void VolumeViewer::on_actionGreen_triggered()
{
	vtkwid->volumeColor->RemoveAllPoints();
	vtkwid->volumeColor->AddRGBPoint(0, 0.0, 0.0, 0.0);
	vtkwid->volumeColor->AddRGBPoint(255, 0, 1.0, 0.0);
	vtkwid->volumeProperty->SetColor(vtkwid->volumeColor);
	vtkwid->GetRenderWindow()->Render();
}

void VolumeViewer::on_actionGrey_triggered()
{
	vtkwid->volumeColor->RemoveAllPoints();
	vtkwid->volumeColor->AddRGBPoint(0, 0, 0.0, 0.0);
	vtkwid->volumeColor->AddRGBPoint(255, 1, 1, 1);
	vtkwid->volumeProperty->SetColor(vtkwid->volumeColor);
	vtkwid->GetRenderWindow()->Render();
}

void VolumeViewer::on_actionB_to_R_triggered()
{

   vtkwid-> volumeColor->RemoveAllPoints();
   vtkwid-> volumeColor->AddRGBPoint(0,0, 0, 1);
   vtkwid-> volumeColor->AddRGBPoint(255,1, 0, 0);
   vtkwid-> volumeProperty->SetColor(vtkwid->volumeColor);
   vtkwid->GetRenderWindow()->Render();
}

void VolumeViewer::setvolcol(int rowcnt)
{

 vtkwid->volumeColor->RemoveAllPoints();
 QModelIndex index;
 double tfna[4];
 for (int i=0;i<rowcnt;i++)
 {
     for (int j=0;j<4;j++)
     {
         index = diatfn->model->index(i, j);
         tfna[j]=diatfn->model->data(index).toDouble();
         
     }
    
     vtkwid->volumeColor->AddRGBPoint(tfna[0],tfna[1],tfna[2],tfna[3]);
 }
vtkwid->GetRenderWindow()->Render();

}



void VolumeViewer::on_actionSave_Screenshot_triggered()
{
    if ( vtkwid->isVisible())
    {
    QString fileName = QFileDialog::getSaveFileName(this,
    tr("Save Screenshot"), "",
    tr("(*.png);;All Files (*)"));
    if (fileName.isEmpty()==0){
    vtkSmartPointer<vtkWindowToImageFilter> windowToImageFilter =
    vtkSmartPointer<vtkWindowToImageFilter>::New();
    windowToImageFilter->SetInput(vtkwid->GetRenderWindow());
    //windowToImageFilter->SetMagnification(1); //set the resolution of the output image (1 times the current resolution of vtk render window)
    windowToImageFilter->SetInputBufferTypeToRGBA(); //also record the alpha (transparency) channel
    windowToImageFilter->Update();
    vtkSmartPointer<vtkPNGWriter> writer =
    vtkSmartPointer<vtkPNGWriter>::New();
    writer->SetFileName(fileName.toStdString().c_str());
    writer->SetInputConnection(windowToImageFilter->GetOutputPort());
    writer->Write();
   vtkwid->GetRenderWindow()->Render();}
    }
    else
    {
        QMessageBox::critical(0, QObject::tr("Error"), "No Render Window for screenshot");
    }

}

void VolumeViewer::on_actionRotate_triggered()
{
    diarotat = new dialog_rotation(this);

    connect(diarotat->rtimer,SIGNAL(timeout()),this,SLOT(rot()));

    connect(diarotat,SIGNAL(sendwrmovstat(int)),this,SLOT(rmovstat(int)));

    if ( vtkwid->isVisible())
    {
    diarotat->show();
    }
    else
    {
        QMessageBox::critical(0, QObject::tr("Error"), "No Volume loaded");
    }

}

void dialog_rotation::on_stoprot_clicked()
{
	
    rtimer->stop();

    if (wrmv==1){
//#ifdef _WIN32
		//movie->End();
		//movie->Delete();
//#endif
    w2i->Delete();
    wrmv=0;}

}

void VolumeViewer::on_actionAxes_triggered()
{
	if (ui->actionAxes->isChecked())
	{
		vtkwid->leftRenderer->ResetCamera();
		vtkSmartPointer<vtkAxesActor> axes =
			vtkSmartPointer<vtkAxesActor>::New();
		vtkwid->widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
		vtkwid->widget->SetOrientationMarker(axes);
		vtkwid->widget->SetInteractor(vtkwid->leftRenderer->GetRenderWindow()->GetInteractor());
		vtkwid->widget->SetViewport(0.0, 0.0, 0.2, 0.2);
		vtkwid->widget->SetEnabled(1);
		vtkwid->widget->InteractiveOn();

		vtkwid->GetRenderWindow()->Render();
	}
	else{
			{


				vtkwid->widget->SetEnabled(0);
				vtkwid->leftRenderer->ResetCamera();
				vtkwid->GetRenderWindow()->Render();


			}
	}

}

void VolumeViewer::on_actionClip_triggered()
{

	//Check Clip button
	//vtkwid->leftRenderer->ResetCamera();
	if (vtkwid->isVisible())
	{
		if (ui->actionClip->isChecked())
		{
			if (vol_id == 0 || vol_id == 1) {
				box = vtkSmartPointer<vtkBoxWidget2>::New();
				vtkwid->leftRenderer->ResetCamera();

				//vtkwid->mapper->SetRequestedRenderModeToRayCast();
				vtkSmartPointer <vtkBoxRepresentation> boxrep = vtkSmartPointer <vtkBoxRepresentation>::New();
				boxrep->SetPlaceFactor(1.00);
				boxrep->SetInsideOut(1);

				boxrep->PlaceWidget(vtkwid->mapper->GetInput()->GetBounds());
				boxrep->SetRenderer(vtkwid->leftRenderer);
				box->SetRepresentation(boxrep);
				box->SetTranslationEnabled(1);
				//box->SetInputData(vtkwid->mapper->GetInput());
				// Add a box widget for clipping
				box->SetInteractor(vtkwid->GetInteractor());

				vtkSmartPointer <vtkBoxWidgetCallback> callback = vtkSmartPointer <vtkBoxWidgetCallback>::New();
				callback->SetMapper(vtkwid->mapper);

				box->AddObserver(vtkCommand::InteractionEvent, callback);
				box->On();
				vtkwid->GetInteractor()->Render();
			}
			else if (vol_id == 2 || vol_id == 3)
			{
				box = vtkSmartPointer<vtkBoxWidget2>::New();
				vtkwid->leftRenderer->ResetCamera();

				//vtkwid->mapper->SetRequestedRenderModeToRayCast();
				vtkSmartPointer <vtkBoxRepresentation> boxrep = vtkSmartPointer <vtkBoxRepresentation>::New();
				boxrep->SetPlaceFactor(1.00);
				boxrep->SetInsideOut(1);

				boxrep->PlaceWidget(vtkwid->poly_mapper->GetBounds());
				boxrep->SetRenderer(vtkwid->leftRenderer);
				box->SetRepresentation(boxrep);
				box->SetTranslationEnabled(1);
				//box->SetInputData(vtkwid->mapper->GetInput());
				// Add a box widget for clipping
				box->SetInteractor(vtkwid->GetInteractor());

				vtkSmartPointer <vtkPolyClipCallback> callback = vtkSmartPointer <vtkPolyClipCallback>::New();
				callback->SetMapper(vtkwid->poly_mapper);

				box->AddObserver(vtkCommand::InteractionEvent, callback);
				box->On();
				vtkwid->GetInteractor()->Render();
			}

		}
		else {
			{

				//box->RemoveAllObservers();
				box->Off();
				//box->Delete();
				vtkwid->leftRenderer->ResetCameraClippingRange();
				vtkwid->leftRenderer->ResetCamera();
				vtkwid->GetInteractor()->Render();


			}
		}
	}

	else {
		QMessageBox::critical(0, QObject::tr("Error"), "No volume loaded.\nPlease load the volume first.");
	}


}


void VolumeViewer::on_actionCrop_triggered()
{
    if (vtkwid->isVisible())
    {
        if (ui->actionClip->isChecked())
        {
			/*
            vtkSmartPointer<vtkPlanes> pcoll = vtkSmartPointer<vtkPlanes>::New();
          //  vtkPlanes * clippingPlanes;
            static_cast<vtkBoxRepresentation*>(box->GetRepresentation())->GetPlanes(pcoll);
            vtkwid->volume->GetMapper()->SetClippingPlanes(pcoll);
            vtkClipVolume* clipper = vtkClipVolume::New();
            clipper->SetInputData(vtkwid->mapper->GetInput());
            clipper->SetClipFunction(pcoll);
            clipper->GenerateClipScalarsOn();
            clipper->GenerateClippedOutputOn();

            clipper->Update();
            vtkSmartPointer<vtkXMLUnstructuredGridWriter> volwrite = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
            volwrite->SetInputData(clipper->GetOutput());
            volwrite->SetFileName("Clipped.vtu");
            volwrite->Write();
			*/
            
            //if (vtkwid->sample_rate = 1){
            vtkIdType id = 0; double points[3];
            vtkSmartPointer <vtkPolyData> Crop =  vtkSmartPointer <vtkPolyData>::New();

            static_cast<vtkBoxRepresentation*>(box->GetRepresentation())->GetPolyData(Crop);


            Crop->GetPoint(id, points);


            vtkSmartPointer <vtkExtractVOI> extvoi = vtkSmartPointer <vtkExtractVOI>::New();

            double yb = (vtkwid->dims[1]-1);



            double coord[3][6];
            int j = 0;
            for (vtkIdType i = 8; i < 14; i++)
            {
                double p[3];
                Crop->GetPoint(i, p);
                coord[0][j] = p[0]; coord[1][j] = p[1]; coord[2][j] = p[2];
                j++;
            }
            ui->label->setText(QString::number(coord[0][0]) + " " + QString::number(coord[0][1]) + " " + QString::number(yb-coord[1][3]) + " " + QString::number(yb-coord[1][2]) + " " + QString::number(coord[2][4]) + " " + QString::number(coord[2][5]));

         //   string pre = appsettings->value("fullprefix").toString().toStdString();
        //	cutterthread = new Cutter();
         //   cutterthread->Run(pre,0, (appsettings->value("Numfiles").toInt())-1, int(coord[0][0]), int(coord[0][1]), int(yb - coord[1][3]), int(yb - coord[1][2]), int(coord[2][4]), int(coord[2][5]));


            }
        }

    else {
        QMessageBox::critical(0, QObject::tr("Error"), "You need to clip the volume first.");
    }
    //}
}



void VolumeViewer::on_actionReslice_triggered()
{
    if (vtkwid->isVisible())
    {
      //  if (ui->actionClip->isChecked())
       // {
       //     double *bounds;
       //     bounds = box->GetRepresentation()->GetBounds();

           // vtkSmartPointer<vtkImageReslice> reslice =
           //    vtkSmartPointer<vtkImageReslice>::New();
          //  reslice->SetInputData(vtkwid->mapper->GetInput());
            /*
            vtkSmartPointer<vtkMatrixToLinearTransform> mat2tran =
                    vtkSmartPointer<vtkMatrixToLinearTransform>::New();
            //mat2tran->SetInput(box->GetRepresentation()->GetMatrix());
            vtkMatrix4x4 *mat;
           mat = static_cast<vtkBoxRepresentation*>(box->GetRepresentation())->GetMatrix();
                   mat2tran->SetInput(mat);
            std::cout << "Matrix: " << endl << mat << std::endl;
            mat2tran->Update();

            // Matrices for axial, coronal, sagittal, oblique view orientations
             static double sagittalElements[16] =
             { 1,   0,     0,   0,
               0,  0,      1,   0,
               0,  -1,     0,   0,
               0,   0,     0,   1 };


            // Set the slice orientation
               vtkSmartPointer<vtkMatrix4x4> resliceAxes =
                 vtkSmartPointer<vtkMatrix4x4>::New();
                resliceAxes->DeepCopy(sagittalElements);
                // Set the point through which to slice
               double * center;
               center = vtkwid->volume->GetCenter();
               resliceAxes->SetElement(0, 3, center[0]);
               resliceAxes->SetElement(1, 3, center[1]);
               resliceAxes->SetElement(2, 3, center[2]);
              // reslice->SetResliceAxes(resliceAxes);
               reslice->SetOutputDimensionality(3);
               reslice->SetInterpolationModeToCubic();

vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();

transform->RotateX(30);
transform->RotateY(0);
transform->RotateZ(90);
transform->Update();

vtkSmartPointer<vtkTransformFilter> transformModel =
      vtkSmartPointer<vtkTransformFilter>::New();

transformModel->SetTransform(transform);
transformModel->SetInputData(vtkwid->mapper->GetInput());
transformModel->SetOutputPointsPrecision(4);
transformModel->Update();


           // reslice->Update();
            QString fileNameSave = QFileDialog::getSaveFileName(this,
                tr("Save Volume"), "",
                tr("VTK File (*.vtu)"));
            string volname = fileNameSave.toStdString();
            vtkSmartPointer<vtkXMLUnstructuredGridWriter> volwrite = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
            volwrite->SetInputData(transformModel->GetOutput());

            volwrite->SetFileName(volname.c_str());
            volwrite->Write();
*/

//ui->label->setText(QString::number(bounds[0]) + " " + QString::number(bounds[1]) +  " " + QString::number(bounds[2])+ " " + QString::number(bounds[3]) + " " + QString::number(bounds[4]) + " " + QString::number(bounds[5]) + " " + QString::number(bounds[6]));

      //  }

      vtkSmartPointer < vtkTransform> tran =vtkSmartPointer < vtkTransform>::New();
static_cast<vtkBoxRepresentation*>(box->GetRepresentation())->GetTransform(tran);
        double *ori;
        ori=tran->GetOrientation();
		
        double *center;
        center=vtkwid->volume->GetCenter();

             double *Bounds;
           Bounds = static_cast<vtkBoxRepresentation*>(box->GetRepresentation())->GetBounds();

           ui->label->setText(QString::number(ori[0]) + " " + QString::number(ori[1])  + " " + QString::number(ori[2]) + " " + QString::number(ori[3]) + " "+QString::number(Bounds[0]) + " " + QString::number(Bounds[1]) +  " " + QString::number(Bounds[2])+ " " +
                   QString::number(Bounds[3]) + " " + QString::number(Bounds[4]) + " " + QString::number(Bounds[5]));

/*
        vtkSmartPointer<vtkTransform> transform =
          vtkSmartPointer<vtkTransform>::New();
        // Rotate about the center
        transform->Translate(center[0], center[1], center[2]);
        transform->RotateWXYZ(ori[0],ori[1],ori[2],ori[3]);
        transform->Translate(-center[0], -center[1], -center[2]);


        vtkSmartPointer<vtkImageReslice> reslice =
            vtkSmartPointer<vtkImageReslice>::New();
          reslice->SetInputData(vtkwid->mapper->GetInput());
          reslice->SetResliceTransform(transform);
          reslice->SetInterpolationModeToCubic();
          reslice->SetOutputExtent(int(Bounds[0]),int(Bounds[1]),int(Bounds[2]),int(Bounds[3]),int(Bounds[4]),int(Bounds[5]));
          reslice->SetOutputSpacing(1,1,1);
          reslice->SetOutputOrigin(
              vtkwid->volume->GetOrigin()[0],
              vtkwid->volume->GetOrigin()[1],
              vtkwid->volume->GetOrigin()[2]);



          //Write the resampled data as a temporary file to be viewed
          vtkSmartPointer<vtkTIFFWriter> volwrite = vtkSmartPointer<vtkTIFFWriter>::New();
              //volwrite->SetFileName("/hpc/gram526/Segmented/Rabbit.tif");
          volwrite-> SetFilePrefix("/hpc/gram526/Segmented/test/");
          volwrite->SetFilePattern("%stestreslice%04d.tif");
          //volwrite->SetDimensions(reslice->GetOutputPort()->GetDimensions());
          //volwrite->SetCompressionToNoCompression ();
          volwrite->SetInputConnection(reslice->GetOutputPort());
          volwrite->SetFileDimensionality(3);
          volwrite->Update();

              volwrite->Write();

*/

    }
}


void VolumeViewer::on_actionDimensions_triggered()
{
    diavolprop->show();
}

void VolumeViewer::on_actionLights_triggered()
{
    dialight->show();
}

void VolumeViewer::on_actionAbout_triggered()
{
    QMessageBox::about( 0, "About", "Volume Viewer v 0.1.0\nCopyright 2014\nThe University of Auckland" ) ;
}

void VolumeViewer::on_actionOpacity_triggered()
{
    diaopa->show();
}

void VolumeViewer::updateopacity(int rowcntopa, bool col)
{

	ui->label->setNum(col);

	double tfopa[2];
	QModelIndex indexopa;
	if (!col)
	{
		vtkwid->volumeScalarOpacity->RemoveAllPoints();
		for (int i = 0; i < rowcntopa; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				indexopa = diaopa->modelopa->index(i, j);
				tfopa[j] = diaopa->modelopa->data(indexopa).toDouble();
			}
			vtkwid->volumeScalarOpacity->AddPoint(tfopa[0], tfopa[1]);
		}
		
	}


		
	else if (col)
	{
		vtkwid->volumeScalarOpacity1->RemoveAllPoints();
		vtkwid->volumeScalarOpacity2->RemoveAllPoints();
		vtkwid->volumeScalarOpacity3->RemoveAllPoints();
		for (int i = 0; i < rowcntopa; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				indexopa = diaopa->modelopa->index(i, j);
				tfopa[j] = diaopa->modelopa->data(indexopa).toDouble();
			}
			vtkwid->volumeScalarOpacity1->AddPoint(tfopa[0], tfopa[1]);
		}


		for (int i = 0; i < rowcntopa; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				indexopa = diaopa->modelopa2->index(i, j);
				tfopa[j] = diaopa->modelopa2->data(indexopa).toDouble();
			}

			vtkwid->volumeScalarOpacity2->AddPoint(tfopa[0], tfopa[1]);

		}
		for (int i = 0; i < rowcntopa; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				indexopa = diaopa->modelopa3->index(i, j);
				tfopa[j] = diaopa->modelopa3->data(indexopa).toDouble();
			}
			vtkwid->volumeScalarOpacity3->AddPoint(tfopa[0], tfopa[1]);
		}

	}
	    
		vtkwid->GetRenderWindow()->Render();

}

void VolumeViewer::rmovstat(int wr)
{

    if (wr==2){
		w2i->SetInput(vtkwid->GetRenderWindow());
//#ifdef _WIN32
       // movie->SetCompression(0);
       // movie->SetFileName(diarotat->movname.c_str());
	//	movie->SetInputConnection(w2i->GetOutputPort());
	//	movie->SetRate(30);
	//	movie->Start();
//#endif
    diarotat->rtimer->start();
    wrmv=1;
    }

    else if (wr==3){


        diarotat->rtimer->start();}


}

void VolumeViewer::rot()
{
 if (wrmv==1)
   {
//#ifdef _WIN32
	  // movie->Write();
//#endif
     w2i->Modified();}

 //To add centre
 if (vol_id == 3 || vol_id==2)
 {
	 vtkwid->poly_actor->RotateWXYZ(diarotat->rotang, diarotat->rotmat[0], diarotat->rotmat[1], diarotat->rotmat[2]);
 }
 //vtkwid->poly_actor->GetCenter
 else if (vol_id == 0 || vol_id==1)
 {
	 vtkwid->volume->RotateWXYZ(diarotat->rotang,diarotat->rotmat[0],diarotat->rotmat[1],diarotat->rotmat[2]);
 }
  vtkwid->GetRenderWindow()->Render();

}

void VolumeViewer::on_actionSlice_triggered()
{
	vtkwid->leftRenderer->ResetCamera();

	vtkSmartPointer<vtkPlane> plane = vtkSmartPointer<vtkPlane>::New();


	vtkSmartPointer<vtkIPWCallback> myCallback =
		vtkSmartPointer<vtkIPWCallback>::New();
	myCallback->Plane = plane;
	

	vtkSmartPointer <vtkImplicitPlaneWidget> planeWidget = vtkSmartPointer <vtkImplicitPlaneWidget>::New();
	planeWidget->SetInteractor(vtkwid->GetInteractor());
	planeWidget->SetInputData(vtkwid->mapper->GetInput());
	planeWidget->SetDefaultRenderer(vtkwid->leftRenderer);
	planeWidget->SetPlaceFactor(1.05);
	planeWidget->PlaceWidget();
	planeWidget->SetOrigin(vtkwid->volume->GetOrigin());
	planeWidget->SetNormal(plane->GetNormal());
	planeWidget->UpdatePlacement();

	planeWidget->AddObserver(vtkCommand::InteractionEvent, myCallback);

	planeWidget->EnabledOn();
	
	vtkwid->leftRenderer->Render();


	
}

void VolumeViewer::on_actionGPU_Texture_triggered()
{

    vtkwid->mapper->SetRequestedRenderMode(vtkSmartVolumeMapper::GPURenderMode);
    vtkwid->GetRenderWindow()->Render();
}

void VolumeViewer::on_actionRay_Cast_triggered()
{
	vtkwid->mapper->SetRequestedRenderMode(vtkSmartVolumeMapper::RayCastRenderMode);
    vtkwid->GetRenderWindow()->Render();
}


void VolumeViewer::on_actionSave_Volume_triggered()
{


	QString fileNameSave = QFileDialog::getSaveFileName(this,
		tr("Save Volume"), "",
		tr("VTK File (*.vti)"));
	string volname = fileNameSave.toStdString();
	savevol(volname);

}

void VolumeViewer::savevol(string volname)
{
	if (!volname.empty())
	{
		vtkSmartPointer<vtkXMLImageDataWriter> volwrite = vtkSmartPointer<vtkXMLImageDataWriter>::New();
		volwrite->SetInputData(vtkwid->mapper->GetInput());
		volwrite->SetFileName(volname.c_str());
		volwrite->Write();
	}
}

void VolumeViewer::on_actionColor_triggered()
{
	diacol->show();
}

void VolumeViewer::on_actionIsosurface_triggered()
{
	vtkwid->renderpoly();	
}

void VolumeViewer::on_actionNearest_triggered()
{
	vtkwid->volumeProperty->SetInterpolationTypeToNearest();
	vtkwid->GetRenderWindow()->Render();
}

void VolumeViewer::on_actionLinear_triggered()
{
	vtkwid->volumeProperty->SetInterpolationTypeToLinear();
	vtkwid->GetRenderWindow()->Render();
}

void VolumeViewer::on_actionCubic_triggered()
{
	vtkwid->volumeProperty->SetInterpolationType(VTK_CUBIC_INTERPOLATION);
	vtkwid->GetRenderWindow()->Render();
}


void VolumeViewer::on_actionAnaglyph_triggered()
{
	if (ui->actionAnaglyph->isChecked()){
		vtkwid->GetRenderWindow()->SetStereoTypeToAnaglyph();
		vtkwid->GetRenderWindow()->SetStereoRender(1);
		vtkwid->GetRenderWindow()->Render();
	}
	else{
		vtkwid->leftRenderer->ResetCamera();
		vtkwid->GetRenderWindow()->SetStereoRender(0);
		vtkwid->GetRenderWindow()->Render();
	    }

}

void VolumeViewer::on_actionRed_Blue_triggered()
{
	if (ui->actionRed_Blue->isChecked()){
		vtkwid->GetRenderWindow()->SetStereoTypeToRedBlue();
		vtkwid->GetRenderWindow()->SetStereoRender(1);
		vtkwid->GetRenderWindow()->Render();
	}
	else{
		vtkwid->leftRenderer->ResetCamera();
		vtkwid->GetRenderWindow()->SetStereoRender(0);
		vtkwid->GetRenderWindow()->Render();
	}
}
void VolumeViewer::on_actionInterlaced_triggered()
{
	if (ui->actionInterlaced->isChecked()){
		vtkwid->GetRenderWindow()->SetStereoTypeToInterlaced();
		vtkwid->GetRenderWindow()->SetStereoRender(1);
		vtkwid->GetRenderWindow()->Render();
	}
	else{
		vtkwid->leftRenderer->ResetCamera();
		vtkwid->GetRenderWindow()->SetStereoRender(0);
		vtkwid->GetRenderWindow()->Render();
	}
}


void VolumeViewer::on_actionThreshold_triggered()
{

	
}

void VolumeViewer::setthresh(double lthreshold, double uthreshold)
{
    vtkSmartPointer <vtkThreshold> thresholdfilter = vtkSmartPointer<vtkThreshold>::New();
    thresholdfilter->SetInputData(vtkwid->mapper->GetInput());
    thresholdfilter->ThresholdBetween(lthreshold,uthreshold);
    thresholdfilter->Update();
    vtkwid->leftRenderer->ResetCamera();
    vtkwid->GetRenderWindow()->Render();
    //itkhess->threshold(vtkwid->mapper->GetInput(), lthreshold, uthreshold);
//	vtkwid->volume->RemoveAllObservers();
//	vtkwid->resample(itkhess->threshimg);
	
	
}

void VolumeViewer::generatefibres(string inputFilename, int fiblen, int skip)
{

	
/*
	mxArray *matarr, *matcolarr;
	MATFile *matf;

	vtkSmartPointer<vtkTypeUInt16Array> pointarray = vtkSmartPointer<vtkTypeUInt16Array>::New();
	//vtkSmartPointer<vtkUnsignedShortArray> dataarr = vtkSmartPointer<vtkUnsignedShortArray>::New();
	//vtkSmartPointer<vtkImageData> matimg = vtkSmartPointer<vtkImageData>::New();

	matf = matOpen(inputFilename.c_str(), "r");
	if (matf == NULL)
	{
		QMessageBox::critical(0, QObject::tr("Error"), "Error Loading File");
	}


	else {


		const char **dir;
		const char *name;
		int	  ndir;
		int i;
		dir = (const char **)matGetDir(matf, &ndir);
		if (dir == NULL)
		{
			QMessageBox::critical(0, QObject::tr("Error"), "Error reading directory of file");

		}

		else {
			matarr = matGetVariable(matf, "fibres");
			matcolarr = matGetVariable(matf, "MeasureAngles");
		}




		const mwSize * matsize = mxGetDimensions(matarr);

		ui->label->setText(QString::number(matsize[1]));


		if (matarr == NULL)
		{
			QMessageBox::critical(0, QObject::tr("Error"), "Could not copy to array");
		}






		//QProgressDialog progress("Loading...", "Abort", 0, matimg->GetNumberOfPoints(), this);
		//	progress.setWindowModality(Qt::WindowModal);

		vtkSmartPointer <vtkCellArray> lines = vtkSmartPointer <vtkCellArray> ::New();

		vtkSmartPointer <vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
		points->SetDataTypeToShort();

		vtkIdType k = 0;
		vtkDataArray *colors;
		colors->CreateDataArray(VTK_TYPE_INT8);
		//colors->SetNumberOfComponents(1);
		//ui->label->setText(QString::number(readermat->GetMTime()));ee
		colors = mxArrayTovtkDataArray(matcolarr,1);

		colors->SetName("Colors");
		colors->Squeeze();

		QProgressDialog progress("Loading...", "Abort", 0, matsize[1], this);
		progress.setWindowModality(Qt::WindowModal);

		vtkDataArray* matvtkarr;

		
#pragma parallel 
		for (vtkIdType i = 0; i <matsize[1]; i++)
		{
			progress.setValue(i);
			if (progress.wasCanceled())
			{

				matClose(matf);
				mxDestroyArray(matarr);
				mxDestroyArray(matcolarr);

				return;
			}
			//	mxArray *mline = mxGetCell(matarr, i);
			
			matvtkarr = mxArrayTovtkDataArray(mxGetCell(matarr, i),1);
			ui->label->setText(QString::number(matvtkarr->GetNumberOfComponents()));

			//matvtkarr->SetNumberOfComponents(1);
			matvtkarr->Squeeze();

			//ui->label->setText(QString::number(L));

			if (matvtkarr->GetNumberOfTuples() > fiblen)
			{
				lines->InsertNextCell(matvtkarr->GetNumberOfTuples());

				for (vtkIdType j = 0; j < matvtkarr->GetNumberOfTuples() ; j ++)
				{
					pointarray->InsertNextTuple3(matvtkarr->GetComponent(j, 0), matvtkarr->GetComponent(j, 1), matvtkarr->GetComponent(j, 2));
					points->InsertNextPoint(matvtkarr->GetComponent(j, 0), matvtkarr->GetComponent(j, 1), matvtkarr->GetComponent(j, 2));
					lines->InsertCellPoint(k);
					k++;
				}


			}
		}

		progress.setValue(matsize[1]);
		lines->Squeeze();
		points->Squeeze();
		matClose(matf);
		mxDestroyArray(matarr);
		mxDestroyArray(matcolarr);

		vtkSmartPointer <vtkPolyData> polyd = vtkSmartPointer <vtkPolyData>::New();
		//	polyd->Allocate();


		polyd->SetPoints(points);
		polyd->SetLines(lines);
		polyd->GetCellData()->SetScalars(colors);
		polyd->Squeeze();
		/*
		vtkSmartPointer<vtkSplineFilter> splinefilter = vtkSmartPointer<vtkSplineFilter>::New();
		splinefilter->SetInputData(polyd);
		splinefilter->SetNumberOfSubdivisions(10);
		splinefilter->Update();

		vtkSmartPointer<vtkTubeFilter> tubeFilter =
			vtkSmartPointer<vtkTubeFilter>::New();
		tubeFilter->SetInputData(splinefilter->GetOutput());
		tubeFilter->SetRadius(1); //default is .5
		tubeFilter->CappingOn();
		tubeFilter->Update();
		
		//ui->label->setText(QString::number(points->GetDataType()) + " " + QString::number(points->GetActualMemorySize()) + " " + QString::number(lines->GetActualMemorySize()) + " " + QString::number(polyd->GetActualMemorySize()));


		vtkwid->renderpol(polyd);
		
	}
	*/
}


void VolumeViewer::setfibres(int fiblen, int skip)
{

	generatefibres(inputFilename, fiblen, skip);

}

void VolumeViewer::getgpuinfo(int vram)
{
  //  VRAM=vram;
    ui->label->setNum(vram);
	
}


void VolumeViewer::on_actionHelp_Topics_triggered()
{

  QDesktopServices::openUrl(QUrl("http://sites.google.com/a/aucklanduni.ac.nz/volumeviewer", QUrl::TolerantMode));
}


void VolumeViewer::getfileprefix(QString ffile)
{
	QStringList PrefixList = ffile.split(".");
	
	QStringList list2 = PrefixList[0].split("/");
	int list2length = list2.length()-1;
	string filename = list2[list2length].toStdString();

	PrefixList[0].replace("/", "\\\\");

	string PrefixNum = PrefixList[0].toStdString();
	//ui->label->setText(PrefixNum);
	string num = "", FilePrefix = "";
	int res = 0;
	for (int i = filename.length()-1; i >= 0; i--)
	{
		if (isdigit(filename[i]))
			num += filename[i];
		
		else
			//FilePrefix += PrefixNum[i];
			break;
	}

	for (int i = 0; i < filename.length() - num.length(); i++)
	{
		FilePrefix += filename[i];
	}

	string prefiX;
	for (int i = 0; i < list2.length() - 1; i++)
	{
        prefiX += list2[i].toStdString()+"//";
	}

	//string fullprefix =FilePrefix+"%0"+std::to_string(num.length())+"d.tif";
    string fullprefix = prefiX + FilePrefix + "%0" + ToString(num.length()) + "d.tif";
    //ui->label->setNum(666);
    ui->label->setNum(appsettings->value("Numfiles").toInt());
    appsettings->setValue("fullprefix" , QString::fromStdString(fullprefix));

    //printf(fullprefix.c_str());
}






