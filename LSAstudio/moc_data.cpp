/****************************************************************************
** Meta object code from reading C++ file 'data.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "data.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'data.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Data_t {
    QByteArrayData data[11];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Data_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Data_t qt_meta_stringdata_Data = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Data"
QT_MOC_LITERAL(1, 5, 10), // "manageData"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 10), // "frame_rate"
QT_MOC_LITERAL(4, 28, 9), // "filter_sz"
QT_MOC_LITERAL(5, 38, 13), // "initilizeData"
QT_MOC_LITERAL(6, 52, 13), // "vector_length"
QT_MOC_LITERAL(7, 66, 10), // "filterData"
QT_MOC_LITERAL(8, 77, 15), // "QVector<double>"
QT_MOC_LITERAL(9, 93, 5), // "vdata"
QT_MOC_LITERAL(10, 99, 6) // "w_size"

    },
    "Data\0manageData\0\0frame_rate\0filter_sz\0"
    "initilizeData\0vector_length\0filterData\0"
    "QVector<double>\0vdata\0w_size"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Data[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x0a /* Public */,
       5,    1,   34,    2, 0x0a /* Public */,
       7,    2,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    0x80000000 | 8, 0x80000000 | 8, QMetaType::Int,    9,   10,

       0        // eod
};

void Data::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Data *_t = static_cast<Data *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->manageData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->initilizeData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { QVector<double> _r = _t->filterData((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVector<double>*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    }
}

const QMetaObject Data::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Data.data,
      qt_meta_data_Data,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Data::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Data::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Data.stringdata0))
        return static_cast<void*>(const_cast< Data*>(this));
    return QObject::qt_metacast(_clname);
}

int Data::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
