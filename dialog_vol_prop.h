#ifndef DIALOG_VOL_PROP_H
#define DIALOG_VOL_PROP_H

#include <QDialog>

namespace Ui {
class dialog_vol_prop;
}

class dialog_vol_prop : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_vol_prop(QWidget *parent = 0);
    ~dialog_vol_prop();
    double dim_x,dim_y,dim_z;

private slots:


    void on_set_vol_dim_clicked();
    void update_dim();
signals:

	void send_dims(double, double, double);

private:
    Ui::dialog_vol_prop *ui;

};

#endif // DIALOG_VOL_PROP_H
