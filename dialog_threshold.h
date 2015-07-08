#ifndef DIALOG_THRESHOLD_H
#define DIALOG_THRESHOLD_H

#include <QDialog>

namespace Ui {
class Dialog_threshold;
}

class Dialog_threshold : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_threshold(QWidget *parent = 0);
    ~Dialog_threshold();

private:
    Ui::Dialog_threshold *ui;

signals:
	void sendthreshold(double,double);

private slots:
	void on_okthreshold_accepted();
};

#endif // DIALOG_THRESHOLD_H
