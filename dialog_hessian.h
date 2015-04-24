#ifndef DIALOG_HESSIAN_H
#define DIALOG_HESSIAN_H

#include <QDialog>

using namespace std;

namespace Ui {
class dialog_hessian;
}

class dialog_hessian : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_hessian(QWidget *parent = 0);
    ~dialog_hessian();

signals:
	void sendhessparams(double,double,double);

private slots:
	void on_okhessian_accepted();


private:
    Ui::dialog_hessian *ui;
};

#endif // DIALOG_HESSIAN_H
