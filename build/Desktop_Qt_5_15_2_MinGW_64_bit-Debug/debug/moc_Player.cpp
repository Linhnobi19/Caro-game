/****************************************************************************
** Meta object code from reading C++ file 'Player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Player_t {
    QByteArrayData data[13];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Player_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Player_t qt_meta_stringdata_Player = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Player"
QT_MOC_LITERAL(1, 7, 15), // "nickNameChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "winsChanged"
QT_MOC_LITERAL(4, 36, 12), // "drawsChanged"
QT_MOC_LITERAL(5, 49, 13), // "loosesChanged"
QT_MOC_LITERAL(6, 63, 11), // "rankChanged"
QT_MOC_LITERAL(7, 75, 8), // "nickName"
QT_MOC_LITERAL(8, 84, 4), // "wins"
QT_MOC_LITERAL(9, 89, 5), // "draws"
QT_MOC_LITERAL(10, 95, 6), // "looses"
QT_MOC_LITERAL(11, 102, 4), // "rank"
QT_MOC_LITERAL(12, 107, 7) // "Ranking"

    },
    "Player\0nickNameChanged\0\0winsChanged\0"
    "drawsChanged\0loosesChanged\0rankChanged\0"
    "nickName\0wins\0draws\0looses\0rank\0Ranking"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Player[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       5,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00495903,
       8, QMetaType::Int, 0x00495903,
       9, QMetaType::Int, 0x00495903,
      10, QMetaType::Int, 0x00495903,
      11, 0x80000000 | 12, 0x0049590b,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void Player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Player *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nickNameChanged(); break;
        case 1: _t->winsChanged(); break;
        case 2: _t->drawsChanged(); break;
        case 3: _t->loosesChanged(); break;
        case 4: _t->rankChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player::nickNameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player::winsChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player::drawsChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player::loosesChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player::rankChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Player *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->nickName(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->wins(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->draws(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->looses(); break;
        case 4: *reinterpret_cast< Ranking*>(_v) = _t->rank(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Player *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setNickName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setWins(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setDraws(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setLooses(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setRank(*reinterpret_cast< Ranking*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Player::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Player.data,
    qt_meta_data_Player,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Player::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Player.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Player::nickNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Player::winsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Player::drawsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Player::loosesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Player::rankChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
