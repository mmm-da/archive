/****************************************************************************
** Meta object code from reading C++ file 'LogWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LogWindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LogWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogWindow_t {
    QByteArrayData data[10];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogWindow_t qt_meta_stringdata_LogWindow = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LogWindow"
QT_MOC_LITERAL(1, 10, 8), // "save_log"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 16), // "record_open_door"
QT_MOC_LITERAL(4, 37, 9), // "apart_num"
QT_MOC_LITERAL(5, 47, 19), // "record_connect_open"
QT_MOC_LITERAL(6, 67, 20), // "record_connect_close"
QT_MOC_LITERAL(7, 88, 20), // "record_open_with_key"
QT_MOC_LITERAL(8, 109, 3), // "key"
QT_MOC_LITERAL(9, 113, 16) // "record_wrong_key"

    },
    "LogWindow\0save_log\0\0record_open_door\0"
    "apart_num\0record_connect_open\0"
    "record_connect_close\0record_open_with_key\0"
    "key\0record_wrong_key"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x0a /* Public */,
       6,    1,   51,    2, 0x0a /* Public */,
       7,    1,   54,    2, 0x0a /* Public */,
       9,    1,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void LogWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LogWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->save_log(); break;
        case 1: _t->record_open_door((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->record_connect_open((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->record_connect_close((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->record_open_with_key((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->record_wrong_key((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LogWindow::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_LogWindow.data,
    qt_meta_data_LogWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LogWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LogWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LogWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
