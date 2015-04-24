#include "dialog_light.h"
#include "ui_dialog_light.h"

dialog_light::dialog_light(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_light)
{
    ui->setupUi(this);
}

dialog_light::~dialog_light()
{
    delete ui;
}


void dialog_light::on_ok_lights_accepted()
{

   updateparams();
    emit sendlights(kw,ki,ke,ka,fw,fkf,fe,fa,bw,bkb,be,ba,hw,hkh);



}

void dialog_light::updateparams()
{
    kw=ui->keywarmth->value();
    ki=ui->keyint->value();
    ke=ui->keyele->value();
    ka=ui->keyazi->value();

    fw=ui->fillwarm->value();
    fkf=ui->fillkf->value();
    fe=ui->fillele->value();
    fa=ui->fillazi->value();

    bw=ui->backwarm->value();
    bkb=ui->backkb->value();
    be=ui->backele->value();
    ba=ui->backazi->value();

    hw=ui->headwarm->value();
    hkh=ui->headkh->value();
}
