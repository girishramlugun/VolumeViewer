/****************************************************************************
** Meta object code from reading C++ file 'VolumeViewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VolumeViewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VolumeViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VolumeViewer_t {
    QByteArrayData data[70];
    char stringdata0[1420];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VolumeViewer_t, stringdata0) + ofs \
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
QT_MOC_LITERAL(14, 137, 10), // "vtkNotUsed"
QT_MOC_LITERAL(15, 148, 16), // "on_clear_clicked"
QT_MOC_LITERAL(16, 165, 23), // "on_actionAxes_triggered"
QT_MOC_LITERAL(17, 189, 30), // "on_actionGPU_Texture_triggered"
QT_MOC_LITERAL(18, 220, 27), // "on_actionRay_Cast_triggered"
QT_MOC_LITERAL(19, 248, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(20, 272, 25), // "on_actionExit_2_triggered"
QT_MOC_LITERAL(21, 298, 29), // "on_actionBackground_triggered"
QT_MOC_LITERAL(22, 328, 25), // "on_actionCustom_triggered"
QT_MOC_LITERAL(23, 354, 24), // "on_actionImage_triggered"
QT_MOC_LITERAL(24, 379, 23), // "on_actionGrey_triggered"
QT_MOC_LITERAL(25, 403, 26), // "on_actionHessian_triggered"
QT_MOC_LITERAL(26, 430, 27), // "on_actionFibrosis_triggered"
QT_MOC_LITERAL(27, 458, 22), // "on_actionAdd_triggered"
QT_MOC_LITERAL(28, 481, 25), // "on_actionR_to_B_triggered"
QT_MOC_LITERAL(29, 507, 24), // "on_actionGreen_triggered"
QT_MOC_LITERAL(30, 532, 25), // "on_actionB_to_R_triggered"
QT_MOC_LITERAL(31, 558, 26), // "on_actionOptions_triggered"
QT_MOC_LITERAL(32, 585, 34), // "on_actionSave_Screenshot_trig..."
QT_MOC_LITERAL(33, 620, 25), // "on_actionRotate_triggered"
QT_MOC_LITERAL(34, 646, 33), // "on_actionImage_Sequence_trigg..."
QT_MOC_LITERAL(35, 680, 23), // "on_actionClip_triggered"
QT_MOC_LITERAL(36, 704, 29), // "on_actionDimensions_triggered"
QT_MOC_LITERAL(37, 734, 25), // "on_actionLights_triggered"
QT_MOC_LITERAL(38, 760, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(39, 785, 26), // "on_actionOpacity_triggered"
QT_MOC_LITERAL(40, 812, 24), // "on_actionSlice_triggered"
QT_MOC_LITERAL(41, 837, 30), // "on_actionSave_Volume_triggered"
QT_MOC_LITERAL(42, 868, 24), // "on_actionColor_triggered"
QT_MOC_LITERAL(43, 893, 29), // "on_actionIsosurface_triggered"
QT_MOC_LITERAL(44, 923, 26), // "on_actionNearest_triggered"
QT_MOC_LITERAL(45, 950, 25), // "on_actionLinear_triggered"
QT_MOC_LITERAL(46, 976, 24), // "on_actionCubic_triggered"
QT_MOC_LITERAL(47, 1001, 26), // "on_actionLoadLUT_triggered"
QT_MOC_LITERAL(48, 1028, 27), // "on_actionAnaglyph_triggered"
QT_MOC_LITERAL(49, 1056, 27), // "on_actionRed_Blue_triggered"
QT_MOC_LITERAL(50, 1084, 29), // "on_actionInterlaced_triggered"
QT_MOC_LITERAL(51, 1114, 23), // "on_actionCrop_triggered"
QT_MOC_LITERAL(52, 1138, 9), // "doHessian"
QT_MOC_LITERAL(53, 1148, 28), // "on_actionThreshold_triggered"
QT_MOC_LITERAL(54, 1177, 9), // "setthresh"
QT_MOC_LITERAL(55, 1187, 14), // "generatefibres"
QT_MOC_LITERAL(56, 1202, 6), // "string"
QT_MOC_LITERAL(57, 1209, 9), // "setfibres"
QT_MOC_LITERAL(58, 1219, 30), // "on_actionHelp_Topics_triggered"
QT_MOC_LITERAL(59, 1250, 13), // "getfileprefix"
QT_MOC_LITERAL(60, 1264, 21), // "mxArrayTovtkDataArray"
QT_MOC_LITERAL(61, 1286, 13), // "vtkDataArray*"
QT_MOC_LITERAL(62, 1300, 14), // "const mxArray*"
QT_MOC_LITERAL(63, 1315, 3), // "mxa"
QT_MOC_LITERAL(64, 1319, 11), // "ShallowCopy"
QT_MOC_LITERAL(65, 1331, 14), // "GetVTKDataType"
QT_MOC_LITERAL(66, 1346, 9), // "mxClassID"
QT_MOC_LITERAL(67, 1356, 3), // "cid"
QT_MOC_LITERAL(68, 1360, 26), // "on_actionReslice_triggered"
QT_MOC_LITERAL(69, 1387, 32) // "on_actionTime_Sequence_triggered"

    },
    "VolumeViewer\0vramsize\0\0gpinf\0slotExit\0"
    "rot\0setvolcol\0updateopacity\0rmovstat\0"
    "getgpuinfo\0vram\0process\0"
    "vtkMultiProcessController*\0controller\0"
    "vtkNotUsed\0on_clear_clicked\0"
    "on_actionAxes_triggered\0"
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
    "getfileprefix\0mxArrayTovtkDataArray\0"
    "vtkDataArray*\0const mxArray*\0mxa\0"
    "ShallowCopy\0GetVTKDataType\0mxClassID\0"
    "cid\0on_actionReslice_triggered\0"
    "on_actionTime_Sequence_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VolumeViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      57,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  299,    2, 0x06 /* Public */,
       3,    1,  302,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  305,    2, 0x0a /* Public */,
       5,    0,  306,    2, 0x0a /* Public */,
       6,    1,  307,    2, 0x0a /* Public */,
       7,    2,  310,    2, 0x0a /* Public */,
       8,    1,  315,    2, 0x0a /* Public */,
       9,    1,  318,    2, 0x0a /* Public */,
      11,    2,  321,    2, 0x0a /* Public */,
      15,    0,  326,    2, 0x08 /* Private */,
      16,    0,  327,    2, 0x08 /* Private */,
      17,    0,  328,    2, 0x08 /* Private */,
      18,    0,  329,    2, 0x08 /* Private */,
      19,    0,  330,    2, 0x08 /* Private */,
      20,    0,  331,    2, 0x08 /* Private */,
      21,    0,  332,    2, 0x08 /* Private */,
      22,    0,  333,    2, 0x08 /* Private */,
      23,    0,  334,    2, 0x08 /* Private */,
      24,    0,  335,    2, 0x08 /* Private */,
      25,    0,  336,    2, 0x08 /* Private */,
      26,    0,  337,    2, 0x08 /* Private */,
      27,    0,  338,    2, 0x08 /* Private */,
      28,    0,  339,    2, 0x08 /* Private */,
      29,    0,  340,    2, 0x08 /* Private */,
      30,    0,  341,    2, 0x08 /* Private */,
      31,    0,  342,    2, 0x08 /* Private */,
      32,    0,  343,    2, 0x08 /* Private */,
      33,    0,  344,    2, 0x08 /* Private */,
      34,    0,  345,    2, 0x08 /* Private */,
      35,    0,  346,    2, 0x08 /* Private */,
      36,    0,  347,    2, 0x08 /* Private */,
      37,    0,  348,    2, 0x08 /* Private */,
      38,    0,  349,    2, 0x08 /* Private */,
      39,    0,  350,    2, 0x08 /* Private */,
      40,    0,  351,    2, 0x08 /* Private */,
      41,    0,  352,    2, 0x08 /* Private */,
      42,    0,  353,    2, 0x08 /* Private */,
      43,    0,  354,    2, 0x08 /* Private */,
      44,    0,  355,    2, 0x08 /* Private */,
      45,    0,  356,    2, 0x08 /* Private */,
      46,    0,  357,    2, 0x08 /* Private */,
      47,    0,  358,    2, 0x08 /* Private */,
      48,    0,  359,    2, 0x08 /* Private */,
      49,    0,  360,    2, 0x08 /* Private */,
      50,    0,  361,    2, 0x08 /* Private */,
      51,    0,  362,    2, 0x08 /* Private */,
      52,    3,  363,    2, 0x08 /* Private */,
      53,    0,  370,    2, 0x08 /* Private */,
      54,    2,  371,    2, 0x08 /* Private */,
      55,    3,  376,    2, 0x08 /* Private */,
      57,    2,  383,    2, 0x08 /* Private */,
      58,    0,  388,    2, 0x08 /* Private */,
      59,    1,  389,    2, 0x08 /* Private */,
      60,    2,  392,    2, 0x08 /* Private */,
      65,    1,  397,    2, 0x08 /* Private */,
      68,    0,  400,    2, 0x08 /* Private */,
      69,    0,  401,    2, 0x08 /* Private */,

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
    QMetaType::Void, 0x80000000 | 12, QMetaType::VoidStar,   13,   14,
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
    QMetaType::Void, 0x80000000 | 56, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    0x80000000 | 61, 0x80000000 | 62, QMetaType::Bool,   63,   64,
    0x80000000 | 61, 0x80000000 | 66,   67,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VolumeViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VolumeViewer *_t = static_cast<VolumeViewer *>(_o);
        Q_UNUSED(_t)
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
        case 53: { vtkDataArray* _r = _t->mxArrayTovtkDataArray((*reinterpret_cast< const mxArray*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< vtkDataArray**>(_a[0]) = std::move(_r); }  break;
        case 54: { vtkDataArray* _r = _t->GetVTKDataType((*reinterpret_cast< mxClassID(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vtkDataArray**>(_a[0]) = std::move(_r); }  break;
        case 55: _t->on_actionReslice_triggered(); break;
        case 56: _t->on_actionTime_Sequence_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VolumeViewer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VolumeViewer::vramsize)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VolumeViewer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VolumeViewer::gpinf)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VolumeViewer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VolumeViewer.data,
      qt_meta_data_VolumeViewer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VolumeViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VolumeViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VolumeViewer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int VolumeViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 57)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 57)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 57;
    }
    return _id;
}

// SIGNAL 0
void VolumeViewer::vramsize(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VolumeViewer::gpinf(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
