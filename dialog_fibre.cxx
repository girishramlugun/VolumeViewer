#include "dialog_fibre.h"
#include "ui_dialog_fibre.h"

Dialog_Fibre::Dialog_Fibre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Fibre)
{
    ui->setupUi(this);
}

Dialog_Fibre::~Dialog_Fibre()
{
    delete ui;
}


void Dialog_Fibre::on_okfibre_accepted()
{
	emit sendfibreparams(ui->fiblen->value(), ui->Skip->value());
}