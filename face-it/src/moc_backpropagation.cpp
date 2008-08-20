/****************************************************************************
** Meta object code from reading C++ file 'backpropagation.h'
**
** Created: Thu Aug 21 00:47:32 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "backpropagation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backpropagation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Backpropagation[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      25,   17,   16,   16, 0x05,
      48,   16,   16,   16, 0x05,
      61,   16,   16,   16, 0x05,
      81,   77,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      94,   16,   16,   16, 0x08,
     110,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Backpropagation[] = {
    "Backpropagation\0\0message\0"
    "exception(const char*)\0propagated()\0"
    "cycleFinished()\0err\0errr(double)\0"
    "changeWeights()\0checkProgress()\0"
};

const QMetaObject Backpropagation::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Backpropagation,
      qt_meta_data_Backpropagation, 0 }
};

const QMetaObject *Backpropagation::metaObject() const
{
    return &staticMetaObject;
}

void *Backpropagation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Backpropagation))
        return static_cast<void*>(const_cast< Backpropagation*>(this));
    return QThread::qt_metacast(_clname);
}

int Backpropagation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: exception((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 1: propagated(); break;
        case 2: cycleFinished(); break;
        case 3: errr((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: changeWeights(); break;
        case 5: checkProgress(); break;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Backpropagation::exception(const char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Backpropagation::propagated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Backpropagation::cycleFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Backpropagation::errr(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
