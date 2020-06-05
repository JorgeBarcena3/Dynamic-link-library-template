/****************************************************************************
** Meta object code from reading C++ file 'QTaskWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../code/headers/QTaskWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QTaskWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QTaskWidget_t {
    QByteArrayData data[8];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTaskWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTaskWidget_t qt_meta_stringdata_QTaskWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QTaskWidget"
QT_MOC_LITERAL(1, 12, 15), // "edit_task_title"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 9), // "triggered"
QT_MOC_LITERAL(4, 39, 15), // "change_to_panel"
QT_MOC_LITERAL(5, 55, 11), // "remove_task"
QT_MOC_LITERAL(6, 67, 13), // "edit_assigned"
QT_MOC_LITERAL(7, 81, 16) // "edit_description"

    },
    "QTaskWidget\0edit_task_title\0\0triggered\0"
    "change_to_panel\0remove_task\0edit_assigned\0"
    "edit_description"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTaskWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       5,    1,   45,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void QTaskWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QTaskWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->edit_task_title((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->change_to_panel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->remove_task((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->edit_assigned((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->edit_description((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QTaskWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QTaskWidget.data,
    qt_meta_data_QTaskWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QTaskWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTaskWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QTaskWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QTaskWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
