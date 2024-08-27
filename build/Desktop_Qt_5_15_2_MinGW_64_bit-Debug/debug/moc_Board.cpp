/****************************************************************************
** Meta object code from reading C++ file 'Board.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Board.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Board.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Board_t {
    QByteArrayData data[26];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Board_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Board_t qt_meta_stringdata_Board = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Board"
QT_MOC_LITERAL(1, 6, 16), // "boardDataChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 17), // "botMoveSuccessful"
QT_MOC_LITERAL(4, 42, 5), // "index"
QT_MOC_LITERAL(5, 48, 12), // "winningState"
QT_MOC_LITERAL(6, 61, 12), // "QVector<int>"
QT_MOC_LITERAL(7, 74, 8), // "indecies"
QT_MOC_LITERAL(8, 83, 13), // "isBusyChanged"
QT_MOC_LITERAL(9, 97, 8), // "makeMove"
QT_MOC_LITERAL(10, 106, 6), // "number"
QT_MOC_LITERAL(11, 113, 6), // "player"
QT_MOC_LITERAL(12, 120, 10), // "resetBoard"
QT_MOC_LITERAL(13, 131, 6), // "isFull"
QT_MOC_LITERAL(14, 138, 8), // "getValue"
QT_MOC_LITERAL(15, 147, 7), // "botMove"
QT_MOC_LITERAL(16, 155, 4), // "mode"
QT_MOC_LITERAL(17, 160, 4), // "redo"
QT_MOC_LITERAL(18, 165, 4), // "undo"
QT_MOC_LITERAL(19, 170, 11), // "clearReplay"
QT_MOC_LITERAL(20, 182, 11), // "undoInMatch"
QT_MOC_LITERAL(21, 194, 7), // "playbot"
QT_MOC_LITERAL(22, 202, 9), // "boardSize"
QT_MOC_LITERAL(23, 212, 9), // "boardData"
QT_MOC_LITERAL(24, 222, 12), // "QList<Cell*>"
QT_MOC_LITERAL(25, 235, 6) // "isBusy"

    },
    "Board\0boardDataChanged\0\0botMoveSuccessful\0"
    "index\0winningState\0QVector<int>\0"
    "indecies\0isBusyChanged\0makeMove\0number\0"
    "player\0resetBoard\0isFull\0getValue\0"
    "botMove\0mode\0redo\0undo\0clearReplay\0"
    "undoInMatch\0playbot\0boardSize\0boardData\0"
    "QList<Cell*>\0isBusy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Board[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       3,  106, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,
       5,    1,   83,    2, 0x06 /* Public */,
       8,    0,   86,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       9,    2,   87,    2, 0x02 /* Public */,
      12,    0,   92,    2, 0x02 /* Public */,
      13,    0,   93,    2, 0x02 /* Public */,
      14,    1,   94,    2, 0x02 /* Public */,
      15,    1,   97,    2, 0x02 /* Public */,
      17,    0,  100,    2, 0x02 /* Public */,
      18,    0,  101,    2, 0x02 /* Public */,
      19,    0,  102,    2, 0x02 /* Public */,
      20,    1,  103,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Bool, QMetaType::Int, QMetaType::QString,   10,   11,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::QString, QMetaType::Int,    4,
    QMetaType::Bool, QMetaType::QString,   16,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Bool,   21,

 // properties: name, type, flags
      22, QMetaType::Int, 0x00095401,
      23, 0x80000000 | 24, 0x00495009,
      25, QMetaType::Bool, 0x00495903,

 // properties: notify_signal_id
       0,
       0,
       3,

       0        // eod
};

void Board::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Board *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->boardDataChanged(); break;
        case 1: _t->botMoveSuccessful((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->winningState((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 3: _t->isBusyChanged(); break;
        case 4: { bool _r = _t->makeMove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->resetBoard(); break;
        case 6: { bool _r = _t->isFull();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->getValue((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->botMove((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->redo();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->undo();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->clearReplay(); break;
        case 12: { int _r = _t->undoInMatch((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Board::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board::boardDataChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Board::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board::botMoveSuccessful)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Board::*)(QVector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board::winningState)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Board::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board::isBusyChanged)) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Cell*> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Board *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->boardSize(); break;
        case 1: *reinterpret_cast< QList<Cell*>*>(_v) = _t->boardData(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isBusy(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Board *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setIsBusy(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Board::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Board.data,
    qt_meta_data_Board,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Board::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Board::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Board.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Board::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Board::boardDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Board::botMoveSuccessful(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Board::winningState(QVector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Board::isBusyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
