#ifndef DIALOG_GPU_H
#define DIALOG_GPU_H

#include <QDialog>

namespace Ui {
class Dialog_gpu;
}

class Dialog_gpu : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_gpu(QWidget *parent = 0);
    ~Dialog_gpu();

private slots:
    void on_buttonBox_accepted();

signals:


private:
    Ui::Dialog_gpu *ui;

public slots:
    void setvram(int vramval);


};

#endif // DIALOG_GPU_H
