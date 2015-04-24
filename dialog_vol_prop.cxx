#include "dialog_vol_prop.h"
#include "ui_dialog_vol_prop.h"

dialog_vol_prop::dialog_vol_prop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_vol_prop)
{
    ui->setupUi(this);
}

dialog_vol_prop::~dialog_vol_prop()
{
    delete ui;
}


void dialog_vol_prop::update_dim()
{
    dim_x = ui->dim_x->value();
    dim_y = ui->dim_y->value();
    dim_z = ui->dim_z->value();
}


void dialog_vol_prop::on_set_vol_dim_clicked()
{
	update_dim();
	emit send_dims(dim_x,dim_y,dim_z);
	close();
}


