/****************************************************************************
** Meta object code from reading C++ file 'WeightMatrix.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../lib/components/WeightMatrix.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WeightMatrix.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN12WeightMatrixE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN12WeightMatrixE = QtMocHelpers::stringData(
    "WeightMatrix",
    "QML.Element",
    "auto",
    "sizeChanged",
    "",
    "updated",
    "QVariant",
    "rows",
    "index",
    "value",
    "setData",
    "get_display_data",
    "QModelIndex",
    "columns"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN12WeightMatrixE[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
       4,   16, // methods
       2,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   40,    4, 0x06,    3 /* Public */,
       5,    3,   41,    4, 0x06,    4 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      10,    2,   48,    4, 0x02,    8 /* Public */,
      11,    1,   53,    4, 0x02,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6,    7,    8,    9,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    8,    9,
    0x80000000 | 6, 0x80000000 | 12,    8,

 // properties: name, type, flags, notifyId, revision
       7, QMetaType::Int, 0x00015003, uint(0), 0,
      13, QMetaType::Int, 0x00015003, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject WeightMatrix::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_ZN12WeightMatrixE.offsetsAndSizes,
    qt_meta_data_ZN12WeightMatrixE,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'rows'
        int,
        // property 'columns'
        int,
        // Q_OBJECT / Q_GADGET
        WeightMatrix,
        // method 'sizeChanged'
        void,
        // method 'updated'
        void,
        const QVariant &,
        const QVariant &,
        const QVariant &,
        // method 'setData'
        void,
        const QVariant &,
        const QVariant &,
        // method 'get_display_data'
        QVariant,
        const QModelIndex &
    >,
    nullptr
} };

void WeightMatrix::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WeightMatrix *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sizeChanged(); break;
        case 1: _t->updated((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3]))); break;
        case 2: _t->setData((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 3: { QVariant _r = _t->get_display_data((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (WeightMatrix::*)();
            if (_q_method_type _q_method = &WeightMatrix::sizeChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (WeightMatrix::*)(const QVariant & , const QVariant & , const QVariant & );
            if (_q_method_type _q_method = &WeightMatrix::updated; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getRowCount(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getColumnCount(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRowCount(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setColumnCount(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *WeightMatrix::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeightMatrix::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN12WeightMatrixE.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int WeightMatrix::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void WeightMatrix::sizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WeightMatrix::updated(const QVariant & _t1, const QVariant & _t2, const QVariant & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
