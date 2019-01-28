/********************************************************************************
** Form generated from reading UI file 'dialog_opacity.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_OPACITY_H
#define UI_DIALOG_OPACITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_dialog_opacity
{
public:
    QTableWidget *opatable;
    QCustomPlot *opaplot;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *Addrow;
    QPushButton *Removerow;
    QDialogButtonBox *bboxopa;
    QRadioButton *ColChan;
    QPushButton *SetOpa;
    QTableWidget *opatable_2;
    QTableWidget *opatable_3;
    QLabel *label;

    void setupUi(QDialog *dialog_opacity)
    {
        if (dialog_opacity->objectName().isEmpty())
            dialog_opacity->setObjectName(QStringLiteral("dialog_opacity"));
        dialog_opacity->resize(1013, 822);
        opatable = new QTableWidget(dialog_opacity);
        if (opatable->columnCount() < 2)
            opatable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        opatable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        opatable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (opatable->rowCount() < 2)
            opatable->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        opatable->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        opatable->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        opatable->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        opatable->setItem(0, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        opatable->setItem(1, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        opatable->setItem(1, 1, __qtablewidgetitem7);
        opatable->setObjectName(QStringLiteral("opatable"));
        opatable->setGeometry(QRect(10, 30, 221, 151));
        opatable->setAutoScrollMargin(16);
        opaplot = new QCustomPlot(dialog_opacity);
        opaplot->setObjectName(QStringLiteral("opaplot"));
        opaplot->setGeometry(QRect(10, 200, 881, 541));
        layoutWidget = new QWidget(dialog_opacity);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(730, 30, 164, 146));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Addrow = new QPushButton(layoutWidget);
        Addrow->setObjectName(QStringLiteral("Addrow"));

        verticalLayout->addWidget(Addrow);

        Removerow = new QPushButton(layoutWidget);
        Removerow->setObjectName(QStringLiteral("Removerow"));

        verticalLayout->addWidget(Removerow);

        bboxopa = new QDialogButtonBox(layoutWidget);
        bboxopa->setObjectName(QStringLiteral("bboxopa"));
        bboxopa->setOrientation(Qt::Horizontal);
        bboxopa->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(bboxopa);


        verticalLayout_2->addLayout(verticalLayout);

        ColChan = new QRadioButton(layoutWidget);
        ColChan->setObjectName(QStringLiteral("ColChan"));

        verticalLayout_2->addWidget(ColChan);

        SetOpa = new QPushButton(layoutWidget);
        SetOpa->setObjectName(QStringLiteral("SetOpa"));

        verticalLayout_2->addWidget(SetOpa);

        opatable_2 = new QTableWidget(dialog_opacity);
        if (opatable_2->columnCount() < 2)
            opatable_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        opatable_2->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        opatable_2->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        if (opatable_2->rowCount() < 2)
            opatable_2->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        opatable_2->setVerticalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        opatable_2->setVerticalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        opatable_2->setItem(0, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        opatable_2->setItem(0, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        opatable_2->setItem(1, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        opatable_2->setItem(1, 1, __qtablewidgetitem15);
        opatable_2->setObjectName(QStringLiteral("opatable_2"));
        opatable_2->setEnabled(false);
        opatable_2->setGeometry(QRect(240, 30, 221, 151));
        opatable_2->setAutoScrollMargin(16);
        opatable_3 = new QTableWidget(dialog_opacity);
        if (opatable_3->columnCount() < 2)
            opatable_3->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        opatable_3->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        opatable_3->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        if (opatable_3->rowCount() < 2)
            opatable_3->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        opatable_3->setVerticalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        opatable_3->setVerticalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        opatable_3->setItem(0, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        opatable_3->setItem(0, 1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        opatable_3->setItem(1, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        opatable_3->setItem(1, 1, __qtablewidgetitem23);
        opatable_3->setObjectName(QStringLiteral("opatable_3"));
        opatable_3->setEnabled(false);
        opatable_3->setGeometry(QRect(470, 30, 221, 151));
        opatable_3->setAutoScrollMargin(16);
        label = new QLabel(dialog_opacity);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 10, 521, 16));

        retranslateUi(dialog_opacity);
        QObject::connect(bboxopa, SIGNAL(accepted()), dialog_opacity, SLOT(accept()));
        QObject::connect(bboxopa, SIGNAL(rejected()), dialog_opacity, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialog_opacity);
    } // setupUi

    void retranslateUi(QDialog *dialog_opacity)
    {
        dialog_opacity->setWindowTitle(QApplication::translate("dialog_opacity", "OPacity Function", nullptr));
        QTableWidgetItem *___qtablewidgetitem = opatable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("dialog_opacity", "Intensity", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = opatable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("dialog_opacity", "Opacity", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = opatable->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("dialog_opacity", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = opatable->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("dialog_opacity", "1", nullptr));

        const bool __sortingEnabled = opatable->isSortingEnabled();
        opatable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = opatable->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("dialog_opacity", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = opatable->item(0, 1);
        ___qtablewidgetitem5->setText(QApplication::translate("dialog_opacity", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = opatable->item(1, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("dialog_opacity", "255", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = opatable->item(1, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("dialog_opacity", "1", nullptr));
        opatable->setSortingEnabled(__sortingEnabled);

        Addrow->setText(QApplication::translate("dialog_opacity", "Add Row", nullptr));
        Removerow->setText(QApplication::translate("dialog_opacity", "Remove Row", nullptr));
        ColChan->setText(QApplication::translate("dialog_opacity", "Colour Channels", nullptr));
        SetOpa->setText(QApplication::translate("dialog_opacity", "Set", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = opatable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("dialog_opacity", "Intensity", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = opatable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("dialog_opacity", "Opacity", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = opatable_2->verticalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("dialog_opacity", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = opatable_2->verticalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("dialog_opacity", "1", nullptr));

        const bool __sortingEnabled1 = opatable_2->isSortingEnabled();
        opatable_2->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem12 = opatable_2->item(0, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("dialog_opacity", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = opatable_2->item(0, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("dialog_opacity", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = opatable_2->item(1, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("dialog_opacity", "255", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = opatable_2->item(1, 1);
        ___qtablewidgetitem15->setText(QApplication::translate("dialog_opacity", "1", nullptr));
        opatable_2->setSortingEnabled(__sortingEnabled1);

        QTableWidgetItem *___qtablewidgetitem16 = opatable_3->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("dialog_opacity", "Intensity", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = opatable_3->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("dialog_opacity", "Opacity", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = opatable_3->verticalHeaderItem(0);
        ___qtablewidgetitem18->setText(QApplication::translate("dialog_opacity", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = opatable_3->verticalHeaderItem(1);
        ___qtablewidgetitem19->setText(QApplication::translate("dialog_opacity", "1", nullptr));

        const bool __sortingEnabled2 = opatable_3->isSortingEnabled();
        opatable_3->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem20 = opatable_3->item(0, 0);
        ___qtablewidgetitem20->setText(QApplication::translate("dialog_opacity", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = opatable_3->item(0, 1);
        ___qtablewidgetitem21->setText(QApplication::translate("dialog_opacity", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = opatable_3->item(1, 0);
        ___qtablewidgetitem22->setText(QApplication::translate("dialog_opacity", "255", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = opatable_3->item(1, 1);
        ___qtablewidgetitem23->setText(QApplication::translate("dialog_opacity", "1", nullptr));
        opatable_3->setSortingEnabled(__sortingEnabled2);

        label->setText(QApplication::translate("dialog_opacity", "      R                                                                           G                                                                            B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog_opacity: public Ui_dialog_opacity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_OPACITY_H
