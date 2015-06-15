#include "dialog_opacity.h"
#include "ui_dialog_opacity.h"

dialog_opacity::dialog_opacity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_opacity)
{
	ui->setupUi(this);
	// give the axes some labels:
	ui->opaplot->xAxis->setLabel("Intensity");
	ui->opaplot->yAxis->setLabel("Opacity");
	// set axes ranges, so we see all data:
	ui->opaplot->xAxis->setRange(0, 255);
	ui->opaplot->yAxis->setRange(0, 1);
	ui->opaplot->setBackground(Qt::black);
	ui->opaplot->xAxis->setLabelColor(Qt::white);
	ui->opaplot->yAxis->setLabelColor(Qt::white);
	ui->opaplot->yAxis->setTickLabelColor(Qt::white);
	ui->opaplot->xAxis->setTickLabelColor(Qt::white);
	ui->opaplot->xAxis->grid()->setVisible(false);
	ui->opaplot->yAxis->grid()->setVisible(false);
	ui->opaplot->xAxis->setTickPen(QPen(Qt::white, 1));
	ui->opaplot->yAxis->setTickPen(QPen(Qt::white, 1));
	ui->opaplot->xAxis->setSubTickPen(QPen(Qt::white, 1));
	ui->opaplot->yAxis->setSubTickPen(QPen(Qt::white, 1));
	ui->opaplot->xAxis->setBasePen(QPen(Qt::white, 1));
	ui->opaplot->yAxis->setBasePen(QPen(Qt::white, 1));
	ui->opaplot->yAxis->grid()->setVisible(false);
}

dialog_opacity::~dialog_opacity()
{
    delete ui;
}

void dialog_opacity::on_Addrow_clicked()
{
    ui->opatable->insertRow(ui->opatable->rowCount());
}

void dialog_opacity::on_Removerow_clicked()
{
    ui->opatable->removeRow(ui->opatable->currentRow());
}

void dialog_opacity::on_bboxopa_accepted()
{

}

void dialog_opacity::on_SetOpa_clicked()
{
	bool col;
	
	if (ui->ColChan->isChecked())
	{
		col = true;
		modelopa = ui->opatable->model();
		modelopa2 = ui->opatable_2->model();
		modelopa3 = ui->opatable_3->model();
	}
		
	else if (!ui->ColChan->isChecked())
	{
		col = false;
		modelopa = ui->opatable->model();
	}
	
	rowcntopa = ui->opatable->rowCount();

	emit sendopa(rowcntopa,col);
	plotopa();
}

void dialog_opacity::plotopa()
{
	if (!ui->opatable_2->isEnabled())
	{
		ui->opaplot->clearGraphs();
		modelopa = ui->opatable->model();
		QModelIndex index;
		QVector<double> In(rowcntopa), Opa(rowcntopa);
		double val[2];
		for (int r = 0; r < ui->opatable->rowCount(); ++r)

		{


			for (int j = 0; j < 2; j++)
			{
				index = modelopa->index(r, j);
				val[j] = modelopa->data(index).toDouble();

			}
			In[r] = val[0]; Opa[r] = val[1];

		}

		QCPGraph *pointsOpa = new QCPGraph(ui->opaplot->xAxis, ui->opaplot->yAxis);
		pointsOpa->setData(In, Opa);
		pointsOpa->setLineStyle(QCPGraph::lsLine);
		pointsOpa->setPen(QPen(QBrush(Qt::yellow), 1));
		ui->opaplot->addPlottable(pointsOpa);
		ui->opaplot->replot();
	}

	else if (ui->opatable_2->isEnabled() && ui->opatable_3->isEnabled())
	{
		ui->opaplot->clearGraphs();
		modelopa = ui->opatable->model();
		modelopa2 = ui->opatable_2->model();
		modelopa3 = ui->opatable_3->model();
		QModelIndex index; 
		QVector<double> In(rowcntopa), Opa(rowcntopa), In1(rowcntopa), Opa1(rowcntopa), In2(rowcntopa), Opa2(rowcntopa);
		double val[2];
		for (int r = 0; r < ui->opatable->rowCount(); ++r)

		{


			for (int j = 0; j < 2; j++)
			{
				index = modelopa->index(r, j);
				val[j] = modelopa->data(index).toDouble();

			}
			In[r] = val[0]; Opa[r] = val[1];

		}

		for (int r = 0; r < ui->opatable_2->rowCount(); ++r)

		{


			for (int j = 0; j < 2; j++)
			{
				index = modelopa2->index(r, j);
				val[j] = modelopa2->data(index).toDouble();

			}
			In1[r] = val[0]; Opa1[r] = val[1];

		}

		for (int r = 0; r < ui->opatable_3->rowCount(); ++r)

		{


			for (int j = 0; j < 2; j++)
			{
				index = modelopa3->index(r, j);
				val[j] = modelopa3->data(index).toDouble();

			}
			In2[r] = val[0]; Opa2[r] = val[1];

		}

		QCPGraph *pointsOpa = new QCPGraph(ui->opaplot->xAxis, ui->opaplot->yAxis);
		QCPGraph *pointsOpa1 = new QCPGraph(ui->opaplot->xAxis, ui->opaplot->yAxis);
		QCPGraph *pointsOpa2 = new QCPGraph(ui->opaplot->xAxis, ui->opaplot->yAxis);
		pointsOpa->setData(In, Opa);
		pointsOpa1->setData(In1, Opa1);
		pointsOpa2->setData(In2, Opa2);

		pointsOpa->setLineStyle(QCPGraph::lsLine);
		pointsOpa->setPen(QPen(QBrush(Qt::red), 1));

		pointsOpa1->setLineStyle(QCPGraph::lsLine);
		pointsOpa1->setPen(QPen(QBrush(Qt::green), 1));

		pointsOpa2->setLineStyle(QCPGraph::lsLine);
		pointsOpa2->setPen(QPen(QBrush(Qt::blue), 1));

		ui->opaplot->addPlottable(pointsOpa);
		ui->opaplot->replot();

	}
}


void dialog_opacity::on_ColChan_toggled(bool t)
{
	
		ui->opatable_2->setEnabled(t);
		ui->opatable_3->setEnabled(t);

	
}