/****************************************************************************
** Meta object code from reading C++ file 'mineButton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mineButton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mineButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mineButton_t {
    QByteArrayData data[6];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mineButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mineButton_t qt_meta_stringdata_mineButton = {
    {
QT_MOC_LITERAL(0, 0, 10), // "mineButton"
QT_MOC_LITERAL(1, 11, 12), // "return_style"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "find_mine"
QT_MOC_LITERAL(4, 35, 8), // "get_mine"
QT_MOC_LITERAL(5, 44, 9) // "NO_button"

    },
    "mineButton\0return_style\0\0find_mine\0"
    "get_mine\0NO_button"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mineButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void mineButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mineButton *_t = static_cast<mineButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->return_style(); break;
        case 1: _t->find_mine(); break;
        case 2: _t->get_mine(); break;
        case 3: _t->NO_button((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (mineButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mineButton::return_style)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (mineButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mineButton::find_mine)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (mineButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mineButton::get_mine)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (mineButton::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mineButton::NO_button)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject mineButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_mineButton.data,
      qt_meta_data_mineButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mineButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mineButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mineButton.stringdata0))
        return static_cast<void*>(const_cast< mineButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int mineButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void mineButton::return_style()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void mineButton::find_mine()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void mineButton::get_mine()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void mineButton::NO_button(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
