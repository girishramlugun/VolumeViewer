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



void Dialog_gpu::setvram(int vramval)
{
    ui->vram_val->setCurrentIndex((vramval/1024)-1);
}
