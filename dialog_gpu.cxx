#include "dialog_gpu.h"
#include "ui_dialog_gpu.h"
#include <iostream>
#include <fstream>

using namespace std;

Dialog_gpu::Dialog_gpu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_gpu)
{
    ui->setupUi(this);
	string line; int vramval;
    ifstream vram ("vram.info");
    if (vram.is_open())
    {
      while ( getline (vram,line) )
      {
		  vramval = atoi(line.c_str());
		  ui->vram_val->setCurrentIndex((vramval/1024)-1);
		  emit gpinf(vramval);

      }
      vram.close();
    }
}

Dialog_gpu::~Dialog_gpu()
{
    delete ui;
}



void Dialog_gpu::on_buttonBox_accepted()
{

    ofstream myfile;
    myfile.open ("vram.info");
    myfile << (ui->vram_val->currentIndex()+1)*1024;
    myfile.close();

}
