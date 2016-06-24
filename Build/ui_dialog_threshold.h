/********************************************************************************
** Form generated from reading UI file 'dialog_threshold.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_THRESHOLD_H
#define UI_DIALOG_THRESHOLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog_threshold
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *lthreshold;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *uthreshold;
    QDialogButtonBox *okthreshold;

    void setupUi(QDialog *Dialog_threshold)
    {
        if (Dialog_threshold->objectName().isEmpty())
            Dialog_threshold->setObjectName(QStringLiteral("Dialog_threshold"));
        Dialog_threshold->resize(178, 108);
        gridLayout = new QGridLayout(Dialog_threshold);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(Dialog_threshold);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lthreshold = new QSpinBox(Dialog_threshold);
        lthreshold->setObjectName(QStringLiteral("lthreshold"));
        lthreshold->setMaximum(255);

        horizontalLayout_2->addWidget(lthreshold);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(Dialog_threshold);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        uthreshold = new QSpinBox(Dialog_threshold);
        uthreshold->setObjectName(QStringLiteral("uthreshold"));
        uthreshold->setMaximum(255);
        uthreshold->setValue(255);

        horizontalLayout->addWidget(uthreshold);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        okthreshold = new QDialogButtonBox(Dialog_threshold);
        okthreshold->setObjectName(QStringLiteral("okthreshold"));
        okthreshold->setOrientation(Qt::Horizontal);
        okthreshold->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(okthreshold, 2, 0, 1, 1);


        retranslateUi(Dialog_threshold);
        QObject::connect(okthreshold, SIGNAL(accepted()), Dialog_threshold, SLOT(accept()));
        QObject::connect(okthreshold, SIGNAL(rejected()), Dialog_threshold, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_threshold);
    } // setupUi

    void retranslateUi(QDialog *Dialog_threshold)
    {
        Dialog_threshold->setWindowTitle(QApplication::translate("Dialog_threshold", "Threshold Volume", 0));
        label->setText(QApplication::translate("Dialog_threshold", "Lower Threshold:", 0));
        label_2->setText(QApplication::translate("Dialog_threshold", "Upper Threshold:", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_threshold: public Ui_Dialog_threshold {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_THRESHOLD_H
