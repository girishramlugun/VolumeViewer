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
	rowcntopa = ui->opatable->rowCount();
	modelopa = ui->opatable->model();
	emit sendopa(rowcntopa);
	plotopa();
}

void dialog_opacity::plotopa()
{
	ui->opaplot->clearGraphs();
	modelopa = ui->opatable->model();
	QModelIndex index;
	QVector<double> In(rowcntopa), Opa(rowcntopa);
	double val[2];
	for (int r = 0; r < ui->opatable->rowCount(); ++r)

	{


		for (int j = 0; j<2; j++)
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

