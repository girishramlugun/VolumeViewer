/****************************************************************************
** Meta object code from reading C++ file 'VolumeViewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VolumeViewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VolumeViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VolumeViewer_t {
    QByteArrayData data[61];
    char stringdata[1313];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VolumeViewer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VolumeViewer_t qt_meta_stringdata_VolumeViewer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "VolumeViewer"
QT_MOC_LITERAL(1, 13, 8), // "vramsize"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "gpinf"
QT_MOC_LITERAL(4, 29, 8), // "slotExit"
QT_MOC_LITERAL(5, 38, 3), // "rot"
QT_MOC_LITERAL(6, 42, 9), // "setvolcol"
QT_MOC_LITERAL(7, 52, 13), // "updateopacity"
QT_MOC_LITERAL(8, 66, 8), // "rmovstat"
QT_MOC_LITERAL(9, 75, 10), // "getgpuinfo"
QT_MOC_LITERAL(10, 86, 4), // "vram"
QT_MOC_LITERAL(11, 91, 7), // "process"
QT_MOC_LITERAL(12, 99, 26), // "vtkMultiProcessController*"
QT_MOC_LITERAL(13, 126, 10), // "controller"
QT_MOC_LITERAL(14, 137, 16), // "on_clear_clicked"
QT_MOC_LITERAL(15, 154, 23), // "on_actionAxes_triggered"
QT_MOC_LITERAL(16, 178, 30), // "on_actionGPU_Texture_triggered"
QT_MOC_LITERAL(17, 209, 27), // "on_actionRay_Cast_triggered"
QT_MOC_LITERAL(18, 237, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(19, 261, 25), // "on_actionExit_2_triggered"
QT_MOC_LITERAL(20, 287, 29), // "on_actionBackground_triggered"
QT_MOC_LITERAL(21, 317, 25), // "on_actionCustom_triggered"
QT_MOC_LITERAL(22, 343, 24), // "on_actionImage_triggered"
QT_MOC_LITERAL(23, 368, 23), // "on_actionGrey_triggered"
QT_MOC_LITERAL(24, 392, 26), // "on_actionHessian_triggered"
QT_MOC_LITERAL(25, 419, 27), // "on_actionFibrosis_triggered"
QT_MOC_LITERAL(26, 447, 22), // "on_actionAdd_triggered"
QT_MOC_LITERAL(27, 470, 25), // "on_actionR_to_B_triggered"
QT_MOC_LITERAL(28, 496, 24), // "on_actionGreen_triggered"
QT_MOC_LITERAL(29, 521, 25), // "on_actionB_to_R_triggered"
QT_MOC_LITERAL(30, 547, 26), // "on_actionOptions_triggered"
QT_MOC_LITERAL(31, 574, 34), // "on_actionSave_Screenshot_trig..."
QT_MOC_LITERAL(32, 609, 25), // "on_actionRotate_triggered"
QT_MOC_LITERAL(33, 635, 33), // "on_actionImage_Sequence_trigg..."
QT_MOC_LITERAL(34, 669, 23), // "on_actionClip_triggered"
QT_MOC_LITERAL(35, 693, 29), // "on_actionDimensions_triggered"
QT_MOC_LITERAL(36, 723, 25), // "on_actionLights_triggered"
QT_MOC_LITERAL(37, 749, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(38, 774, 26), // "on_actionOpacity_triggered"
QT_MOC_LITERAL(39, 801, 24), // "on_actionSlice_triggered"
QT_MOC_LITERAL(40, 826, 30), // "on_actionSave_Volume_triggered"
QT_MOC_LITERAL(41, 857, 24), // "on_actionColor_triggered"
QT_MOC_LITERAL(42, 882, 29), // "on_actionIsosurface_triggered"
QT_MOC_LITERAL(43, 912, 26), // "on_actionNearest_triggered"
QT_MOC_LITERAL(44, 939, 25), // "on_actionLinear_triggered"
QT_MOC_LITERAL(45, 965, 24), // "on_actionCubic_triggered"
QT_MOC_LITERAL(46, 990, 26), // "on_actionLoadLUT_triggered"
QT_MOC_LITERAL(47, 1017, 27), // "on_actionAnaglyph_triggered"
QT_MOC_LITERAL(48, 1045, 27), // "on_actionRed_Blue_triggered"
QT_MOC_LITERAL(49, 1073, 29), // "on_actionInterlaced_triggered"
QT_MOC_LITERAL(50, 1103, 23), // "on_actionCrop_triggered"
QT_MOC_LITERAL(51, 1127, 9), // "doHessian"
QT_MOC_LITERAL(52, 1137, 28), // "on_actionThreshold_triggered"
QT_MOC_LITERAL(53, 1166, 9), // "setthresh"
QT_MOC_LITERAL(54, 1176, 14), // "generatefibres"
QT_MOC_LITERAL(55, 1191, 6), // "string"
QT_MOC_LITERAL(56, 1198, 9), // "setfibres"
QT_MOC_LITERAL(57, 1208, 30), // "on_actionHelp_Topics_triggered"
QT_MOC_LITERAL(58, 1239, 13), // "getfileprefix"
QT_MOC_LITERAL(59, 1253, 26), // "on_actionReslice_triggered"
QT_MOC_LITERAL(60, 1280, 32) // "on_actionTime_Sequence_triggered"

    },
    "VolumeViewer\0vramsize\0\0gpinf\0slotExit\0"
    "rot\0setvolcol\0updateopacity\0rmovstat\0"
    "getgpuinfo\0vram\0process\0"
    "vtkMultiProcessController*\0controller\0"
    "on_clear_clicked\0on_actionAxes_triggered\0"
    "on_actionGPU_Texture_triggered\0"
    "on_actionRay_Cast_triggered\0"
    "on_actionOpen_triggered\0"
    "on_actionExit_2_triggered\0"
    "on_actionBackground_triggered\0"
    "on_actionCustom_triggered\0"
    "on_actionImage_triggered\0"
    "on_actionGrey_triggered\0"
    "on_actionHessian_triggered\0"
    "on_actionFibrosis_triggered\0"
    "on_actionAdd_triggered\0on_actionR_to_B_triggered\0"
    "on_actionGreen_triggered\0"
    "on_actionB_to_R_triggered\0"
    "on_actionOptions_triggered\0"
    "on_actionSave_Screenshot_triggered\0"
    "on_actionRotate_triggered\0"
    "on_actionImage_Sequence_triggered\0"
    "on_actionClip_triggered\0"
    "on_actionDimensions_triggered\0"
    "on_actionLights_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionOpacity_triggered\0"
    "on_actionSlice_triggered\0"
    "on_actionSave_Volume_triggered\0"
    "on_actionColor_triggered\0"
    "on_actionIsosurface_triggered\0"
    "on_actionNearest_triggered\0"
    "on_actionLinear_triggered\0"
    "on_actionCubic_triggered\0"
    "on_actionLoadLUT_triggered\0"
    "on_actionAnaglyph_triggered\0"
    "on_actionRed_Blue_triggered\0"
    "on_actionInterlaced_triggered\0"
    "on_actionCrop_triggered\0doHessian\0"
    "on_actionThreshold_triggered\0setthresh\0"
    "generatefibres\0string\0setfibres\0"
    "on_actionHelp_Topics_triggered\0"
    "getfileprefix\0on_actionReslice_triggered\0"
    "on_actionTime_Sequence_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VolumeViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      55,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  289,    2, 0x06 /* Public */,
       3,    1,  292,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  295,    2, 0x0a /* Public */,
       5,    0,  296,    2, 0x0a /* Public */,
       6,    1,  297,    2, 0x0a /* Public */,
       7,    2,  300,    2, 0x0a /* Public */,
       8,    1,  305,    2, 0x0a /* Public */,
       9,    1,  308,    2, 0x0a /* Public */,
      11,    2,  311,    2, 0x0a /* Public */,
      14,    0,  316,    2, 0x08 /* Private */,
      15,    0,  317,    2, 0x08 /* Private */,
      16,    0,  318,    2, 0x08 /* Private */,
      17,    0,  319,    2, 0x08 /* Private */,
      18,    0,  320,    2, 0x08 /* Private */,
      19,    0,  321,    2, 0x08 /* Private */,
      20,    0,  322,    2, 0x08 /* Private */,
      21,    0,  323,    2, 0x08 /* Private */,
      22,    0,  324,    2, 0x08 /* Private */,
      23,    0,  325,    2, 0x08 /* Private */,
      24,    0,  326,    2, 0x08 /* Private */,
      25,    0,  327,    2, 0x08 /* Private */,
      26,    0,  328,    2, 0x08 /* Private */,
      27,    0,  329,    2, 0x08 /* Private */,
      28,    0,  330,    2, 0x08 /* Private */,
      29,    0,  331,    2, 0x08 /* Private */,
      30,    0,  332,    2, 0x08 /* Private */,
      31,    0,  333,    2, 0x08 /* Private */,
      32,    0,  334,    2, 0x08 /* Private */,
      33,    0,  335,    2, 0x08 /* Private */,
      34,    0,  336,    2, 0x08 /* Private */,
      35,    0,  337,    2, 0x08 /* Private */,
      36,    0,  338,    2, 0x08 /* Private */,
      37,    0,  339,    2, 0x08 /* Private */,
      38,    0,  340,    2, 0x08 /* Private */,
      39,    0,  341,    2, 0x08 /* Private */,
      40,    0,  342,    2, 0x08 /* Private */,
      41,    0,  343,    2, 0x08 /* Private */,
      42,    0,  344,    2, 0x08 /* Private */,
      43,    0,  345,    2, 0x08 /* Private */,
      44,    0,  346,    2, 0x08 /* Private */,
      45,    0,  347,    2, 0x08 /* Private */,
      46,    0,  348,    2, 0x08 /* Private */,
      47,    0,  349,    2, 0x08 /* Private */,
      48,    0,  350,    2, 0x08 /* Private */,
      49,    0,  351,    2, 0x08 /* Private */,
      50,    0,  352,    2, 0x08 /* Private */,
      51,    3,  353,    2, 0x08 /* Private */,
      52,    0,  360,    2, 0x08 /* Private */,
      53,    2,  361,    2, 0x08 /* Private */,
      54,    3,  366,    2, 0x08 /* Private */,
      56,    2,  373,    2, 0x08 /* Private */,
      57,    0,  378,    2, 0x08 /* Private */,
      58,    1,  379,    2, 0x08 /* Private */,
      59,    0,  382,    2, 0x08 /* Private */,
      60,    0,  383,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 12, QMetaType::VoidStar,   13,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,
    QMetaType::Void, 0x80000000 | 55, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VolumeViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VolumeViewer *_t = static_cast<VolumeViewer *>(_o);
        switch (_id) {
        case 0: _t->vramsize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->gpinf((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slotExit(); break;
        case 3: _t->rot(); break;
        case 4: _t->setvolcol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateopacity((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->rmovstat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->getgpuinfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->process((*reinterpret_cast< vtkMultiProcessController*(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2]))); break;
        case 9: _t->on_clear_clicked(); break;
        case 10: _t->on_actionAxes_triggered(); break;
        case 11: _t->on_actionGPU_Texture_triggered(); break;
        case 12: _t->on_actionRay_Cast_triggered(); break;
        case 13: _t->on_actionOpen_triggered(); break;
        case 14: _t->on_actionExit_2_triggered(); break;
        case 15: _t->on_actionBackground_triggered(); break;
        case 16: _t->on_actionCustom_triggered(); break;
        case 17: _t->on_actionImage_triggered(); break;
        case 18: _t->on_actionGrey_triggered(); break;
        case 19: _t->on_actionHessian_triggered(); break;
        case 20: _t->on_actionFibrosis_triggered(); break;
        case 21: _t->on_actionAdd_triggered(); break;
        case 22: _t->on_actionR_to_B_triggered(); break;
        case 23: _t->on_actionGreen_triggered(); break;
        case 24: _t->on_actionB_to_R_triggered(); break;
        case 25: _t->on_actionOptions_triggered(); break;
        case 26: _t->on_actionSave_Screenshot_triggered(); break;
        case 27: _t->on_actionRotate_triggered(); break;
        case 28: _t->on_actionImage_Sequence_triggered(); break;
        case 29: _t->on_actionClip_triggered(); break;
        case 30: _t->on_actionDimensions_triggered(); break;
        case 31: _t->on_actionLights_triggered(); break;
        case 32: _t->on_actionAbout_triggered(); break;
        case 33: _t->on_actionOpacity_triggered(); break;
        case 34: _t->on_actionSlice_triggered(); break;
        case 35: _t->on_actionSave_Volume_triggered(); break;
        case 36: _t->on_actionColor_triggered(); break;
        case 37: _t->on_actionIsosurface_triggered(); break;
        case 38: _t->on_actionNearest_triggered(); break;
        case 39: _t->on_actionLinear_triggered(); break;
        case 40: _t->on_actionCubic_triggered(); break;
        case 41: _t->on_actionLoadLUT_triggered(); break;
        case 42: _t->on_actionAnaglyph_triggered(); break;
        case 43: _t->on_actionRed_Blue_triggered(); break;
        case 44: _t->on_actionInterlaced_triggered(); break;
        case 45: _t->on_actionCrop_triggered(); break;
        case 46: _t->doHessian((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 47: _t->on_actionThreshold_triggered(); break;
        case 48: _t->setthresh((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 49: _t->generatefibres((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 50: _t->setfibres((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 51: _t->on_actionHelp_Topics_triggered(); break;
        case 52: _t->getfileprefix((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 53: _t->on_actionReslice_triggered(); break;
        case 54: _t->on_actionTime_Sequence_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VolumeViewer::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VolumeViewer::vramsize)) {
                *result = 0;
            }
        }
        {
            typedef void (VolumeViewer::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VolumeViewer::gpinf)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject VolumeViewer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VolumeViewer.data,
      qt_meta_data_VolumeViewer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VolumeViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VolumeViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VolumeViewer.stringdata))
        return static_cast<void*>(const_cast< VolumeViewer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VolumeViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 55)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 55;
    }
    return _id;
}

// SIGNAL 0
void VolumeViewer::vramsize(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VolumeViewer::gpinf(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
