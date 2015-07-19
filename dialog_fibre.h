#ifndef DIALOG_FIBRE_H
#define DIALOG_FIBRE_H

#include <QDialog>

namespace Ui {
class Dialog_Fibre;
}

class Dialog_Fibre : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Fibre(QWidget *parent = 0);
    ~Dialog_Fibre();

signals:
	void sendfibreparams(int,int);

	private slots:
	void on_okfibre_accepted();

private:
    Ui::Dialog_Fibre *ui;
};

#endif // DIALOG_FIBRE_H
