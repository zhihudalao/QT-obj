/****************************************************************************
** Meta object code from reading C++ file 'mineGame.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mineGame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mineGame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mineGame_t {
    QByteArrayData data[5];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mineGame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mineGame_t qt_meta_stringdata_mineGame = {
    {
QT_MOC_LITERAL(0, 0, 8), // "mineGame"
QT_MOC_LITERAL(1, 9, 9), // "new_level"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "show_help"
QT_MOC_LITERAL(4, 30, 13) // "show_calcuate"

    },
    "mineGame\0new_level\0\0show_help\0"
    "show_calcuate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mineGame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mineGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mineGame *_t = static_cast<mineGame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->new_level(); break;
        case 1: _t->show_help(); break;
        case 2: _t->show_calcuate(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject mineGame::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mineGame.data,
      qt_meta_data_mineGame,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mineGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mineGame::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mineGame.stringdata0))
        return static_cast<void*>(const_cast< mineGame*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int mineGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
