/********************************************************************************
** Form generated from reading UI file 'dialog_color.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_COLOR_H
#define UI_DIALOG_COLOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog_color
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QSlider *volcol;
    QSlider *wincol;
    QLabel *vc;
    QLabel *wc;

    void setupUi(QDialog *dialog_color)
    {
        if (dialog_color->objectName().isEmpty())
            dialog_color->setObjectName(QStringLiteral("dialog_color"));
        dialog_color->resize(193, 237);
        buttonBox = new QDialogButtonBox(dialog_color);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 140, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(dialog_color);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 151, 111));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        volcol = new QSlider(layoutWidget);
        volcol->setObjectName(QStringLiteral("volcol"));
        volcol->setMaximum(100);
        volcol->setSingleStep(10);
        volcol->setPageStep(10);
        volcol->setValue(50);
        volcol->setOrientation(Qt::Vertical);

        gridLayout->addWidget(volcol, 1, 0, 1, 1, Qt::AlignHCenter);

        wincol = new QSlider(layoutWidget);
        wincol->setObjectName(QStringLiteral("wincol"));
        wincol->setMaximum(100);
        wincol->setSingleStep(10);
        wincol->setPageStep(10);
        wincol->setValue(100);
        wincol->setOrientation(Qt::Vertical);

        gridLayout->addWidget(wincol, 1, 1, 1, 1, Qt::AlignHCenter);

        vc = new QLabel(dialog_color);
        vc->setObjectName(QStringLiteral("vc"));
        vc->setGeometry(QRect(30, 120, 51, 16));
        wc = new QLabel(dialog_color);
        wc->setObjectName(QStringLiteral("wc"));
        wc->setGeometry(QRect(110, 120, 51, 16));

        retranslateUi(dialog_color);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialog_color, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialog_color, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialog_color);
    } // setupUi

    void retranslateUi(QDialog *dialog_color)
    {
        dialog_color->setWindowTitle(QApplication::translate("dialog_color", "Dialog", nullptr));
        label->setText(QApplication::translate("dialog_color", "Volume Color", nullptr));
        label_2->setText(QApplication::translate("dialog_color", "Window Color", nullptr));
        vc->setText(QString());
        wc->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dialog_color: public Ui_dialog_color {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_COLOR_H
