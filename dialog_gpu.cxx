#include "dialog_gpu.h"
#include "ui_dialog_gpu.h"

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
