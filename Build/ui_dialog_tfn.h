/********************************************************************************
** Form generated from reading UI file 'dialog_tfn.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_TFN_H
#define UI_DIALOG_TFN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_dialog_tfn
{
public:
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addrow;
    QPushButton *delrow;
    QPushButton *settfn;
    QPushButton *save;
    QPushButton *resettfn;
    QPushButton *canceltfn;
    QCustomPlot *Plot;
    QLabel *label;

    void setupUi(QDialog *dialog_tfn)
    {
        if (dialog_tfn->objectName().isEmpty())
            dialog_tfn->setObjectName(QStringLiteral("dialog_tfn"));
        dialog_tfn->resize(642, 765);
        tableWidget = new QTableWidget(dialog_tfn);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 431, 181));
        layoutWidget = new QWidget(dialog_tfn);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(450, 20, 79, 182));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addrow = new QPushButton(layoutWidget);
        addrow->setObjectName(QStringLiteral("addrow"));

        verticalLayout->addWidget(addrow);

        delrow = new QPushButton(layoutWidget);
        delrow->setObjectName(QStringLiteral("delrow"));

        verticalLayout->addWidget(delrow);

        settfn = new QPushButton(layoutWidget);
        settfn->setObjectName(QStringLiteral("settfn"));

        verticalLayout->addWidget(settfn);

        save = new QPushButton(layoutWidget);
        save->setObjectName(QStringLiteral("save"));

        verticalLayout->addWidget(save);

        resettfn = new QPushButton(layoutWidget);
        resettfn->setObjectName(QStringLiteral("resettfn"));

        verticalLayout->addWidget(resettfn);

        canceltfn = new QPushButton(layoutWidget);
        canceltfn->setObjectName(QStringLiteral("canceltfn"));

        verticalLayout->addWidget(canceltfn);

        Plot = new QCustomPlot(dialog_tfn);
        Plot->setObjectName(QStringLiteral("Plot"));
        Plot->setGeometry(QRect(10, 220, 621, 531));
        label = new QLabel(dialog_tfn);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(550, 150, 71, 31));

        retranslateUi(dialog_tfn);

        QMetaObject::connectSlotsByName(dialog_tfn);
    } // setupUi

    void retranslateUi(QDialog *dialog_tfn)
    {
        dialog_tfn->setWindowTitle(QApplication::translate("dialog_tfn", "Set Transfer Function", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("dialog_tfn", "Intensity", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("dialog_tfn", "R", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("dialog_tfn", "G", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("dialog_tfn", "B", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("dialog_tfn", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("dialog_tfn", "2", nullptr));
        addrow->setText(QApplication::translate("dialog_tfn", "Add Row", nullptr));
        delrow->setText(QApplication::translate("dialog_tfn", "Delete Row", nullptr));
        settfn->setText(QApplication::translate("dialog_tfn", "Set", nullptr));
        save->setText(QApplication::translate("dialog_tfn", "Save", nullptr));
        resettfn->setText(QApplication::translate("dialog_tfn", "Reset", nullptr));
        canceltfn->setText(QApplication::translate("dialog_tfn", "Cancel", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dialog_tfn: public Ui_dialog_tfn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_TFN_H
