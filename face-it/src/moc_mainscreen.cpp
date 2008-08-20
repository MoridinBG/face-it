/****************************************************************************
** Meta object code from reading C++ file 'mainscreen.h'
**
** Created: Thu Aug 21 00:47:34 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainscreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainScreen[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,
      59,   11,   11,   11, 0x08,
      92,   83,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainScreen[] = {
    "MainScreen\0\0on_pushLoad_clicked()\0"
    "on_pushEditNet_clicked()\0"
    "on_pushSearch_clicked()\0_network\0"
    "updateNetwork(Network*)\0"
};

const QMetaObject MainScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MainScreen,
      qt_meta_data_MainScreen, 0 }
};

const QMetaObject *MainScreen::metaObject() const
{
    return &staticMetaObject;
}

void *MainScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainScreen))
        return static_cast<void*>(const_cast< MainScreen*>(this));
    if (!strcmp(_clname, "Ui::Dialog"))
        return static_cast< Ui::Dialog*>(const_cast< MainScreen*>(this));
    return QDialog::qt_metacast(_clname);
}

int MainScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushLoad_clicked(); break;
        case 1: on_pushEditNet_clicked(); break;
        case 2: on_pushSearch_clicked(); break;
        case 3: updateNetwork((*reinterpret_cast< Network*(*)>(_a[1]))); break;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
