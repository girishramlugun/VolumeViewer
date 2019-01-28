/********************************************************************************
** Form generated from reading UI file 'dialog_fibre.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FIBRE_H
#define UI_DIALOG_FIBRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Fibre
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *fiblen;
    QLabel *label_2;
    QSpinBox *Skip;
    QDialogButtonBox *okfibre;

    void setupUi(QDialog *Dialog_Fibre)
    {
        if (Dialog_Fibre->objectName().isEmpty())
            Dialog_Fibre->setObjectName(QStringLiteral("Dialog_Fibre"));
        Dialog_Fibre->resize(213, 99);
        gridLayout_3 = new QGridLayout(Dialog_Fibre);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Dialog_Fibre);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        fiblen = new QSpinBox(Dialog_Fibre);
        fiblen->setObjectName(QStringLiteral("fiblen"));
        fiblen->setMaximum(20000);
        fiblen->setValue(20);

        gridLayout->addWidget(fiblen, 0, 1, 1, 1);

        label_2 = new QLabel(Dialog_Fibre);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        Skip = new QSpinBox(Dialog_Fibre);
        Skip->setObjectName(QStringLiteral("Skip"));
        Skip->setMaximum(100);
        Skip->setValue(10);

        gridLayout->addWidget(Skip, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        okfibre = new QDialogButtonBox(Dialog_Fibre);
        okfibre->setObjectName(QStringLiteral("okfibre"));
        okfibre->setOrientation(Qt::Horizontal);
        okfibre->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(okfibre, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(Dialog_Fibre);
        QObject::connect(okfibre, SIGNAL(accepted()), Dialog_Fibre, SLOT(accept()));
        QObject::connect(okfibre, SIGNAL(rejected()), Dialog_Fibre, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_Fibre);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Fibre)
    {
        Dialog_Fibre->setWindowTitle(QApplication::translate("Dialog_Fibre", "Select Display Parameters", nullptr));
        label->setText(QApplication::translate("Dialog_Fibre", "Set Minimum Fibre Length:", nullptr));
        label_2->setText(QApplication::translate("Dialog_Fibre", "Set Resolution:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Fibre: public Ui_Dialog_Fibre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FIBRE_H
