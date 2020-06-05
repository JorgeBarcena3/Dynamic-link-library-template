/****************************************************************************
** Meta object code from reading C++ file 'MenuActions.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../code/headers/MenuActions.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MenuActions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MenuActions_t {
    QByteArrayData data[15];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuActions_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuActions_t qt_meta_stringdata_MenuActions = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MenuActions"
QT_MOC_LITERAL(1, 12, 4), // "load"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 9), // "triggered"
QT_MOC_LITERAL(4, 28, 4), // "save"
QT_MOC_LITERAL(5, 33, 6), // "saveAs"
QT_MOC_LITERAL(6, 40, 9), // "exportXML"
QT_MOC_LITERAL(7, 50, 9), // "importXML"
QT_MOC_LITERAL(8, 60, 10), // "openGitHub"
QT_MOC_LITERAL(9, 71, 12), // "openLinkedin"
QT_MOC_LITERAL(10, 84, 17), // "executeLuaCommand"
QT_MOC_LITERAL(11, 102, 14), // "executeLuaFile"
QT_MOC_LITERAL(12, 117, 7), // "newFile"
QT_MOC_LITERAL(13, 125, 16), // "closeApplication"
QT_MOC_LITERAL(14, 142, 11) // "removePanel"

    },
    "MenuActions\0load\0\0triggered\0save\0"
    "saveAs\0exportXML\0importXML\0openGitHub\0"
    "openLinkedin\0executeLuaCommand\0"
    "executeLuaFile\0newFile\0closeApplication\0"
    "removePanel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuActions[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       4,    1,   77,    2, 0x0a /* Public */,
       5,    1,   80,    2, 0x0a /* Public */,
       6,    1,   83,    2, 0x0a /* Public */,
       7,    1,   86,    2, 0x0a /* Public */,
       8,    1,   89,    2, 0x0a /* Public */,
       9,    1,   92,    2, 0x0a /* Public */,
      10,    1,   95,    2, 0x0a /* Public */,
      11,    1,   98,    2, 0x0a /* Public */,
      12,    1,  101,    2, 0x0a /* Public */,
      13,    0,  104,    2, 0x0a /* Public */,
      14,    1,  105,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void MenuActions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MenuActions *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->load((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->save((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->saveAs((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->exportXML((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->importXML((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->openGitHub((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->openLinkedin((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->executeLuaCommand((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->executeLuaFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->newFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->closeApplication(); break;
        case 11: _t->removePanel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MenuActions::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MenuActions.data,
    qt_meta_data_MenuActions,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MenuActions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuActions::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MenuActions.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MenuActions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
