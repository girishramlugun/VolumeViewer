#include "dialog_tfn.h"
#include "ui_dialog_tfn.h"
#include <vtkUnsignedCharArray.h>
#include <vector>



//This a dialog for adding a custom transfer function

dialog_tfn::dialog_tfn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_tfn)
{
    ui->setupUi(this);



}

dialog_tfn::~dialog_tfn()
{
    delete ui;
}

void dialog_tfn::on_addrow_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void dialog_tfn::on_delrow_clicked()
{

    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}


void dialog_tfn::on_settfn_clicked()
{
    rowcnt = ui->tableWidget->rowCount();
    model = ui->tableWidget->model();
    emit sendtfn(rowcnt);


}
