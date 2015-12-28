/********************************************************************************
** Form generated from reading UI file 'dialog_rotation.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ROTATION_H
#define UI_DIALOG_ROTATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialog_rotation
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *x;
    QRadioButton *Y;
    QRadioButton *Z;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *angle;
    QRadioButton *generatemovie;
    QHBoxLayout *horizontalLayout;
    QPushButton *startrot;
    QPushButton *stoprot;

    void setupUi(QDialog *dialog_rotation)
    {
        if (dialog_rotation->objectName().isEmpty())
            dialog_rotation->setObjectName(QStringLiteral("dialog_rotation"));
        dialog_rotation->resize(297, 141);
        gridLayout = new QGridLayout(dialog_rotation);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(dialog_rotation);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        x = new QRadioButton(groupBox);
        x->setObjectName(QStringLiteral("x"));

        verticalLayout->addWidget(x);

        Y = new QRadioButton(groupBox);
        Y->setObjectName(QStringLiteral("Y"));

        verticalLayout->addWidget(Y);

        Z = new QRadioButton(groupBox);
        Z->setObjectName(QStringLiteral("Z"));

        verticalLayout->addWidget(Z);


        gridLayout->addWidget(groupBox, 0, 0, 3, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(dialog_rotation);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        angle = new QDoubleSpinBox(dialog_rotation);
        angle->setObjectName(QStringLiteral("angle"));
        angle->setDecimals(1);
        angle->setSingleStep(1);
        angle->setValue(1);

        horizontalLayout_2->addWidget(angle);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        generatemovie = new QRadioButton(dialog_rotation);
        generatemovie->setObjectName(QStringLiteral("generatemovie"));

        gridLayout->addWidget(generatemovie, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        startrot = new QPushButton(dialog_rotation);
        startrot->setObjectName(QStringLiteral("startrot"));

        horizontalLayout->addWidget(startrot);

        stoprot = new QPushButton(dialog_rotation);
        stoprot->setObjectName(QStringLiteral("stoprot"));

        horizontalLayout->addWidget(stoprot);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);


        retranslateUi(dialog_rotation);

        QMetaObject::connectSlotsByName(dialog_rotation);
    } // setupUi

    void retranslateUi(QDialog *dialog_rotation)
    {
        dialog_rotation->setWindowTitle(QApplication::translate("dialog_rotation", "Rotation", 0));
        groupBox->setTitle(QApplication::translate("dialog_rotation", "Direction", 0));
        x->setText(QApplication::translate("dialog_rotation", "X", 0));
        Y->setText(QApplication::translate("dialog_rotation", "Y", 0));
        Z->setText(QApplication::translate("dialog_rotation", "Z", 0));
        label->setText(QApplication::translate("dialog_rotation", "Angle:", 0));
        generatemovie->setText(QApplication::translate("dialog_rotation", "Generate Movie", 0));
        startrot->setText(QApplication::translate("dialog_rotation", "Start", 0));
        stoprot->setText(QApplication::translate("dialog_rotation", "Stop", 0));
    } // retranslateUi

};

namespace Ui {
    class dialog_rotation: public Ui_dialog_rotation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ROTATION_H
