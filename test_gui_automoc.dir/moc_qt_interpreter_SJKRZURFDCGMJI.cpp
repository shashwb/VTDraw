/****************************************************************************
** Meta object code from reading C++ file 'qt_interpreter.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt_interpreter.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_interpreter.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtInterpreter_t {
    QByteArrayData data[14];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtInterpreter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtInterpreter_t qt_meta_stringdata_QtInterpreter = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QtInterpreter"
QT_MOC_LITERAL(1, 14, 11), // "drawGraphic"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(4, 42, 4), // "item"
QT_MOC_LITERAL(5, 47, 4), // "info"
QT_MOC_LITERAL(6, 52, 7), // "message"
QT_MOC_LITERAL(7, 60, 5), // "error"
QT_MOC_LITERAL(8, 66, 16), // "parseAndEvaluate"
QT_MOC_LITERAL(9, 83, 5), // "entry"
QT_MOC_LITERAL(10, 89, 22), // "determineMessageOutput"
QT_MOC_LITERAL(11, 112, 10), // "Expression"
QT_MOC_LITERAL(12, 123, 3), // "exp"
QT_MOC_LITERAL(13, 127, 17) // "recieveDrawVector"

    },
    "QtInterpreter\0drawGraphic\0\0QGraphicsItem*\0"
    "item\0info\0message\0error\0parseAndEvaluate\0"
    "entry\0determineMessageOutput\0Expression\0"
    "exp\0recieveDrawVector"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtInterpreter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,
       7,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   53,    2, 0x0a /* Public */,
      10,    1,   56,    2, 0x0a /* Public */,
      13,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,

       0        // eod
};

void QtInterpreter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtInterpreter *_t = static_cast<QtInterpreter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->drawGraphic((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 1: _t->info((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->parseAndEvaluate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->determineMessageOutput((*reinterpret_cast< Expression(*)>(_a[1]))); break;
        case 5: _t->recieveDrawVector(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QtInterpreter::*_t)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtInterpreter::drawGraphic)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QtInterpreter::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtInterpreter::info)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QtInterpreter::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtInterpreter::error)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QtInterpreter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtInterpreter.data,
      qt_meta_data_QtInterpreter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtInterpreter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtInterpreter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtInterpreter.stringdata0))
        return static_cast<void*>(const_cast< QtInterpreter*>(this));
    return QObject::qt_metacast(_clname);
}

int QtInterpreter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QtInterpreter::drawGraphic(QGraphicsItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtInterpreter::info(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtInterpreter::error(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
