/********************************************************************************
** Form generated from reading UI file 'dialog_bg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_BG_H
#define UI_DIALOG_BG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Bg
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *set_bg;
    QPushButton *reset_bg;
    QPushButton *cancel_bg;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelr;
    QSpinBox *bg_col_r;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelb;
    QSpinBox *bg_col_b;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelgg;
    QSpinBox *bg_col_g;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *Dialog_Bg)
    {
        if (Dialog_Bg->objectName().isEmpty())
            Dialog_Bg->setObjectName(QStringLiteral("Dialog_Bg"));
        Dialog_Bg->resize(244, 109);
        gridLayout_3 = new QGridLayout(Dialog_Bg);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        set_bg = new QPushButton(Dialog_Bg);
        set_bg->setObjectName(QStringLiteral("set_bg"));

        verticalLayout->addWidget(set_bg);

        reset_bg = new QPushButton(Dialog_Bg);
        reset_bg->setObjectName(QStringLiteral("reset_bg"));

        verticalLayout->addWidget(reset_bg);

        cancel_bg = new QPushButton(Dialog_Bg);
        cancel_bg->setObjectName(QStringLiteral("cancel_bg"));

        verticalLayout->addWidget(cancel_bg);


        gridLayout_2->addLayout(verticalLayout, 0, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelr = new QLabel(Dialog_Bg);
        labelr->setObjectName(QStringLiteral("labelr"));

        horizontalLayout->addWidget(labelr);

        bg_col_r = new QSpinBox(Dialog_Bg);
        bg_col_r->setObjectName(QStringLiteral("bg_col_r"));
        bg_col_r->setMaximum(255);

        horizontalLayout->addWidget(bg_col_r);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelb = new QLabel(Dialog_Bg);
        labelb->setObjectName(QStringLiteral("labelb"));

        horizontalLayout_3->addWidget(labelb);

        bg_col_b = new QSpinBox(Dialog_Bg);
        bg_col_b->setObjectName(QStringLiteral("bg_col_b"));
        bg_col_b->setMaximum(255);

        horizontalLayout_3->addWidget(bg_col_b);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelgg = new QLabel(Dialog_Bg);
        labelgg->setObjectName(QStringLiteral("labelgg"));

        horizontalLayout_2->addWidget(labelgg);

        bg_col_g = new QSpinBox(Dialog_Bg);
        bg_col_g->setObjectName(QStringLiteral("bg_col_g"));
        bg_col_g->setMaximum(255);

        horizontalLayout_2->addWidget(bg_col_g);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(Dialog_Bg);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setAutoFillBackground(true);
        graphicsView->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(graphicsView, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(Dialog_Bg);

        QMetaObject::connectSlotsByName(Dialog_Bg);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Bg)
    {
        Dialog_Bg->setWindowTitle(QApplication::translate("Dialog_Bg", "Background", nullptr));
        set_bg->setText(QApplication::translate("Dialog_Bg", "Set", nullptr));
        reset_bg->setText(QApplication::translate("Dialog_Bg", "Reset", nullptr));
        cancel_bg->setText(QApplication::translate("Dialog_Bg", "Cancel", nullptr));
        labelr->setText(QApplication::translate("Dialog_Bg", "R:", nullptr));
        labelb->setText(QApplication::translate("Dialog_Bg", "B:", nullptr));
        labelgg->setText(QApplication::translate("Dialog_Bg", "G:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Bg: public Ui_Dialog_Bg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_BG_H
