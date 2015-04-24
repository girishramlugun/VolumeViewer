#include "dialog_hessian.h"
#include "ui_dialog_hessian.h"

dialog_hessian::dialog_hessian(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_hessian)
{
    ui->setupUi(this);
}




dialog_hessian::~dialog_hessian()
{
    delete ui;
}


void dialog_hessian::on_okhessian_accepted()
{
	double sig = ui->sigma->value();
	double a1 = ui->alpha1->value();
	double a2 = ui->alpha2->value();
	emit sendhessparams(sig,a1,a2);
}