/****************************************************************************
** Meta object code from reading C++ file 'errorsignalthread.h'
**
** Created: Thu Aug 21 00:47:33 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "errorsignalthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'errorsignalthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ErrorSignalThread[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ErrorSignalThread[] = {
    "ErrorSignalThread\0\0ready()\0"
};

const QMetaObject ErrorSignalThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ErrorSignalThread,
      qt_meta_data_ErrorSignalThread, 0 }
};

const QMetaObject *ErrorSignalThread::metaObject() const
{
    return &staticMetaObject;
}

void *ErrorSignalThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ErrorSignalThread))
        return static_cast<void*>(const_cast< ErrorSignalThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ErrorSignalThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ready(); break;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ErrorSignalThread::ready()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
