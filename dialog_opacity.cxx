#include "dialog_opacity.h"
#include "ui_dialog_opacity.h"

dialog_opacity::dialog_opacity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_opacity)
{
    ui->setupUi(this);
}

dialog_opacity::~dialog_opacity()
{
    delete ui;
}

void dialog_opacity::on_Addrow_clicked()
{
    ui->opatable->insertRow(ui->opatable->rowCount());
}

void dialog_opacity::on_Removerow_clicked()
{
    ui->opatable->removeRow(ui->opatable->currentRow());
}

void dialog_opacity::on_bboxopa_accepted()
{
    rowcntopa = ui->opatable->rowCount();
    modelopa = ui->opatable->model();
    emit sendopa(rowcntopa);
}




