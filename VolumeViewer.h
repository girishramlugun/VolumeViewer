#ifndef VolumeViewer_H
#define VolumeViewer_H

#include <vtkMultiProcessController.h>

#include <vtkSmartPointer.h>

#include <QMainWindow>

#include "ui_VolumeViewer.h"

#include <dialog_bg.h>

#include <dialog_tfn.h>

#include <dialog_vol_prop.h>

#include <dialog_light.h>

#include <dialog_opacity.h>

#include <dialog_rotation.h>

#include <dialog_color.h>

#include <vtkwidget.h>

#include <vtkBoxWidget2.h>

#include <dialog_hessian.h>

#include<dialog_gpu.h>

#include<dialog_threshold.h>

#include <dialog_fibre.h>



using namespace std;


class Ui_VolumeViewer;

class VolumeViewer : public QMainWindow
{
  Q_OBJECT
public:

  // Constructor/Destructor
  VolumeViewer();
  ~VolumeViewer() {}
  Dialog_Bg *diabg;
  dialog_tfn *diatfn;
  dialog_vol_prop *diavolprop;
  dialog_light *dialight;
  dialog_opacity *diaopa;
  dialog_rotation *diarotat;
  dialog_color *diacol;
  dialog_hessian *diahessian;
  Dialog_gpu *diagpu;
  Dialog_threshold *diathresh;
  Dialog_Fibre *diafibre;
  vtkSmartPointer <vtkBoxWidget2> box;
  vtkwidget *vtkwid;
QSettings *appsettings;


  void savevol(string);
  void openvol(string);
  void openimg(string);
  void opentimeseq(string);


signals:
 
 void vramsize(int);
 void gpinf(int);

public slots:

  virtual void slotExit();
  void rot();
  void setvolcol(int);
  void updateopacity(int,bool);
  void rmovstat(int);
  void getgpuinfo(int vram);
  void process(vtkMultiProcessController* controller, void* vtkNotUsed(arg));



private slots:

  void on_clear_clicked();
  void on_actionAxes_triggered();
  void on_actionGPU_Texture_triggered();
  void on_actionRay_Cast_triggered();
  void on_actionOpen_triggered();
  void on_actionExit_2_triggered();
  void on_actionBackground_triggered();
  void on_actionCustom_triggered();
  void on_actionImage_triggered();
  void on_actionGrey_triggered();
  void on_actionHessian_triggered();
  void on_actionFibrosis_triggered();
  void on_actionAdd_triggered();
  void on_actionR_to_B_triggered();
  void on_actionGreen_triggered();
  void on_actionB_to_R_triggered();
  void on_actionOptions_triggered();
  void on_actionSave_Screenshot_triggered();

  void on_actionRotate_triggered();
  void on_actionImage_Sequence_triggered();
  void on_actionClip_triggered();

  void on_actionDimensions_triggered();

  void on_actionLights_triggered();

  void on_actionAbout_triggered();

  void on_actionOpacity_triggered();

  void on_actionSlice_triggered();

  void on_actionSave_Volume_triggered();

  void on_actionColor_triggered();

  void on_actionIsosurface_triggered();

  void on_actionNearest_triggered();

  void on_actionLinear_triggered();

  void on_actionCubic_triggered();



  void on_actionLoadLUT_triggered();

  void on_actionAnaglyph_triggered();

  void on_actionRed_Blue_triggered();

  void on_actionInterlaced_triggered();

  void on_actionCrop_triggered();

  void doHessian(double, double, double);

  void on_actionThreshold_triggered();

  void setthresh(double , double );

  void generatefibres(string,int,int);

  void setfibres(int, int);

  void on_actionHelp_Topics_triggered();

  void getfileprefix(QString);

  void on_actionReslice_triggered();

  void on_actionTime_Sequence_triggered();

  
  
private:

	
Ui_VolumeViewer *ui;


};

#endif
