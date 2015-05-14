#include "VolumeViewer.h"
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkPlanes.h>
#include <vtkPlane.h>
#include <vtkBoxWidget.h>
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
#include<vtkAVIWriter.h>
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
#include<vtkMatlabMexAdapter.h>
#include<mat.h>
#include <matrix.h>
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
#include<vtkArrayIteratorIncludes.h>

using namespace std;
std::string inputFilename;
QString ext;
bool wrmv=0;

//template <typename Iterator > void setval(Iterator begin, Iterator end) {  }



vtkSmartPointer<vtkAVIWriter> movie = vtkSmartPointer <vtkAVIWriter>::New();
vtkSmartPointer <vtkWindowToImageFilter> w2i = vtkSmartPointer <vtkWindowToImageFilter>::New();



class vtkBoxWidgetCallback : public vtkCommand
{
public:
  static vtkBoxWidgetCallback *New()
    { return new vtkBoxWidgetCallback; }
  virtual void Execute(vtkObject *caller, unsigned long, void*)

    {
      vtkBoxWidget *widget = reinterpret_cast<vtkBoxWidget*>(caller);
	  
      if (this->Mapper)
        {
        vtkPlanes *planes = vtkPlanes::New();
        widget->GetPlanes(planes);
        this->Mapper->SetClippingPlanes(planes);
        planes->Delete();
        }
    }
  void SetMapper(vtkSmartVolumeMapper* m)
    { this->Mapper = m; }

protected:
  vtkBoxWidgetCallback()
    { this->Mapper = 0; }

  vtkSmartVolumeMapper *Mapper;
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

  // Set up action signals and slots
  connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
  connect(diatfn,SIGNAL(sendtfn(int)),this,SLOT(setvolcol(int)));
  connect(diaopa,SIGNAL(sendopa(int)),this,SLOT(updateopacity(int)));
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

	QString Filename = QFileDialog::getOpenFileName(this, tr("Open Volume"), "", tr("TIFF (*.tif);;VTK Files (*.vti);; MATLAB Files(*.mat)"));
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
	QString Filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("TIFF (*.tif);;PNG Files (*.png)"));
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
	//QString Filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("TIFF (*.tif);;PNG Files (*.png)"));
	//const char = QFileDialog::getExistingDirectory(this, tr("Set Directory"), "");
	QString Dir_Str = QFileDialog::getExistingDirectory(this, tr("Set Directory"), "");

	//vtkSmartPointer<vtkDirectory> dir = vtkSmartPointer<vtkDirectory>::New();
	//vtkSmartPointer<vtkStringArray> starr = vtkSmartPointer<vtkStringArray>::New();
	//string dirstr = Dir_Str.toStdString();
	//const char *dirchar = dirstr.c_str();
	//dir->Open(dirchar);
	//starr = dir->GetFiles();
	//starr->
	if (!Dir_Str.isEmpty()){


		//vtkSmartPointer<vtkImageReader2> imgrd = vtkSmartPointer<vtkImageReader2>::New();


		// set path to user chosen folder
		QDir dir = QDir(Dir_Str);

		// set filter to only search for bmp files
		QStringList filters;
		filters << "*.tiff"<<"*.tif";
		dir.setNameFilters(filters);

		// Create list of all *.dcm filenames
		QStringList list = dir.entryList();
		vtkSmartPointer<vtkStringArray> filenames = vtkSmartPointer<vtkStringArray>::New();
		filenames->SetNumberOfValues(list.size());
		if (list.size() == 0) { QMessageBox::critical(0, QObject::tr("Error"), "No Files Found"); }
		else
		{
			// if there exist tiff files in directory, create vector containing them all

			//filenames->SetNumberOfValues(list.size());
			filenames->SetName("List_of_Filenames");
			for (int i = 0; i < list.size(); i++)
			{


				QString temp = Dir_Str + "/" + list.at(i);
				QByteArray tempbyte = temp.toUtf8();



				//to assign data use setnumberofvalues and setvalue or insertnextvalue
				filenames->SetValue(i, tempbyte.data());

				//filenames->InsertNextValue(temp);


			}

			vtkSmartPointer<vtkTIFFReader>readimg = vtkSmartPointer<vtkTIFFReader>::New();
			readimg->SetFileName(filenames->GetValue(0));
			readimg->Update();

			//int dims[6]; readimg->GetOutput()->GetInformation();
			//readimg->GetOutput()->GetExtent(dims);

			int dims[3]; int ext[6];
			readimg->GetOutput()->GetDimensions(dims);
			

			
			int N = list.size();
			__int64 dim1, dim2, dim3;
			
			
			dims[2] = N;
			dim1 = dims[0]; dim2 = dims[1]; dim3 = dims[2];
			//ui->label->setText(QString::number(ext[0]) + QString::number(ext[1]) + QString::number(ext[2]));
			
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
	
			
			
			__int64 npoints = (dim1*dim2*dim3);
			vtkwid->input->SetDimensions(dims);
			vtkSmartPointer<vtkUnsignedShortArray> volarray = vtkSmartPointer<vtkUnsignedShortArray>::New();
			
			volarray->SetNumberOfComponents(1);
			vtkwid->input->AllocateScalars(VTK_UNSIGNED_SHORT, 1);
			
			volarray->SetNumberOfValues(npoints);

			
			
			//clock_t start = clock();
			for (__int64 k = 0; k <N; k++)
			{
				
				vtkwid->imseq->SetFileName(filenames->GetValue(k));
				vtkwid->imseq->Update();
				//vtkImageData *img = vtkwid->imseq->GetOutput();
				
				vtkDataArray *vals = vtkwid->imseq->GetOutput()->GetPointData()->GetArray("Tiff Scalars");
			
				vals->SetNumberOfComponents(1);
				__int64 vals64 = vals->GetNumberOfTuples();
				__int64 offset = k*vals64;
				
				vtkArrayIterator *iter = volarray->NewIterator();
				/*
				switch (volarray->GetDataType())
				{
					vtkArrayIteratorTemplateMacro(volarray,setval(vtkDABegin,VTKDAEnd))
				}
				*/
				
				for (__int64 j = 0; j < vals->GetNumberOfTuples(); j++)
					
				{
					
					volarray->SetValue(offset + j, vals->GetComponent(j, 0));
					
				}
				

			}
			
			//ui->label->setText(QString::number(((double)clock() - start) / CLOCKS_PER_SEC));
			vtkwid->input->SetSpacing(1.0, 1.0, 1.0);
			vtkwid->input->SetOrigin(0.0, 0.0, 0.0);
			
			vtkwid->input->GetPointData()->SetScalars(volarray);
			
			//volarray->Delete();
			//ui->label->setText(QString::number(vtkwid->input->GetActualMemorySize()));
			
			vtkwid->initialize();
					}
		
	}
	
}

void VolumeViewer::on_actionHessian_triggered()
{
	diahessian->show();
}

void VolumeViewer::on_actionAdd_triggered()
{

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

		if (ext == QString("vti"))
		{
			vtkXMLImageDataReader *rvti = vtkXMLImageDataReader::New();
			rvti->SetFileName(inputFilename.c_str());
			rvti->Update();
			vtkwid->input = rvti->GetOutput();
			
		//	vtkwid->reader = vtkwid->readervti;
			vtkwid->initialize();
			rvti->Delete();
		}

		else if (ext == QString("tif"))
		{
			vtkTIFFReader *rtiff = vtkTIFFReader::New();
			rtiff->SetFileName(inputFilename.c_str());
			rtiff->SetOrientationType(ORIENTATION_TOPLEFT);
			rtiff->Update();
			vtkwid->input = rtiff->GetOutput();
			
			vtkwid->initialize();
			rtiff->Delete();

		}
		else if (ext == QString("mat"))
		{
			
			vtkSmartPointer<vtkMatlabMexAdapter> readermat = vtkSmartPointer<vtkMatlabMexAdapter>::New();
			mxArray *matarr;
			MATFile *matf;
			vtkArray *matvtkarr;
			vtkSmartPointer<vtkUnsignedShortArray> dataarr = vtkSmartPointer<vtkUnsignedShortArray>::New();
			

			matf = matOpen(inputFilename.c_str(), "r");
			if (matf == NULL) {
				QMessageBox::critical(0, QObject::tr("Error"), "Error Loading File");
			}
			else{

				matarr = matGetVariable(matf, "IM");
				const mwSize * matsize = mxGetDimensions(matarr);

			//	dataarr->SetNumberOfTuples(matsize[0] * matsize[1] * matsize[2]);

				if (matarr == NULL) {
					QMessageBox::critical(0, QObject::tr("Error"), "Could not copy to array");
				}

				matvtkarr = readermat->mxArrayTovtkArray(matarr);
				vtkwid->input->SetDimensions(matsize[0], matsize[1], matsize[2]);
				

				
			dataarr->SetNumberOfTuples(vtkwid->input->GetNumberOfPoints());

				 
			for (vtkIdType i = 0; i < vtkwid->input->GetNumberOfPoints(); i++)
				{
							dataarr->SetVariantValue(i, matvtkarr->GetVariantValueN(i));
		         }

				
			
			
			vtkwid->input->SetOrigin(0, 0, 0);
			vtkwid->input->SetSpacing(1, 1, 1);
	    	vtkwid->input->GetPointData()->SetScalars(dataarr);
			//ui->label->setNum(int(vtkwid->input->GetNumberOfPoints()));
		}

		

		vtkwid->initialize();
		

	}
	
	else
		QMessageBox::critical(0, QObject::tr("Error"), "Cannot Render; wrong format!");

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
				listA = line.split(",");
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
    windowToImageFilter->SetMagnification(1); //set the resolution of the output image (2 times the current resolution of vtk render window)
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
    movie->End();
    movie->Delete();
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
	vtkwid->leftRenderer->ResetCamera();
if (vtkwid->isVisible())
{
    if (ui->actionClip->isChecked())
{
		box = vtkSmartPointer<vtkBoxWidget>::New();
		vtkwid->leftRenderer->ResetCamera();
        box->SetInputData(vtkwid->mapper->GetInput());
    // Add a box widget for clipping
        box->SetInteractor(vtkwid->GetInteractor());
        box->SetDefaultRenderer(vtkwid->leftRenderer);
		
		box->SetPlaceFactor(1.02);
        box->InsideOutOn();
        box->PlaceWidget();
        vtkBoxWidgetCallback *callback = vtkBoxWidgetCallback::New();
        callback->SetMapper(vtkwid->mapper);
        box->AddObserver(vtkCommand::InteractionEvent, callback);
        box->EnabledOn();
		
        vtkwid->leftRenderer->Render();
        callback->Delete();}
    else{
        {
			
			//box->RemoveAllObservers();
			box->EnabledOff();
			//box->Delete();
			vtkwid->leftRenderer->ResetCameraClippingRange();
			vtkwid->leftRenderer->ResetCamera();
			vtkwid->GetRenderWindow()->Render();


        }
    }
}

else {
    QMessageBox::critical(0, QObject::tr("Error"), "No volume loaded.\nPlease load the volume first.");
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

void VolumeViewer::updateopacity(int rowcntopa)
{

    vtkwid->volumeScalarOpacity->RemoveAllPoints();
    double tfopa[2];
    QModelIndex indexopa;
    for (int i=0;i<rowcntopa;i++)
    {
        for (int j=0;j<2;j++)
        {
            indexopa = diaopa->modelopa->index(i, j);
            tfopa[j]=diaopa->modelopa->data(indexopa).toDouble();
        }
        vtkwid->volumeScalarOpacity->AddPoint(tfopa[0],tfopa[1]);
    }
   vtkwid->GetRenderWindow()->Render();

}

void VolumeViewer::rmovstat(int wr)
{

    if (wr==2){
		w2i->SetInput(vtkwid->GetRenderWindow());
    movie->SetFileName(diarotat->movname.c_str());
    movie->SetInputConnection(w2i->GetOutputPort());
    movie->SetRate(30);
    movie->Start();
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
     movie->Write();
     w2i->Modified();}
  vtkwid->volume->RotateWXYZ(diarotat->rotang,diarotat->rotmat[0],diarotat->rotmat[1],diarotat->rotmat[2]);
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
	planeWidget->SetInputData(vtkwid->input);
	planeWidget->SetDefaultRenderer(vtkwid->leftRenderer);

	planeWidget->SetPlaceFactor(1.01);
	planeWidget->PlaceWidget();
	planeWidget->SetOrigin(vtkwid->volume->GetOrigin());
	planeWidget->SetNormal(plane->GetNormal());
	planeWidget->UpdatePlacement();

	planeWidget->AddObserver(vtkCommand::InteractionEvent, myCallback);




	planeWidget->EnabledOn();
	
	vtkwid->leftRenderer->Render();

	/*

	vtkRenderer * renderer = vtkRenderer::New();
	vtkRenderWindow *renwin = vtkRenderWindow::New();
	vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();

	renwin->AddRenderer(renderer);
	iren->SetRenderWindow(renwin);
	renwin->SetSize(800, 800);

	vtkImageResliceMapper *mapper = vtkImageResliceMapper::New();
	     mapper->SetInputData(vtkwid->mapper->GetInput());
	     mapper->SetSlicePlane(plane);
		 mapper->SliceFacesCameraOn();
		 //mapper->SetSliceAtFocalPoint(1);
		 vtkImageSlice *slice = vtkImageSlice::New();

		 slice->SetMapper(mapper);
		 


		 renderer->AddViewProp(slice);
		 vtkInteractorStyleImage *style = vtkInteractorStyleImage::New();
		 style->SetInteractionModeToImage3D();
		 iren->SetInteractorStyle(style);




	 
		    
			 
			 renwin->SetInteractor(iren);
			 renwin->Render();
			  vtkCamera * cam1 = renderer->GetActiveCamera();
			  cam1->ParallelProjectionOn();
			 renwin->Render();
			 iren->Start();
			 */
	
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

void VolumeViewer::on_actionCPU_Texture_triggered()
{
   vtkwid-> mapper->SetRequestedRenderMode(vtkSmartVolumeMapper::TextureRenderMode);
  vtkwid->GetRenderWindow()->Render();
}

void VolumeViewer::on_actionSmart_triggered()
{
vtkwid->mapper->SetRequestedRenderModeToDefault();
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
