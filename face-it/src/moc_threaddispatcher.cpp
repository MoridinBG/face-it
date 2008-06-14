/****************************************************************************
** Meta object code from reading C++ file 'threaddispatcher.h'
**
** Created: Fri Jun 13 21:41:35 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "threaddispatcher.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threaddispatcher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_ThreadDispatcher[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      38,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ThreadDispatcher[] = {
    "ThreadDispatcher\0\0signalsCalculated()\0"
    "weightsChanged()\0threadFinished()\0"
};

const QMetaObject ThreadDispatcher::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ThreadDispatcher,
      qt_meta_data_ThreadDispatcher, 0 }
};

const QMetaObject *ThreadDispatcher::metaObject() const
{
    return &staticMetaObject;
}

void *ThreadDispatcher::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadDispatcher))
	return static_cast<void*>(const_cast< ThreadDispatcher*>(this));
    return QObject::qt_metacast(_clname);
}

int ThreadDispatcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalsCalculated(); break;
        case 1: weightsChanged(); break;
        case 2: threadFinished(); break;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ThreadDispatcher::signalsCalculated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ThreadDispatcher::weightsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
