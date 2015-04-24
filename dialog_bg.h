#ifndef DIALOG_BG_H
#define DIALOG_BG_H

#include <QDialog>

namespace Ui {
class Dialog_Bg;
}

class Dialog_Bg : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Bg(QWidget *parent = 0);
    ~Dialog_Bg();




signals:
    void sendbgparams(double,double,double);



private slots:
    void on_reset_bg_clicked();
    void on_set_bg_clicked();





    void on_bg_col_r_valueChanged(int arg1);

    void on_bg_col_g_valueChanged(int arg1);

    void on_bg_col_b_valueChanged(int arg1);


    void canvasupdate();

private:
    Ui::Dialog_Bg *ui;

    double bg_r,bg_b,bg_g;

};

#endif // DIALOG_BG_H
