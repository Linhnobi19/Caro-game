/****************************************************************************
** Meta object code from reading C++ file 'PlayerController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../PlayerController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlayerController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayerController_t {
    QByteArrayData data[22];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayerController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayerController_t qt_meta_stringdata_PlayerController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "PlayerController"
QT_MOC_LITERAL(1, 17, 14), // "playersChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 21), // "currentPlayer1Changed"
QT_MOC_LITERAL(4, 55, 21), // "currentPlayer2Changed"
QT_MOC_LITERAL(5, 77, 6), // "search"
QT_MOC_LITERAL(6, 84, 14), // "QList<Player*>"
QT_MOC_LITERAL(7, 99, 4), // "name"
QT_MOC_LITERAL(8, 104, 10), // "searchRank"
QT_MOC_LITERAL(9, 115, 4), // "rank"
QT_MOC_LITERAL(10, 120, 11), // "checkPlayer"
QT_MOC_LITERAL(11, 132, 5), // "name1"
QT_MOC_LITERAL(12, 138, 5), // "name2"
QT_MOC_LITERAL(13, 144, 16), // "setCurrentPlayer"
QT_MOC_LITERAL(14, 161, 6), // "update"
QT_MOC_LITERAL(15, 168, 6), // "player"
QT_MOC_LITERAL(16, 175, 5), // "vsBot"
QT_MOC_LITERAL(17, 181, 11), // "resetPlayer"
QT_MOC_LITERAL(18, 193, 7), // "players"
QT_MOC_LITERAL(19, 201, 14), // "currentPlayer1"
QT_MOC_LITERAL(20, 216, 7), // "Player*"
QT_MOC_LITERAL(21, 224, 14) // "currentPlayer2"

    },
    "PlayerController\0playersChanged\0\0"
    "currentPlayer1Changed\0currentPlayer2Changed\0"
    "search\0QList<Player*>\0name\0searchRank\0"
    "rank\0checkPlayer\0name1\0name2\0"
    "setCurrentPlayer\0update\0player\0vsBot\0"
    "resetPlayer\0players\0currentPlayer1\0"
    "Player*\0currentPlayer2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayerController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       3,  102, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    1,   72,    2, 0x02 /* Public */,
       8,    2,   75,    2, 0x02 /* Public */,
      10,    2,   80,    2, 0x02 /* Public */,
      10,    1,   85,    2, 0x22 /* Public | MethodCloned */,
      13,    2,   88,    2, 0x02 /* Public */,
      13,    1,   93,    2, 0x22 /* Public | MethodCloned */,
      14,    2,   96,    2, 0x02 /* Public */,
      17,    0,  101,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    0x80000000 | 6, QMetaType::QString,    7,
    0x80000000 | 6, QMetaType::Int, QMetaType::QString,    9,    7,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::QString, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   15,   16,
    QMetaType::Void,

 // properties: name, type, flags
      18, 0x80000000 | 6, 0x0049590b,
      19, 0x80000000 | 20, 0x0049590b,
      21, 0x80000000 | 20, 0x0049590b,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void PlayerController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlayerController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playersChanged(); break;
        case 1: _t->currentPlayer1Changed(); break;
        case 2: _t->currentPlayer2Changed(); break;
        case 3: { QList<Player*> _r = _t->search((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<Player*>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QList<Player*> _r = _t->searchRank((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<Player*>*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->checkPlayer((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->checkPlayer((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setCurrentPlayer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->setCurrentPlayer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->update((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->resetPlayer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerController::playersChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerController::currentPlayer1Changed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlayerController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerController::currentPlayer2Changed)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Player* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Player*> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<PlayerController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<Player*>*>(_v) = _t->players(); break;
        case 1: *reinterpret_cast< Player**>(_v) = _t->currentPlayer1(); break;
        case 2: *reinterpret_cast< Player**>(_v) = _t->currentPlayer2(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<PlayerController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPlayers(*reinterpret_cast< QList<Player*>*>(_v)); break;
        case 1: _t->setCurrentPlayer1(*reinterpret_cast< Player**>(_v)); break;
        case 2: _t->setCurrentPlayer2(*reinterpret_cast< Player**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject PlayerController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PlayerController.data,
    qt_meta_data_PlayerController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PlayerController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayerController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PlayerController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
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
void PlayerController::playersChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PlayerController::currentPlayer1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PlayerController::currentPlayer2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
