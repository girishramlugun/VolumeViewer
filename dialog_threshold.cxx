#include "dialog_threshold.h"
#include "ui_dialog_threshold.h"

Dialog_threshold::Dialog_threshold(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_threshold)
{
    ui->setupUi(this);
}

Dialog_threshold::~Dialog_threshold()
{
    delete ui;
}


void Dialog_threshold::on_okthreshold_accepted()
{
	emit sendthreshold(ui->lthreshold->value(),ui->uthreshold->value());
}