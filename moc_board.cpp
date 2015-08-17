/****************************************************************************
** Meta object code from reading C++ file 'board.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "board.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'board.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_tile__board_t {
    QByteArrayData data[9];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tile__board_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tile__board_t qt_meta_stringdata_tile__board = {
    {
QT_MOC_LITERAL(0, 0, 11), // "tile::board"
QT_MOC_LITERAL(1, 12, 4), // "move"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 5), // "index"
QT_MOC_LITERAL(4, 24, 9), // "isVictory"
QT_MOC_LITERAL(5, 34, 8), // "mixCubes"
QT_MOC_LITERAL(6, 43, 7), // "getName"
QT_MOC_LITERAL(7, 51, 7), // "setName"
QT_MOC_LITERAL(8, 59, 4) // "name"

    },
    "tile::board\0move\0\0index\0isVictory\0"
    "mixCubes\0getName\0setName\0name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tile__board[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x02 /* Public */,
       4,    0,   42,    2, 0x02 /* Public */,
       5,    0,   43,    2, 0x02 /* Public */,
       6,    1,   44,    2, 0x02 /* Public */,
       7,    2,   47,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Int, QMetaType::Int,    3,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    8,

       0        // eod
};

void tile::board::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        board *_t = static_cast<board *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->move((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->isVictory();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: _t->mixCubes(); break;
        case 3: { int _r = _t->getName((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: _t->setName((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject tile::board::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_tile__board.data,
      qt_meta_data_tile__board,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *tile::board::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tile::board::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_tile__board.stringdata0))
        return static_cast<void*>(const_cast< board*>(this));
    return QObject::qt_metacast(_clname);
}

int tile::board::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
