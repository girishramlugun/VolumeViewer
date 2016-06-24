/********************************************************************************
** Form generated from reading UI file 'dialog_vol_prop.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_VOL_PROP_H
#define UI_DIALOG_VOL_PROP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialog_vol_prop
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *dim_x;
    QDoubleSpinBox *dim_y;
    QDoubleSpinBox *dim_z;
    QPushButton *set_vol_dim;
    QPushButton *cancel_vol_dim;

    void setupUi(QDialog *dialog_vol_prop)
    {
        if (dialog_vol_prop->objectName().isEmpty())
            dialog_vol_prop->setObjectName(QStringLiteral("dialog_vol_prop"));
        dialog_vol_prop->resize(162, 117);
        gridLayout = new QGridLayout(dialog_vol_prop);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        dim_x = new QDoubleSpinBox(dialog_vol_prop);
        dim_x->setObjectName(QStringLiteral("dim_x"));
        dim_x->setMinimum(1);

        verticalLayout->addWidget(dim_x);

        dim_y = new QDoubleSpinBox(dialog_vol_prop);
        dim_y->setObjectName(QStringLiteral("dim_y"));
        dim_y->setValue(1);

        verticalLayout->addWidget(dim_y);

        dim_z = new QDoubleSpinBox(dialog_vol_prop);
        dim_z->setObjectName(QStringLiteral("dim_z"));
        dim_z->setValue(1);

        verticalLayout->addWidget(dim_z);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);

        set_vol_dim = new QPushButton(dialog_vol_prop);
        set_vol_dim->setObjectName(QStringLiteral("set_vol_dim"));

        gridLayout->addWidget(set_vol_dim, 0, 1, 1, 1);

        cancel_vol_dim = new QPushButton(dialog_vol_prop);
        cancel_vol_dim->setObjectName(QStringLiteral("cancel_vol_dim"));

        gridLayout->addWidget(cancel_vol_dim, 1, 1, 1, 1);


        retranslateUi(dialog_vol_prop);

        QMetaObject::connectSlotsByName(dialog_vol_prop);
    } // setupUi

    void retranslateUi(QDialog *dialog_vol_prop)
    {
        dialog_vol_prop->setWindowTitle(QApplication::translate("dialog_vol_prop", "Volume Dimensions", 0));
        set_vol_dim->setText(QApplication::translate("dialog_vol_prop", "Set", 0));
        cancel_vol_dim->setText(QApplication::translate("dialog_vol_prop", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class dialog_vol_prop: public Ui_dialog_vol_prop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_VOL_PROP_H
