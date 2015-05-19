#include "dialog_tfn.h"
#include "ui_dialog_tfn.h"
#include <vtkUnsignedCharArray.h>
#include <vector>
#include<QFile>
#include<QTextStream>
#include<QStringList>
#include<QModelIndex>
#include<QFileDialog>
#include<QTableWidgetItem>


//This a dialog for adding a custom transfer function

dialog_tfn::dialog_tfn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_tfn)
{
    ui->setupUi(this);



}

dialog_tfn::~dialog_tfn()
{
    delete ui;
}

void dialog_tfn::on_addrow_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void dialog_tfn::on_delrow_clicked()
{

    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}


void dialog_tfn::on_settfn_clicked()
{
    rowcnt = ui->tableWidget->rowCount();
    model = ui->tableWidget->model();
    emit sendtfn(rowcnt);


}


void dialog_tfn::on_save_clicked()
{
	QString fileName = QFileDialog::getSaveFileName(this,
		tr("Save Transfer Function"), "",
		tr("(*.csv)"));


	model = ui->tableWidget->model();
	QModelIndex index;
	QFile f(fileName);
		if (f.open(QIODevice::WriteOnly)){
			QTextStream ts(&f);  

			//QDataStream ts(&f);
			
			double val[4]; 
			for (int r = 0; r < ui->tableWidget->rowCount(); ++r){
				
				
				for (int j = 0; j<4; j++)
				{
					index = model->index(r, j);
					 val[j] = model->data( index ).toDouble();
				}
				ts << val[0]<<", "<< val[1]<<" ,"<< val[2]<<", "<< val[3]<<"\n";
				
			}
			f.close();
			
		}
}

void dialog_tfn::loadlut(QStringList LUTList)
{
	int row = 0;
	ui->tableWidget->setColumnCount(LUTList.size());
	ui->tableWidget->insertRow(row);
	for (int x = 0; x < 4; x++){
		QTableWidgetItem *test = new QTableWidgetItem(LUTList.at(x));
		ui->tableWidget->setItem(row, x, test);
		row++;
	}
	this->show();

}