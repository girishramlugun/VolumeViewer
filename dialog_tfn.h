#ifndef DIALOG_TFN_H
#define DIALOG_TFN_H

#include <QDialog>
#include <QAbstractItemModel>
#include <iostream>
#include<QStandardItemModel>
#include<qrubberband.h>
#include<qcustomplot.h>

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
	void plot();




signals:
    void sendtfn (int);

private slots:
    void on_addrow_clicked();

    void on_delrow_clicked();

	void on_save_clicked();
	
    void on_settfn_clicked();

	void mousePress(QMouseEvent* mevent);

	void mouseMove(QMouseEvent *mevent);

	void mouseRelease(QMouseEvent *mevent);


private:
    Ui::dialog_tfn *ui;
	QRubberBand *rubberBand;
	QPoint origin;
	QCPGraph *pointsR;
	QCPGraph * pointsG;
	QCPGraph * pointsB;
public slots:
     void plothist(QVector<double> freq);

};

#endif // DIALOG_TFN_H
