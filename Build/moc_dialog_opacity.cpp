/****************************************************************************
** Meta object code from reading C++ file 'dialog_opacity.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialog_opacity.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_opacity.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dialog_opacity_t {
    QByteArrayData data[9];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dialog_opacity_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dialog_opacity_t qt_meta_stringdata_dialog_opacity = {
    {
QT_MOC_LITERAL(0, 0, 14), // "dialog_opacity"
QT_MOC_LITERAL(1, 15, 7), // "sendopa"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 17), // "on_Addrow_clicked"
QT_MOC_LITERAL(4, 42, 20), // "on_Removerow_clicked"
QT_MOC_LITERAL(5, 63, 19), // "on_bboxopa_accepted"
QT_MOC_LITERAL(6, 83, 7), // "plotopa"
QT_MOC_LITERAL(7, 91, 17), // "on_SetOpa_clicked"
QT_MOC_LITERAL(8, 109, 18) // "on_ColChan_toggled"

    },
    "dialog_opacity\0sendopa\0\0on_Addrow_clicked\0"
    "on_Removerow_clicked\0on_bboxopa_accepted\0"
    "plotopa\0on_SetOpa_clicked\0on_ColChan_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dialog_opacity[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   54,    2, 0x08 /* Private */,
       4,    0,   55,    2, 0x08 /* Private */,
       5,    0,   56,    2, 0x08 /* Private */,
       6,    0,   57,    2, 0x08 /* Private */,
       7,    0,   58,    2, 0x08 /* Private */,
       8,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void dialog_opacity::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dialog_opacity *_t = static_cast<dialog_opacity *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendopa((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->on_Addrow_clicked(); break;
        case 2: _t->on_Removerow_clicked(); break;
        case 3: _t->on_bboxopa_accepted(); break;
        case 4: _t->plotopa(); break;
        case 5: _t->on_SetOpa_clicked(); break;
        case 6: _t->on_ColChan_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (dialog_opacity::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dialog_opacity::sendopa)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dialog_opacity::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dialog_opacity.data,
      qt_meta_data_dialog_opacity,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *dialog_opacity::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dialog_opacity::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dialog_opacity.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int dialog_opacity::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void dialog_opacity::sendopa(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
