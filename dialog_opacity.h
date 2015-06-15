#ifndef DIALOG_OPACITY_H
#define DIALOG_OPACITY_H

#include <QDialog>
#include <QAbstractItemModel>

namespace Ui {
class dialog_opacity;
}

class dialog_opacity : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_opacity(QWidget *parent = 0);
    ~dialog_opacity();
	QAbstractItemModel* modelopa;
	QAbstractItemModel* modelopa2;
	QAbstractItemModel* modelopa3;
	int rowcntopa; 

signals:
    void sendopa(int,bool);

private slots:
    void on_Addrow_clicked();

    void on_Removerow_clicked();

    void on_bboxopa_accepted();

	void plotopa();

	void on_SetOpa_clicked();

	void on_ColChan_toggled(bool);


private:
    Ui::dialog_opacity *ui;

};

#endif // DIALOG_OPACITY_H
