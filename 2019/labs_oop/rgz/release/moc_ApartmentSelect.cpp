/****************************************************************************
** Meta object code from reading C++ file 'ApartmentSelect.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ApartmentSelect.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ApartmentSelect.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ApartmentSelect_t {
    QByteArrayData data[11];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ApartmentSelect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ApartmentSelect_t qt_meta_stringdata_ApartmentSelect = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ApartmentSelect"
QT_MOC_LITERAL(1, 16, 9), // "open_door"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "apart"
QT_MOC_LITERAL(4, 33, 9), // "open_conn"
QT_MOC_LITERAL(5, 43, 10), // "close_conn"
QT_MOC_LITERAL(6, 54, 17), // "show_apart_window"
QT_MOC_LITERAL(7, 72, 3), // "num"
QT_MOC_LITERAL(8, 76, 15), // "apart_open_door"
QT_MOC_LITERAL(9, 92, 15), // "apart_open_conn"
QT_MOC_LITERAL(10, 108, 16) // "apart_close_conn"

    },
    "ApartmentSelect\0open_door\0\0apart\0"
    "open_conn\0close_conn\0show_apart_window\0"
    "num\0apart_open_door\0apart_open_conn\0"
    "apart_close_conn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApartmentSelect[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       5,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   58,    2, 0x0a /* Public */,
       8,    1,   61,    2, 0x0a /* Public */,
       9,    1,   64,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void ApartmentSelect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ApartmentSelect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->open_door((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->open_conn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->close_conn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->show_apart_window((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->apart_open_door((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->apart_open_conn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->apart_close_conn((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ApartmentSelect::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApartmentSelect::open_door)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ApartmentSelect::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApartmentSelect::open_conn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ApartmentSelect::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApartmentSelect::close_conn)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ApartmentSelect::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ApartmentSelect.data,
    qt_meta_data_ApartmentSelect,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ApartmentSelect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApartmentSelect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ApartmentSelect.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ApartmentSelect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ApartmentSelect::open_door(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ApartmentSelect::open_conn(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ApartmentSelect::close_conn(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
