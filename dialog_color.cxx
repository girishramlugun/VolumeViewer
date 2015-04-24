#include "dialog_color.h"
#include "ui_dialog_color.h"
#include<math.h>

dialog_color::dialog_color(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_color)
{
    ui->setupUi(this);
	ui->vc->setNum(ui->volcol->value() / float(100));
	ui->wc->setNum(ui->wincol->value() / float(100));
	connect(ui->volcol, SIGNAL(valueChanged(int)), this, SLOT(emitvolcol(int)));
	connect(ui->wincol, SIGNAL(valueChanged(int)), this, SLOT(emitwincol(int)));
}

dialog_color::~dialog_color()
{
    delete ui;
}


void dialog_color::emitvolcol(int vcol)
{
	double vc = vcol / float(100);
	ui->vc->setNum(vc);
	emit volcol(vc);
}

void dialog_color::emitwincol(int wcol)
{
	double wc = wcol / float(100);
	ui->wc->setNum(wc);
	emit wincol(wc);
}