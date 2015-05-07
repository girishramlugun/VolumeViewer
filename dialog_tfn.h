#ifndef DIALOG_TFN_H
#define DIALOG_TFN_H

#include <QDialog>
#include <QAbstractItemModel>
#include <iostream>
#include<QStandardItemModel>


namespace Ui {
class dialog_tfn;
}

class dialog_tfn : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_tfn(QWidget *parent = 0);
    ~dialog_tfn();
    QAbstractItemModel* model;
    int rowcnt;
	QStandardItemModel*mod;
	void loadlut(QStringList);
signals:
    void sendtfn (int);

private slots:
    void on_addrow_clicked();

    void on_delrow_clicked();

	void on_save_clicked();

	

    void on_settfn_clicked();

private:
    Ui::dialog_tfn *ui;


};

#endif // DIALOG_TFN_H
