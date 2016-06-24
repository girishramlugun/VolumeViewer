/********************************************************************************
** Form generated from reading UI file 'dialog_hessian.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_HESSIAN_H
#define UI_DIALOG_HESSIAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_dialog_hessian
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *sigma;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDoubleSpinBox *alpha1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *alpha2;
    QDialogButtonBox *okhessian;

    void setupUi(QDialog *dialog_hessian)
    {
        if (dialog_hessian->objectName().isEmpty())
            dialog_hessian->setObjectName(QStringLiteral("dialog_hessian"));
        dialog_hessian->resize(327, 92);
        gridLayout_2 = new QGridLayout(dialog_hessian);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(dialog_hessian);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        sigma = new QDoubleSpinBox(dialog_hessian);
        sigma->setObjectName(QStringLiteral("sigma"));

        horizontalLayout_2->addWidget(sigma);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(dialog_hessian);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        alpha1 = new QDoubleSpinBox(dialog_hessian);
        alpha1->setObjectName(QStringLiteral("alpha1"));

        horizontalLayout->addWidget(alpha1);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(dialog_hessian);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        alpha2 = new QDoubleSpinBox(dialog_hessian);
        alpha2->setObjectName(QStringLiteral("alpha2"));

        horizontalLayout_3->addWidget(alpha2);


        gridLayout->addLayout(horizontalLayout_3, 0, 2, 1, 1);

        okhessian = new QDialogButtonBox(dialog_hessian);
        okhessian->setObjectName(QStringLiteral("okhessian"));
        okhessian->setOrientation(Qt::Horizontal);
        okhessian->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(okhessian, 1, 0, 1, 3);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(dialog_hessian);
        QObject::connect(okhessian, SIGNAL(accepted()), dialog_hessian, SLOT(accept()));
        QObject::connect(okhessian, SIGNAL(rejected()), dialog_hessian, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialog_hessian);
    } // setupUi

    void retranslateUi(QDialog *dialog_hessian)
    {
        dialog_hessian->setWindowTitle(QApplication::translate("dialog_hessian", "Hessian Filter", 0));
        label->setText(QApplication::translate("dialog_hessian", "Sigma:", 0));
        label_2->setText(QApplication::translate("dialog_hessian", "Alpha 1:", 0));
        label_3->setText(QApplication::translate("dialog_hessian", "Alpha 2:", 0));
    } // retranslateUi

};

namespace Ui {
    class dialog_hessian: public Ui_dialog_hessian {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_HESSIAN_H
