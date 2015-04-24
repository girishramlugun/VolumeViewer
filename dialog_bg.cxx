#include "dialog_bg.h"
#include "ui_dialog_bg.h"
#include <VolumeViewer.h>
#include <QSpinBox>
#include<iostream>
#include <QStyle>

Dialog_Bg::Dialog_Bg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Bg)
{
    ui->setupUi(this);








}

Dialog_Bg::~Dialog_Bg()
{
    delete ui;
}

void Dialog_Bg::on_bg_col_r_valueChanged(int arg1)
{
    bg_r=ui->bg_col_r->value()/255.0;
canvasupdate();

}



void Dialog_Bg::on_bg_col_g_valueChanged(int arg1)
{
    bg_g=ui->bg_col_g->value()/255.0;
    canvasupdate();
}



void Dialog_Bg::on_bg_col_b_valueChanged(int arg1)
{
    bg_b=ui->bg_col_b->value()/255.0;
    canvasupdate();
}

void Dialog_Bg::canvasupdate()
{
QString r = QString::number(ui->bg_col_r->value());QString g = QString::number(ui->bg_col_g->value());QString b = QString::number(ui->bg_col_b->value());
QString StyleS = "background-color: rgb("+r+","+g+","+b+")";
ui->graphicsView->setStyleSheet(StyleS);
ui->graphicsView->show();

}

void Dialog_Bg::on_reset_bg_clicked()
{
    ui->bg_col_r->setValue(0);
    ui->bg_col_g->setValue(0);
    ui->bg_col_b->setValue(0);
emit sendbgparams(bg_r,bg_g,bg_b);
}



void Dialog_Bg::on_set_bg_clicked()
{
    emit sendbgparams(bg_r,bg_g,bg_b);
}
