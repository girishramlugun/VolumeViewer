#ifndef DIALOG_ROTATION_H
#define DIALOG_ROTATION_H

#include <QDialog>
#include <QString>
#include <QFileDialog>
#include <vtkAVIWriter.h>
#include<vtkWindowToImageFilter.h>
#include<QTimer>

using namespace std;




namespace Ui {
class dialog_rotation;
}

class dialog_rotation : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_rotation(QWidget *parent = 0);
    ~dialog_rotation();
    string movname;
    double rotmat[3];
QTimer* rtimer;
double rotang;
int wrmov;
void updateparams();



signals:

void sendwrmovstat(int);

public slots:



private slots:

    void on_generatemovie_clicked();

    void on_startrot_clicked();

    void on_stoprot_clicked();



private:
    Ui::dialog_rotation *ui;
};

#endif // DIALOG_ROTATION_H
