/****************************************************************************
** Meta object code from reading C++ file 'FrontDoor.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FrontDoor.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrontDoor.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrontDoorPanel_t {
    QByteArrayData data[9];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrontDoorPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrontDoorPanel_t qt_meta_stringdata_FrontDoorPanel = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FrontDoorPanel"
QT_MOC_LITERAL(1, 15, 11), // "b_key_click"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "b_call_click"
QT_MOC_LITERAL(4, 41, 16), // "record_open_door"
QT_MOC_LITERAL(5, 58, 3), // "key"
QT_MOC_LITERAL(6, 62, 16), // "record_wrong_key"
QT_MOC_LITERAL(7, 79, 10), // "b_key_slot"
QT_MOC_LITERAL(8, 90, 11) // "b_call_slot"

    },
    "FrontDoorPanel\0b_key_click\0\0b_call_click\0"
    "record_open_door\0key\0record_wrong_key\0"
    "b_key_slot\0b_call_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrontDoorPanel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    1,   46,    2, 0x06 /* Public */,
       6,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   52,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrontDoorPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrontDoorPanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->b_key_click(); break;
        case 1: _t->b_call_click(); break;
        case 2: _t->record_open_door((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->record_wrong_key((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->b_key_slot(); break;
        case 5: _t->b_call_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FrontDoorPanel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrontDoorPanel::b_key_click)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FrontDoorPanel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrontDoorPanel::b_call_click)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FrontDoorPanel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrontDoorPanel::record_open_door)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FrontDoorPanel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrontDoorPanel::record_wrong_key)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrontDoorPanel::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FrontDoorPanel.data,
    qt_meta_data_FrontDoorPanel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrontDoorPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrontDoorPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrontDoorPanel.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FrontDoorPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FrontDoorPanel::b_key_click()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FrontDoorPanel::b_call_click()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FrontDoorPanel::record_open_door(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FrontDoorPanel::record_wrong_key(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
