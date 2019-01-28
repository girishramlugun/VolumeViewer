/********************************************************************************
** Form generated from reading UI file 'VolumeViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUMEVIEWER_H
#define UI_VOLUMEVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VolumeViewer
{
public:
    QAction *actionOpenFile;
    QAction *actionExit;
    QAction *actionPrint;
    QAction *actionHelp;
    QAction *actionSave;
    QAction *actionClose;
    QAction *actionExit_2;
    QAction *actionOpacity;
    QAction *actionGrey;
    QAction *actionFibrosis;
    QAction *actionCustom;
    QAction *actionGPU_Texture;
    QAction *actionRay_Cast;
    QAction *actionSmart;
    QAction *actionCPU_Texture;
    QAction *actionAbout;
    QAction *actionHelp_Topics;
    QAction *actionClip;
    QAction *actionSlice;
    QAction *actionCamera;
    QAction *actionLights;
    QAction *actionBackground;
    QAction *actionR_to_B;
    QAction *actionB_to_R;
    QAction *actionSave_Screenshot;
    QAction *actionRotate;
    QAction *actionDimensions;
    QAction *actionSave_Volume;
    QAction *actionColor_Window;
    QAction *actionColor_Level;
    QAction *actionColor;
    QAction *actionIsosurface;
    QAction *actionImage;
    QAction *actionHessian;
    QAction *actionOpen;
    QAction *actionAdd;
    QAction *actionRay_Cast_Texture;
    QAction *actionNearest;
    QAction *actionLinear;
    QAction *actionCubic;
    QAction *actionImage_Sequence;
    QAction *actionGreen;
    QAction *actionLoadLUT;
    QAction *actionAxes;
    QAction *actionAnaglyph;
    QAction *actionRed_Blue;
    QAction *actionInterlaced;
    QAction *actionUpsample;
    QAction *actionCrop;
    QAction *actionOptions;
    QAction *actionThreshold;
    QAction *actionReslice;
    QAction *actionTime_Sequence;
    QWidget *centralwidget;
    QPushButton *clear;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSave;
    QMenu *menuLoad;
    QMenu *menuTool;
    QMenu *menuPalette;
    QMenu *menuPreset;
    QMenu *menuRendering;
    QMenu *menuInterpolation;
    QMenu *menuHelp;
    QMenu *menuView;
    QMenu *menuVolume;
    QMenu *menuStereo;
    QMenu *menuFilters;
    QMenu *menuVolume_filter;
    QMenu *menuImage_filter;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VolumeViewer)
    {
        if (VolumeViewer->objectName().isEmpty())
            VolumeViewer->setObjectName(QStringLiteral("VolumeViewer"));
        VolumeViewer->setWindowModality(Qt::NonModal);
        VolumeViewer->setEnabled(true);
        VolumeViewer->resize(583, 132);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VolumeViewer->sizePolicy().hasHeightForWidth());
        VolumeViewer->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/Icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        VolumeViewer->setWindowIcon(icon);
        VolumeViewer->setToolTipDuration(-1);
        VolumeViewer->setIconSize(QSize(22, 22));
        VolumeViewer->setAnimated(true);
        actionOpenFile = new QAction(VolumeViewer);
        actionOpenFile->setObjectName(QStringLiteral("actionOpenFile"));
        actionOpenFile->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenFile->setIcon(icon1);
        actionExit = new QAction(VolumeViewer);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionPrint = new QAction(VolumeViewer);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icons/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon3);
        actionHelp = new QAction(VolumeViewer);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon4);
        actionSave = new QAction(VolumeViewer);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icons/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon5);
        actionClose = new QAction(VolumeViewer);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionExit_2 = new QAction(VolumeViewer);
        actionExit_2->setObjectName(QStringLiteral("actionExit_2"));
        actionOpacity = new QAction(VolumeViewer);
        actionOpacity->setObjectName(QStringLiteral("actionOpacity"));
        actionGrey = new QAction(VolumeViewer);
        actionGrey->setObjectName(QStringLiteral("actionGrey"));
        actionFibrosis = new QAction(VolumeViewer);
        actionFibrosis->setObjectName(QStringLiteral("actionFibrosis"));
        actionCustom = new QAction(VolumeViewer);
        actionCustom->setObjectName(QStringLiteral("actionCustom"));
        actionGPU_Texture = new QAction(VolumeViewer);
        actionGPU_Texture->setObjectName(QStringLiteral("actionGPU_Texture"));
        actionRay_Cast = new QAction(VolumeViewer);
        actionRay_Cast->setObjectName(QStringLiteral("actionRay_Cast"));
        actionSmart = new QAction(VolumeViewer);
        actionSmart->setObjectName(QStringLiteral("actionSmart"));
        actionCPU_Texture = new QAction(VolumeViewer);
        actionCPU_Texture->setObjectName(QStringLiteral("actionCPU_Texture"));
        actionAbout = new QAction(VolumeViewer);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionHelp_Topics = new QAction(VolumeViewer);
        actionHelp_Topics->setObjectName(QStringLiteral("actionHelp_Topics"));
        actionClip = new QAction(VolumeViewer);
        actionClip->setObjectName(QStringLiteral("actionClip"));
        actionClip->setCheckable(true);
        actionSlice = new QAction(VolumeViewer);
        actionSlice->setObjectName(QStringLiteral("actionSlice"));
        actionCamera = new QAction(VolumeViewer);
        actionCamera->setObjectName(QStringLiteral("actionCamera"));
        actionLights = new QAction(VolumeViewer);
        actionLights->setObjectName(QStringLiteral("actionLights"));
        actionBackground = new QAction(VolumeViewer);
        actionBackground->setObjectName(QStringLiteral("actionBackground"));
        actionR_to_B = new QAction(VolumeViewer);
        actionR_to_B->setObjectName(QStringLiteral("actionR_to_B"));
        actionB_to_R = new QAction(VolumeViewer);
        actionB_to_R->setObjectName(QStringLiteral("actionB_to_R"));
        actionSave_Screenshot = new QAction(VolumeViewer);
        actionSave_Screenshot->setObjectName(QStringLiteral("actionSave_Screenshot"));
        actionRotate = new QAction(VolumeViewer);
        actionRotate->setObjectName(QStringLiteral("actionRotate"));
        actionDimensions = new QAction(VolumeViewer);
        actionDimensions->setObjectName(QStringLiteral("actionDimensions"));
        actionSave_Volume = new QAction(VolumeViewer);
        actionSave_Volume->setObjectName(QStringLiteral("actionSave_Volume"));
        actionColor_Window = new QAction(VolumeViewer);
        actionColor_Window->setObjectName(QStringLiteral("actionColor_Window"));
        actionColor_Level = new QAction(VolumeViewer);
        actionColor_Level->setObjectName(QStringLiteral("actionColor_Level"));
        actionColor = new QAction(VolumeViewer);
        actionColor->setObjectName(QStringLiteral("actionColor"));
        actionIsosurface = new QAction(VolumeViewer);
        actionIsosurface->setObjectName(QStringLiteral("actionIsosurface"));
        actionImage = new QAction(VolumeViewer);
        actionImage->setObjectName(QStringLiteral("actionImage"));
        actionHessian = new QAction(VolumeViewer);
        actionHessian->setObjectName(QStringLiteral("actionHessian"));
        actionOpen = new QAction(VolumeViewer);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionAdd = new QAction(VolumeViewer);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        actionAdd->setEnabled(false);
        actionRay_Cast_Texture = new QAction(VolumeViewer);
        actionRay_Cast_Texture->setObjectName(QStringLiteral("actionRay_Cast_Texture"));
        actionNearest = new QAction(VolumeViewer);
        actionNearest->setObjectName(QStringLiteral("actionNearest"));
        actionNearest->setCheckable(true);
        actionNearest->setChecked(true);
        actionLinear = new QAction(VolumeViewer);
        actionLinear->setObjectName(QStringLiteral("actionLinear"));
        actionLinear->setCheckable(true);
        actionCubic = new QAction(VolumeViewer);
        actionCubic->setObjectName(QStringLiteral("actionCubic"));
        actionCubic->setCheckable(true);
        actionImage_Sequence = new QAction(VolumeViewer);
        actionImage_Sequence->setObjectName(QStringLiteral("actionImage_Sequence"));
        actionGreen = new QAction(VolumeViewer);
        actionGreen->setObjectName(QStringLiteral("actionGreen"));
        actionLoadLUT = new QAction(VolumeViewer);
        actionLoadLUT->setObjectName(QStringLiteral("actionLoadLUT"));
        actionLoadLUT->setEnabled(true);
        actionAxes = new QAction(VolumeViewer);
        actionAxes->setObjectName(QStringLiteral("actionAxes"));
        actionAxes->setCheckable(true);
        actionAnaglyph = new QAction(VolumeViewer);
        actionAnaglyph->setObjectName(QStringLiteral("actionAnaglyph"));
        actionAnaglyph->setCheckable(true);
        actionRed_Blue = new QAction(VolumeViewer);
        actionRed_Blue->setObjectName(QStringLiteral("actionRed_Blue"));
        actionRed_Blue->setCheckable(true);
        actionInterlaced = new QAction(VolumeViewer);
        actionInterlaced->setObjectName(QStringLiteral("actionInterlaced"));
        actionInterlaced->setCheckable(true);
        actionUpsample = new QAction(VolumeViewer);
        actionUpsample->setObjectName(QStringLiteral("actionUpsample"));
        actionUpsample->setCheckable(true);
        actionCrop = new QAction(VolumeViewer);
        actionCrop->setObjectName(QStringLiteral("actionCrop"));
        actionOptions = new QAction(VolumeViewer);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionThreshold = new QAction(VolumeViewer);
        actionThreshold->setObjectName(QStringLiteral("actionThreshold"));
        actionReslice = new QAction(VolumeViewer);
        actionReslice->setObjectName(QStringLiteral("actionReslice"));
        actionTime_Sequence = new QAction(VolumeViewer);
        actionTime_Sequence->setObjectName(QStringLiteral("actionTime_Sequence"));
        centralwidget = new QWidget(VolumeViewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QStringLiteral(""));
        clear = new QPushButton(centralwidget);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(100, 10, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 60, 571, 16));
        VolumeViewer->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(VolumeViewer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 583, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSave = new QMenu(menuFile);
        menuSave->setObjectName(QStringLiteral("menuSave"));
        menuLoad = new QMenu(menuFile);
        menuLoad->setObjectName(QStringLiteral("menuLoad"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Icons/icons/open-file-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuLoad->setIcon(icon6);
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName(QStringLiteral("menuTool"));
        menuPalette = new QMenu(menuTool);
        menuPalette->setObjectName(QStringLiteral("menuPalette"));
        menuPreset = new QMenu(menuPalette);
        menuPreset->setObjectName(QStringLiteral("menuPreset"));
        menuRendering = new QMenu(menuTool);
        menuRendering->setObjectName(QStringLiteral("menuRendering"));
        menuInterpolation = new QMenu(menuRendering);
        menuInterpolation->setObjectName(QStringLiteral("menuInterpolation"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuVolume = new QMenu(menuView);
        menuVolume->setObjectName(QStringLiteral("menuVolume"));
        menuStereo = new QMenu(menuView);
        menuStereo->setObjectName(QStringLiteral("menuStereo"));
        menuFilters = new QMenu(menuBar);
        menuFilters->setObjectName(QStringLiteral("menuFilters"));
        menuVolume_filter = new QMenu(menuFilters);
        menuVolume_filter->setObjectName(QStringLiteral("menuVolume_filter"));
        menuImage_filter = new QMenu(menuFilters);
        menuImage_filter->setObjectName(QStringLiteral("menuImage_filter"));
        menuImage_filter->setEnabled(true);
        VolumeViewer->setMenuBar(menuBar);
        statusBar = new QStatusBar(VolumeViewer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VolumeViewer->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuFilters->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(menuLoad->menuAction());
        menuFile->addAction(menuSave->menuAction());
        menuFile->addAction(actionClose);
        menuFile->addAction(actionExit_2);
        menuSave->addAction(actionSave_Screenshot);
        menuSave->addAction(actionSave_Volume);
        menuLoad->addAction(actionImage);
        menuLoad->addAction(actionOpen);
        menuLoad->addAction(actionImage_Sequence);
        menuLoad->addAction(actionTime_Sequence);
        menuTool->addAction(menuPalette->menuAction());
        menuTool->addAction(actionOpacity);
        menuTool->addAction(menuRendering->menuAction());
        menuTool->addAction(actionClip);
        menuTool->addAction(actionSlice);
        menuTool->addAction(actionRotate);
        menuTool->addAction(actionAdd);
        menuTool->addAction(actionCrop);
        menuTool->addAction(actionOptions);
        menuTool->addAction(actionReslice);
        menuPalette->addAction(menuPreset->menuAction());
        menuPalette->addAction(actionCustom);
        menuPalette->addAction(actionLoadLUT);
        menuPreset->addAction(actionGrey);
        menuPreset->addAction(actionFibrosis);
        menuPreset->addAction(actionR_to_B);
        menuPreset->addAction(actionB_to_R);
        menuPreset->addAction(actionGreen);
        menuRendering->addAction(actionGPU_Texture);
        menuRendering->addAction(actionRay_Cast);
        menuRendering->addAction(menuInterpolation->menuAction());
        menuInterpolation->addAction(actionNearest);
        menuInterpolation->addAction(actionLinear);
        menuInterpolation->addAction(actionCubic);
        menuHelp->addAction(actionHelp_Topics);
        menuHelp->addAction(actionAbout);
        menuView->addAction(actionCamera);
        menuView->addAction(actionLights);
        menuView->addAction(actionBackground);
        menuView->addAction(menuVolume->menuAction());
        menuView->addAction(actionAxes);
        menuView->addAction(menuStereo->menuAction());
        menuVolume->addAction(actionDimensions);
        menuVolume->addAction(actionColor);
        menuStereo->addAction(actionAnaglyph);
        menuStereo->addAction(actionRed_Blue);
        menuStereo->addAction(actionInterlaced);
        menuFilters->addAction(menuVolume_filter->menuAction());
        menuFilters->addAction(menuImage_filter->menuAction());
        menuVolume_filter->addAction(actionIsosurface);
        menuVolume_filter->addAction(actionHessian);
        menuVolume_filter->addAction(actionThreshold);

        retranslateUi(VolumeViewer);

        QMetaObject::connectSlotsByName(VolumeViewer);
    } // setupUi

    void retranslateUi(QMainWindow *VolumeViewer)
    {
        VolumeViewer->setWindowTitle(QApplication::translate("VolumeViewer", "Volume Viewer", nullptr));
        actionOpenFile->setText(QApplication::translate("VolumeViewer", "Open File...", nullptr));
        actionExit->setText(QApplication::translate("VolumeViewer", "Exit", nullptr));
        actionPrint->setText(QApplication::translate("VolumeViewer", "Print", nullptr));
        actionHelp->setText(QApplication::translate("VolumeViewer", "Help", nullptr));
        actionSave->setText(QApplication::translate("VolumeViewer", "Save", nullptr));
        actionClose->setText(QApplication::translate("VolumeViewer", "Close", nullptr));
        actionExit_2->setText(QApplication::translate("VolumeViewer", "Exit", nullptr));
        actionOpacity->setText(QApplication::translate("VolumeViewer", "Opacity", nullptr));
        actionGrey->setText(QApplication::translate("VolumeViewer", "Grey", nullptr));
        actionFibrosis->setText(QApplication::translate("VolumeViewer", "Fibrosis", nullptr));
        actionCustom->setText(QApplication::translate("VolumeViewer", "Custom", nullptr));
        actionGPU_Texture->setText(QApplication::translate("VolumeViewer", "GPU Texture", nullptr));
        actionRay_Cast->setText(QApplication::translate("VolumeViewer", "Ray Cast", nullptr));
        actionSmart->setText(QApplication::translate("VolumeViewer", "Smart", nullptr));
        actionCPU_Texture->setText(QApplication::translate("VolumeViewer", "CPU Texture", nullptr));
        actionAbout->setText(QApplication::translate("VolumeViewer", "About", nullptr));
        actionHelp_Topics->setText(QApplication::translate("VolumeViewer", "Help Topics", nullptr));
        actionClip->setText(QApplication::translate("VolumeViewer", "Clip", nullptr));
        actionSlice->setText(QApplication::translate("VolumeViewer", "Slice", nullptr));
        actionCamera->setText(QApplication::translate("VolumeViewer", "Camera", nullptr));
        actionLights->setText(QApplication::translate("VolumeViewer", "Lights", nullptr));
        actionBackground->setText(QApplication::translate("VolumeViewer", "Background", nullptr));
        actionR_to_B->setText(QApplication::translate("VolumeViewer", "R to B", nullptr));
        actionB_to_R->setText(QApplication::translate("VolumeViewer", "B to R", nullptr));
        actionSave_Screenshot->setText(QApplication::translate("VolumeViewer", "Screenshot", nullptr));
        actionRotate->setText(QApplication::translate("VolumeViewer", "Rotate", nullptr));
        actionDimensions->setText(QApplication::translate("VolumeViewer", "Dimensions", nullptr));
        actionSave_Volume->setText(QApplication::translate("VolumeViewer", "Volume", nullptr));
        actionColor_Window->setText(QApplication::translate("VolumeViewer", "Color Window", nullptr));
        actionColor_Level->setText(QApplication::translate("VolumeViewer", "Color Level", nullptr));
        actionColor->setText(QApplication::translate("VolumeViewer", "Color", nullptr));
        actionIsosurface->setText(QApplication::translate("VolumeViewer", "Isosurface", nullptr));
        actionImage->setText(QApplication::translate("VolumeViewer", "Image", nullptr));
        actionHessian->setText(QApplication::translate("VolumeViewer", "Hessian", nullptr));
        actionOpen->setText(QApplication::translate("VolumeViewer", "Volume", nullptr));
        actionAdd->setText(QApplication::translate("VolumeViewer", "Add", nullptr));
        actionRay_Cast_Texture->setText(QApplication::translate("VolumeViewer", "Ray Cast & Texture", nullptr));
        actionNearest->setText(QApplication::translate("VolumeViewer", "Nearest", nullptr));
        actionLinear->setText(QApplication::translate("VolumeViewer", "Linear", nullptr));
        actionCubic->setText(QApplication::translate("VolumeViewer", "Cubic", nullptr));
        actionImage_Sequence->setText(QApplication::translate("VolumeViewer", "Image Sequence", nullptr));
        actionGreen->setText(QApplication::translate("VolumeViewer", "Green", nullptr));
        actionLoadLUT->setText(QApplication::translate("VolumeViewer", "Load", nullptr));
        actionAxes->setText(QApplication::translate("VolumeViewer", "Axes", nullptr));
        actionAnaglyph->setText(QApplication::translate("VolumeViewer", "Anaglyph", nullptr));
        actionRed_Blue->setText(QApplication::translate("VolumeViewer", "Red-Blue", nullptr));
        actionInterlaced->setText(QApplication::translate("VolumeViewer", "Interlaced", nullptr));
        actionUpsample->setText(QApplication::translate("VolumeViewer", "Upsample", nullptr));
        actionCrop->setText(QApplication::translate("VolumeViewer", "Crop", nullptr));
        actionOptions->setText(QApplication::translate("VolumeViewer", "Options", nullptr));
        actionThreshold->setText(QApplication::translate("VolumeViewer", "Threshold", nullptr));
        actionReslice->setText(QApplication::translate("VolumeViewer", "Reslice", nullptr));
        actionTime_Sequence->setText(QApplication::translate("VolumeViewer", "Time Sequence", nullptr));
        clear->setText(QApplication::translate("VolumeViewer", "Clear", nullptr));
        label->setText(QString());
        menuFile->setTitle(QApplication::translate("VolumeViewer", "File", nullptr));
        menuSave->setTitle(QApplication::translate("VolumeViewer", "Save", nullptr));
        menuLoad->setTitle(QApplication::translate("VolumeViewer", "Load", nullptr));
        menuTool->setTitle(QApplication::translate("VolumeViewer", "Tools", nullptr));
        menuPalette->setTitle(QApplication::translate("VolumeViewer", "Palette", nullptr));
        menuPreset->setTitle(QApplication::translate("VolumeViewer", "Preset", nullptr));
        menuRendering->setTitle(QApplication::translate("VolumeViewer", "Rendering", nullptr));
        menuInterpolation->setTitle(QApplication::translate("VolumeViewer", "Interpolation", nullptr));
        menuHelp->setTitle(QApplication::translate("VolumeViewer", "Help", nullptr));
        menuView->setTitle(QApplication::translate("VolumeViewer", "View", nullptr));
        menuVolume->setTitle(QApplication::translate("VolumeViewer", "Volume ", nullptr));
        menuStereo->setTitle(QApplication::translate("VolumeViewer", "Stereo", nullptr));
        menuFilters->setTitle(QApplication::translate("VolumeViewer", "Filters", nullptr));
        menuVolume_filter->setTitle(QApplication::translate("VolumeViewer", "Volume", nullptr));
        menuImage_filter->setTitle(QApplication::translate("VolumeViewer", "Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VolumeViewer: public Ui_VolumeViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUMEVIEWER_H
