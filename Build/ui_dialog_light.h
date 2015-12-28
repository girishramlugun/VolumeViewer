/********************************************************************************
** Form generated from reading UI file 'dialog_light.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_LIGHT_H
#define UI_DIALOG_LIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog_light
{
public:
    QDialogButtonBox *ok_lights;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_5;
    QDoubleSpinBox *keywarmth;
    QLabel *label_3;
    QDoubleSpinBox *keyint;
    QLabel *label_4;
    QDoubleSpinBox *keyele;
    QLabel *label_2;
    QDoubleSpinBox *keyazi;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QLabel *label_16;
    QLabel *label_8;
    QDoubleSpinBox *fillwarm;
    QLabel *label_9;
    QDoubleSpinBox *fillkf;
    QLabel *label_12;
    QDoubleSpinBox *fillele;
    QLabel *label_14;
    QDoubleSpinBox *fillazi;
    QWidget *widget2;
    QGridLayout *gridLayout_3;
    QLabel *label_17;
    QLabel *label_6;
    QDoubleSpinBox *backwarm;
    QLabel *label_10;
    QDoubleSpinBox *backkb;
    QLabel *label_13;
    QDoubleSpinBox *backele;
    QLabel *label_15;
    QDoubleSpinBox *backazi;
    QWidget *widget3;
    QGridLayout *gridLayout_4;
    QLabel *label_18;
    QLabel *label_7;
    QDoubleSpinBox *headwarm;
    QLabel *label_11;
    QDoubleSpinBox *headkh;

    void setupUi(QDialog *dialog_light)
    {
        if (dialog_light->objectName().isEmpty())
            dialog_light->setObjectName(QStringLiteral("dialog_light"));
        dialog_light->resize(391, 169);
        ok_lights = new QDialogButtonBox(dialog_light);
        ok_lights->setObjectName(QStringLiteral("ok_lights"));
        ok_lights->setGeometry(QRect(9, 121, 156, 23));
        ok_lights->setOrientation(Qt::Horizontal);
        ok_lights->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(dialog_light);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 9, 371, 22));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 1, 1, 1);

        keywarmth = new QDoubleSpinBox(widget);
        keywarmth->setObjectName(QStringLiteral("keywarmth"));
        keywarmth->setValue(0.6);

        gridLayout->addWidget(keywarmth, 0, 2, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        keyint = new QDoubleSpinBox(widget);
        keyint->setObjectName(QStringLiteral("keyint"));
        keyint->setValue(0.75);

        gridLayout->addWidget(keyint, 0, 4, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 5, 1, 1);

        keyele = new QDoubleSpinBox(widget);
        keyele->setObjectName(QStringLiteral("keyele"));
        keyele->setDecimals(0);
        keyele->setMaximum(1000);
        keyele->setValue(50);

        gridLayout->addWidget(keyele, 0, 6, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 7, 1, 1);

        keyazi = new QDoubleSpinBox(widget);
        keyazi->setObjectName(QStringLiteral("keyazi"));
        keyazi->setDecimals(0);
        keyazi->setMinimum(-100);
        keyazi->setValue(10);

        gridLayout->addWidget(keyazi, 0, 8, 1, 1);

        widget1 = new QWidget(dialog_light);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(9, 37, 371, 22));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(widget1);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_2->addWidget(label_16, 0, 0, 1, 1);

        label_8 = new QLabel(widget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 0, 1, 1, 1);

        fillwarm = new QDoubleSpinBox(widget1);
        fillwarm->setObjectName(QStringLiteral("fillwarm"));
        fillwarm->setValue(0.4);

        gridLayout_2->addWidget(fillwarm, 0, 2, 1, 1);

        label_9 = new QLabel(widget1);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 0, 3, 1, 1);

        fillkf = new QDoubleSpinBox(widget1);
        fillkf->setObjectName(QStringLiteral("fillkf"));
        fillkf->setValue(3);

        gridLayout_2->addWidget(fillkf, 0, 4, 1, 1);

        label_12 = new QLabel(widget1);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 0, 5, 1, 1);

        fillele = new QDoubleSpinBox(widget1);
        fillele->setObjectName(QStringLiteral("fillele"));
        fillele->setDecimals(0);
        fillele->setMinimum(-1000);
        fillele->setMaximum(1000);
        fillele->setValue(-75);

        gridLayout_2->addWidget(fillele, 0, 6, 1, 1);

        label_14 = new QLabel(widget1);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_2->addWidget(label_14, 0, 7, 1, 1);

        fillazi = new QDoubleSpinBox(widget1);
        fillazi->setObjectName(QStringLiteral("fillazi"));
        fillazi->setMinimum(-100);
        fillazi->setMaximum(100);
        fillazi->setValue(-10);

        gridLayout_2->addWidget(fillazi, 0, 8, 1, 1);

        widget2 = new QWidget(dialog_light);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(9, 65, 374, 22));
        gridLayout_3 = new QGridLayout(widget2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(widget2);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_3->addWidget(label_17, 0, 0, 1, 1);

        label_6 = new QLabel(widget2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 0, 1, 1, 1);

        backwarm = new QDoubleSpinBox(widget2);
        backwarm->setObjectName(QStringLiteral("backwarm"));
        backwarm->setValue(0.5);

        gridLayout_3->addWidget(backwarm, 0, 2, 1, 1);

        label_10 = new QLabel(widget2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 0, 3, 1, 1);

        backkb = new QDoubleSpinBox(widget2);
        backkb->setObjectName(QStringLiteral("backkb"));
        backkb->setValue(3.5);

        gridLayout_3->addWidget(backkb, 0, 4, 1, 1);

        label_13 = new QLabel(widget2);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 0, 5, 1, 1);

        backele = new QDoubleSpinBox(widget2);
        backele->setObjectName(QStringLiteral("backele"));
        backele->setDecimals(0);
        backele->setMinimum(-1000);
        backele->setValue(0);

        gridLayout_3->addWidget(backele, 0, 6, 1, 1);

        label_15 = new QLabel(widget2);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_3->addWidget(label_15, 0, 7, 1, 1);

        backazi = new QDoubleSpinBox(widget2);
        backazi->setObjectName(QStringLiteral("backazi"));
        backazi->setDecimals(0);
        backazi->setMinimum(-1000);
        backazi->setMaximum(1000);
        backazi->setValue(110);

        gridLayout_3->addWidget(backazi, 0, 8, 1, 1);

        widget3 = new QWidget(dialog_light);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(9, 93, 206, 22));
        gridLayout_4 = new QGridLayout(widget3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(widget3);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_4->addWidget(label_18, 0, 0, 1, 1);

        label_7 = new QLabel(widget3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 0, 1, 1, 1);

        headwarm = new QDoubleSpinBox(widget3);
        headwarm->setObjectName(QStringLiteral("headwarm"));
        headwarm->setValue(0.5);

        gridLayout_4->addWidget(headwarm, 0, 2, 1, 1);

        label_11 = new QLabel(widget3);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_4->addWidget(label_11, 0, 3, 1, 1);

        headkh = new QDoubleSpinBox(widget3);
        headkh->setObjectName(QStringLiteral("headkh"));
        headkh->setValue(3);

        gridLayout_4->addWidget(headkh, 0, 4, 1, 1);


        retranslateUi(dialog_light);
        QObject::connect(ok_lights, SIGNAL(accepted()), dialog_light, SLOT(accept()));
        QObject::connect(ok_lights, SIGNAL(rejected()), dialog_light, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialog_light);
    } // setupUi

    void retranslateUi(QDialog *dialog_light)
    {
        dialog_light->setWindowTitle(QApplication::translate("dialog_light", "Lights", 0));
        label->setText(QApplication::translate("dialog_light", "Key:", 0));
        label_5->setText(QApplication::translate("dialog_light", "Warm", 0));
        label_3->setText(QApplication::translate("dialog_light", "Int", 0));
        label_4->setText(QApplication::translate("dialog_light", "Ele", 0));
        label_2->setText(QApplication::translate("dialog_light", "Azi", 0));
        label_16->setText(QApplication::translate("dialog_light", "Fill:", 0));
        label_8->setText(QApplication::translate("dialog_light", "Warm", 0));
        label_9->setText(QApplication::translate("dialog_light", "K:F", 0));
        label_12->setText(QApplication::translate("dialog_light", "Ele", 0));
        label_14->setText(QApplication::translate("dialog_light", "Azi", 0));
        label_17->setText(QApplication::translate("dialog_light", "Back:", 0));
        label_6->setText(QApplication::translate("dialog_light", "Warm", 0));
        label_10->setText(QApplication::translate("dialog_light", "K:B", 0));
        label_13->setText(QApplication::translate("dialog_light", "Ele", 0));
        label_15->setText(QApplication::translate("dialog_light", "Azi", 0));
        label_18->setText(QApplication::translate("dialog_light", "Head:", 0));
        label_7->setText(QApplication::translate("dialog_light", "Warm", 0));
        label_11->setText(QApplication::translate("dialog_light", "K:H", 0));
    } // retranslateUi

};

namespace Ui {
    class dialog_light: public Ui_dialog_light {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_LIGHT_H
