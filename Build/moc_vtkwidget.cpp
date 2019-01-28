/****************************************************************************
** Meta object code from reading C++ file 'vtkwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../vtkwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vtkwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_vtkwidget_t {
    QByteArrayData data[18];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vtkwidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vtkwidget_t qt_meta_stringdata_vtkwidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "vtkwidget"
QT_MOC_LITERAL(1, 10, 8), // "sendhist"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 36, 5), // "setbg"
QT_MOC_LITERAL(5, 42, 7), // "setdims"
QT_MOC_LITERAL(6, 50, 12), // "updatelights"
QT_MOC_LITERAL(7, 63, 12), // "updatevolcol"
QT_MOC_LITERAL(8, 76, 12), // "updatewincol"
QT_MOC_LITERAL(9, 89, 7), // "readvti"
QT_MOC_LITERAL(10, 97, 6), // "string"
QT_MOC_LITERAL(11, 104, 7), // "readtif"
QT_MOC_LITERAL(12, 112, 8), // "resample"
QT_MOC_LITERAL(13, 121, 13), // "vtkImageData*"
QT_MOC_LITERAL(14, 135, 9), // "readimseq"
QT_MOC_LITERAL(15, 145, 15), // "vtkStringArray*"
QT_MOC_LITERAL(16, 161, 9), // "buildhist"
QT_MOC_LITERAL(17, 171, 7) // "setvram"

    },
    "vtkwidget\0sendhist\0\0QVector<double>\0"
    "setbg\0setdims\0updatelights\0updatevolcol\0"
    "updatewincol\0readvti\0string\0readtif\0"
    "resample\0vtkImageData*\0readimseq\0"
    "vtkStringArray*\0buildhist\0setvram"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vtkwidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    3,   77,    2, 0x0a /* Public */,
       5,    3,   84,    2, 0x0a /* Public */,
       6,   15,   91,    2, 0x0a /* Public */,
       7,    1,  122,    2, 0x0a /* Public */,
       8,    1,  125,    2, 0x0a /* Public */,
       9,    1,  128,    2, 0x0a /* Public */,
      11,    1,  131,    2, 0x0a /* Public */,
      12,    1,  134,    2, 0x0a /* Public */,
      14,    3,  137,    2, 0x0a /* Public */,
      16,    1,  144,    2, 0x0a /* Public */,
      17,    0,  147,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 15, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,

       0        // eod
};

void vtkwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vtkwidget *_t = static_cast<vtkwidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendhist((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 1: _t->setbg((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->setdims((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 3: _t->updatelights((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< double(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10])),(*reinterpret_cast< double(*)>(_a[11])),(*reinterpret_cast< double(*)>(_a[12])),(*reinterpret_cast< double(*)>(_a[13])),(*reinterpret_cast< double(*)>(_a[14])),(*reinterpret_cast< bool(*)>(_a[15]))); break;
        case 4: _t->updatevolcol((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->updatewincol((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->readvti((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 7: _t->readtif((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 8: _t->resample((*reinterpret_cast< vtkImageData*(*)>(_a[1]))); break;
        case 9: _t->readimseq((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< vtkStringArray*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 10: _t->buildhist((*reinterpret_cast< vtkImageData*(*)>(_a[1]))); break;
        case 11: _t->setvram(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (vtkwidget::*)(QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&vtkwidget::sendhist)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject vtkwidget::staticMetaObject = {
    { &QVTKOpenGLWidget::staticMetaObject, qt_meta_stringdata_vtkwidget.data,
      qt_meta_data_vtkwidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *vtkwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vtkwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_vtkwidget.stringdata0))
        return static_cast<void*>(this);
    return QVTKOpenGLWidget::qt_metacast(_clname);
}

int vtkwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVTKOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void vtkwidget::sendhist(QVector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
