/****************************************************************************
** Meta object code from reading C++ file 'cvprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cvprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cvprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cvProcess_t {
    QByteArrayData data[9];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cvProcess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cvProcess_t qt_meta_stringdata_cvProcess = {
    {
QT_MOC_LITERAL(0, 0, 9), // "cvProcess"
QT_MOC_LITERAL(1, 10, 13), // "progressValue"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "value"
QT_MOC_LITERAL(4, 31, 12), // "progressTime"
QT_MOC_LITERAL(5, 44, 4), // "time"
QT_MOC_LITERAL(6, 49, 13), // "progressFrame"
QT_MOC_LITERAL(7, 63, 4), // "img1"
QT_MOC_LITERAL(8, 68, 16) // "progressFinished"

    },
    "cvProcess\0progressValue\0\0value\0"
    "progressTime\0time\0progressFrame\0img1\0"
    "progressFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cvProcess[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       8,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::QImage,    7,
    QMetaType::Void,

       0        // eod
};

void cvProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cvProcess *_t = static_cast<cvProcess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->progressValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->progressTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->progressFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->progressFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (cvProcess::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cvProcess::progressValue)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (cvProcess::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cvProcess::progressTime)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (cvProcess::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cvProcess::progressFrame)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (cvProcess::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cvProcess::progressFinished)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject cvProcess::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_cvProcess.data,
      qt_meta_data_cvProcess,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cvProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cvProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cvProcess.stringdata0))
        return static_cast<void*>(const_cast< cvProcess*>(this));
    return QThread::qt_metacast(_clname);
}

int cvProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void cvProcess::progressValue(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cvProcess::progressTime(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void cvProcess::progressFrame(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void cvProcess::progressFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
