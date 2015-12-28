/****************************************************************************
** Meta object code from reading C++ file 'dialog_tfn.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialog_tfn.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_tfn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_dialog_tfn_t {
    QByteArrayData data[15];
    char stringdata[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dialog_tfn_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dialog_tfn_t qt_meta_stringdata_dialog_tfn = {
    {
QT_MOC_LITERAL(0, 0, 10), // "dialog_tfn"
QT_MOC_LITERAL(1, 11, 7), // "sendtfn"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 17), // "on_addrow_clicked"
QT_MOC_LITERAL(4, 38, 17), // "on_delrow_clicked"
QT_MOC_LITERAL(5, 56, 15), // "on_save_clicked"
QT_MOC_LITERAL(6, 72, 17), // "on_settfn_clicked"
QT_MOC_LITERAL(7, 90, 10), // "mousePress"
QT_MOC_LITERAL(8, 101, 12), // "QMouseEvent*"
QT_MOC_LITERAL(9, 114, 6), // "mevent"
QT_MOC_LITERAL(10, 121, 9), // "mouseMove"
QT_MOC_LITERAL(11, 131, 12), // "mouseRelease"
QT_MOC_LITERAL(12, 144, 8), // "plothist"
QT_MOC_LITERAL(13, 153, 15), // "QVector<double>"
QT_MOC_LITERAL(14, 169, 4) // "freq"

    },
    "dialog_tfn\0sendtfn\0\0on_addrow_clicked\0"
    "on_delrow_clicked\0on_save_clicked\0"
    "on_settfn_clicked\0mousePress\0QMouseEvent*\0"
    "mevent\0mouseMove\0mouseRelease\0plothist\0"
    "QVector<double>\0freq"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dialog_tfn[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   62,    2, 0x08 /* Private */,
       4,    0,   63,    2, 0x08 /* Private */,
       5,    0,   64,    2, 0x08 /* Private */,
       6,    0,   65,    2, 0x08 /* Private */,
       7,    1,   66,    2, 0x08 /* Private */,
      10,    1,   69,    2, 0x08 /* Private */,
      11,    1,   72,    2, 0x08 /* Private */,
      12,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void dialog_tfn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dialog_tfn *_t = static_cast<dialog_tfn *>(_o);
        switch (_id) {
        case 0: _t->sendtfn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_addrow_clicked(); break;
        case 2: _t->on_delrow_clicked(); break;
        case 3: _t->on_save_clicked(); break;
        case 4: _t->on_settfn_clicked(); break;
        case 5: _t->mousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->mouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->mouseRelease((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 8: _t->plothist((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (dialog_tfn::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dialog_tfn::sendtfn)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject dialog_tfn::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dialog_tfn.data,
      qt_meta_data_dialog_tfn,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *dialog_tfn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dialog_tfn::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_dialog_tfn.stringdata))
        return static_cast<void*>(const_cast< dialog_tfn*>(this));
    return QDialog::qt_metacast(_clname);
}

int dialog_tfn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void dialog_tfn::sendtfn(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
