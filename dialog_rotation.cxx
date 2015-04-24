#include "dialog_rotation.h"
#include "ui_dialog_rotation.h"
#include <QTimer>
#include<QMessageBox>



dialog_rotation::dialog_rotation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_rotation)
{
    ui->setupUi(this);

    rtimer = new QTimer(this);



}

dialog_rotation::~dialog_rotation()
{
    delete ui;
}





void dialog_rotation::on_generatemovie_clicked()
{
updateparams();
    if (ui->generatemovie->isChecked()){

    QString moviename = QFileDialog::getSaveFileName(this,
    tr("Save Movie"), "",
    tr("(*.avi);;All Files (*)"));
    movname = moviename.toStdString();}
    updateparams();
}


void dialog_rotation::updateparams()
{
    if(ui->x->isChecked())
    {rotmat[0]=1;rotmat[1]=0;rotmat[2]=0;}
    else if(ui->Y->isChecked())
    {rotmat[0]=0;rotmat[1]=1;rotmat[2]=0;}
    else if (ui->Z->isChecked())
    {rotmat[0]=0;rotmat[1]=0;rotmat[2]=1;}
    rotang = ui->angle->value();

if (ui->generatemovie->isChecked())
{
    wrmov=2;
}

else
{
    wrmov=3;
}



}


void dialog_rotation::on_startrot_clicked()
{

if (rotang=0){
    QMessageBox::critical(0, QObject::tr("Error"), "Please add a rotation angle");
}
updateparams();
emit sendwrmovstat(wrmov);


}



