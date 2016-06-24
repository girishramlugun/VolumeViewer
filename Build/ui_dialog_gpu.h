/********************************************************************************
** Form generated from reading UI file 'dialog_gpu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_GPU_H
#define UI_DIALOG_GPU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_gpu
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *vram_val;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_gpu)
    {
        if (Dialog_gpu->objectName().isEmpty())
            Dialog_gpu->setObjectName(QStringLiteral("Dialog_gpu"));
        Dialog_gpu->resize(266, 100);
        widget = new QWidget(Dialog_gpu);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 225, 64));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        vram_val = new QComboBox(widget);
        vram_val->setObjectName(QStringLiteral("vram_val"));

        horizontalLayout->addWidget(vram_val);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(Dialog_gpu);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_gpu, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_gpu, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_gpu);
    } // setupUi

    void retranslateUi(QDialog *Dialog_gpu)
    {
        Dialog_gpu->setWindowTitle(QApplication::translate("Dialog_gpu", "Options", 0));
        label->setText(QApplication::translate("Dialog_gpu", "Select GPU VRAM Size", 0));
        vram_val->clear();
        vram_val->insertItems(0, QStringList()
         << QApplication::translate("Dialog_gpu", "1", 0)
         << QApplication::translate("Dialog_gpu", "2", 0)
         << QApplication::translate("Dialog_gpu", "3", 0)
         << QApplication::translate("Dialog_gpu", "4", 0)
         << QApplication::translate("Dialog_gpu", "5", 0)
         << QApplication::translate("Dialog_gpu", "6", 0)
         << QApplication::translate("Dialog_gpu", "7", 0)
         << QApplication::translate("Dialog_gpu", "8", 0)
        );
        label_2->setText(QApplication::translate("Dialog_gpu", "GB", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_gpu: public Ui_Dialog_gpu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_GPU_H
