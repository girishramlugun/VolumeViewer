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
    // give the axes some labels:
    ui->Plot->xAxis->setLabel("Intensity");
    ui->Plot->yAxis->setLabel("Value");
    // set axes ranges, so we see all data:
    ui->Plot->xAxis->setRange(0, 255);
    ui->Plot->yAxis->setRange(0, 1);
	ui->Plot->setBackground(Qt::black);
	ui->Plot->xAxis->setLabelColor(Qt::white);
	ui->Plot->yAxis->setLabelColor(Qt::white);
	ui->Plot->yAxis->setTickLabelColor(Qt::white);
	ui->Plot->xAxis->setTickLabelColor(Qt::white);
	ui->Plot->xAxis->grid()->setVisible(false);
	ui->Plot->yAxis->grid()->setVisible(false);
	ui->Plot->xAxis->setTickPen(QPen(Qt::white, 1));
	ui->Plot->yAxis->setTickPen(QPen(Qt::white, 1));
	ui->Plot->xAxis->setSubTickPen(QPen(Qt::white, 1));
	ui->Plot->yAxis->setSubTickPen(QPen(Qt::white, 1));
	ui->Plot->xAxis->setBasePen(QPen(Qt::white, 1));
	ui->Plot->yAxis->setBasePen(QPen(Qt::white, 1));
	ui->Plot->yAxis->grid()->setVisible(false);

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
	plot();
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

void dialog_tfn::plot()
{
	
	ui->Plot->clearGraphs(); 
	model = ui->tableWidget->model();
	QModelIndex index;
	QVector<double> In(rowcnt), R(rowcnt),G(rowcnt), B(rowcnt);
	double val[4];
	for (int r = 0; r < ui->tableWidget->rowCount(); ++r)
	
	{


		for (int j = 0; j<4; j++)
		{
			index = model->index(r, j);
			val[j] = model->data(index).toDouble();
			
		}
		In[r] = val[0]; R[r] = val[1]; G[r] = val[2]; B[r] = val[3];

	}
	

	QCPGraph *pointsR = new QCPGraph(ui->Plot->xAxis, ui->Plot->yAxis);
	QCPGraph *pointsG = new QCPGraph(ui->Plot->xAxis, ui->Plot->yAxis);
	QCPGraph *pointsB = new QCPGraph(ui->Plot->xAxis, ui->Plot->yAxis);

	pointsR->setData(In, R);
	pointsR->setLineStyle(QCPGraph::lsLine);
	pointsR->setPen(QPen(QBrush(Qt::red), 1));
	ui->Plot->addPlottable(pointsR);

	pointsG->setData(In, G);
	pointsG->setLineStyle(QCPGraph::lsLine);
	pointsG->setPen(QPen(QBrush(Qt::green), 1));
	ui->Plot->addPlottable(pointsG);

	pointsB->setData(In, B);
	pointsB->setLineStyle(QCPGraph::lsLine);
	pointsB->setPen(QPen(QBrush(Qt::blue), 1));
	ui->Plot->addPlottable(pointsB);
	/*
	ui->Plot->addGraph();
	
	ui->Plot->graph(0)->setPen(QPen(Qt::lightGray));

	ui->Plot->graph(0)->setData(In, Va);
	ui->Plot->addGraph();
	ui->Plot->graph(1)->setPen(QPen(Qt::yellow));

	ui->Plot->graph(1)->setData(In, Op);
	*/
	// set axes ranges, so we see all data:
	//ui->Plot->graph(0)->rescaleAxes();
	ui->Plot->replot();
}


void dialog_tfn::loadlut(QStringList LUTList)
{
	ui->tableWidget->clearContents();
	int row = 0;
	int rc = LUTList.size() / 4;
	ui->tableWidget->setRowCount(rc);
	ui->tableWidget->setColumnCount(4);
	int x = 0;
	for (int r = 0; r < rc; r++){
		for (int c = 0; c < 4; c++)
		{
			QTableWidgetItem *test = new QTableWidgetItem(LUTList.at(x));
			ui->tableWidget->setItem(r, c, test);
			x++;
		}
	}
	rowcnt = ui->tableWidget->rowCount();
	plot();
	this->show();
}

void dialog_tfn::plothist(QVector<double> freq)
{
	QVector<double> ind(256);
	for (int j = 0; j < 256; j++)
	{
		ind[j] = j;
	}
	QCPBars *hist = new QCPBars(ui->Plot->xAxis, ui->Plot->yAxis);
	hist->setData(ind, freq);
	hist->setPen(QPen(QBrush(Qt::gray), 1));
	//hist->setBrush(QBrush(Qt::gray), 1);
	ui->Plot->addPlottable(hist);
	ui->Plot->xAxis->setRange(0, 255);
	ui->Plot->yAxis->setRange(0, 300000);
	ui->Plot->replot();
}