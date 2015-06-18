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

private:
    Ui::Dialog_gpu *ui;
};

#endif // DIALOG_GPU_H
