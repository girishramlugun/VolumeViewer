/****************************************************************************
** Meta object code from reading C++ file 'dialog_vol_prop.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialog_vol_prop.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_vol_prop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_dialog_vol_prop_t {
    QByteArrayData data[5];
    char stringdata[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dialog_vol_prop_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dialog_vol_prop_t qt_meta_stringdata_dialog_vol_prop = {
    {
QT_MOC_LITERAL(0, 0, 15), // "dialog_vol_prop"
QT_MOC_LITERAL(1, 16, 9), // "send_dims"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 22), // "on_set_vol_dim_clicked"
QT_MOC_LITERAL(4, 50, 10) // "update_dim"

    },
    "dialog_vol_prop\0send_dims\0\0"
    "on_set_vol_dim_clicked\0update_dim"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dialog_vol_prop[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   36,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dialog_vol_prop::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dialog_vol_prop *_t = static_cast<dialog_vol_prop *>(_o);
        switch (_id) {
        case 0: _t->send_dims((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 1: _t->on_set_vol_dim_clicked(); break;
        case 2: _t->update_dim(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (dialog_vol_prop::*_t)(double , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dialog_vol_prop::send_dims)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject dialog_vol_prop::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dialog_vol_prop.data,
      qt_meta_data_dialog_vol_prop,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *dialog_vol_prop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dialog_vol_prop::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_dialog_vol_prop.stringdata))
        return static_cast<void*>(const_cast< dialog_vol_prop*>(this));
    return QDialog::qt_metacast(_clname);
}

int dialog_vol_prop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void dialog_vol_prop::send_dims(double _t1, double _t2, double _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
