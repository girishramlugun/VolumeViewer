#ifndef DIALOG_LIGHT_H
#define DIALOG_LIGHT_H

#include <QDialog>

namespace Ui {
class dialog_light;
}

class dialog_light : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_light(QWidget *parent = 0);
    ~dialog_light();
    double kw,ki,ke,ka,fw,fkf,fe,fa,bw,bkb,be,ba,hw,hkh;
    void updateparams();

signals:
void sendlights(double,double,double,double,double,double,double,double,double,double,double,double,double,double);

private slots:


    void on_ok_lights_accepted();


private:
    Ui::dialog_light *ui;

};

#endif // DIALOG_LIGHT_H
