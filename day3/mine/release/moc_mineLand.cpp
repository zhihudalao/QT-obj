/****************************************************************************
** Meta object code from reading C++ file 'mineLand.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mineLand.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mineLand.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mineLand_t {
    QByteArrayData data[10];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mineLand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mineLand_t qt_meta_stringdata_mineLand = {
    {
QT_MOC_LITERAL(0, 0, 8), // "mineLand"
QT_MOC_LITERAL(1, 9, 3), // "win"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 4), // "lost"
QT_MOC_LITERAL(4, 19, 10), // "show_empty"
QT_MOC_LITERAL(5, 30, 6), // "winner"
QT_MOC_LITERAL(6, 37, 6), // "loster"
QT_MOC_LITERAL(7, 44, 8), // "new_game"
QT_MOC_LITERAL(8, 53, 9), // "set_level"
QT_MOC_LITERAL(9, 63, 8) // "showTime"

    },
    "mineLand\0win\0\0lost\0show_empty\0winner\0"
    "loster\0new_game\0set_level\0showTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mineLand[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   56,    2, 0x0a /* Public */,
       5,    0,   59,    2, 0x0a /* Public */,
       6,    0,   60,    2, 0x0a /* Public */,
       7,    0,   61,    2, 0x0a /* Public */,
       8,    1,   62,    2, 0x0a /* Public */,
       9,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void mineLand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mineLand *_t = static_cast<mineLand *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->win(); break;
        case 1: _t->lost(); break;
        case 2: _t->show_empty((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->winner(); break;
        case 4: _t->loster(); break;
        case 5: _t->new_game(); break;
        case 6: _t->set_level((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->showTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (mineLand::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mineLand::win)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (mineLand::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mineLand::lost)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject mineLand::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_mineLand.data,
      qt_meta_data_mineLand,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mineLand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mineLand::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mineLand.stringdata0))
        return static_cast<void*>(const_cast< mineLand*>(this));
    return QDialog::qt_metacast(_clname);
}

int mineLand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void mineLand::win()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void mineLand::lost()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
