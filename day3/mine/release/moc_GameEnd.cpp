/****************************************************************************
** Meta object code from reading C++ file 'GameEnd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GameEnd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameEnd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameEnd_t {
    QByteArrayData data[4];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameEnd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameEnd_t qt_meta_stringdata_GameEnd = {
    {
QT_MOC_LITERAL(0, 0, 7), // "GameEnd"
QT_MOC_LITERAL(1, 8, 8), // "win_show"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 9) // "lost_show"

    },
    "GameEnd\0win_show\0\0lost_show"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameEnd[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameEnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameEnd *_t = static_cast<GameEnd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->win_show(); break;
        case 1: _t->lost_show(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GameEnd::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GameEnd.data,
      qt_meta_data_GameEnd,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameEnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameEnd::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameEnd.stringdata0))
        return static_cast<void*>(const_cast< GameEnd*>(this));
    return QDialog::qt_metacast(_clname);
}

int GameEnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
