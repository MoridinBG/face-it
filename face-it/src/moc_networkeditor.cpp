/****************************************************************************
** Meta object code from reading C++ file 'networkeditor.h'
**
** Created: Fri Jun 13 21:41:33 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "networkeditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_NetworkEditor[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      22,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   43,   14,   14, 0x08,
      83,   43,   14,   14, 0x08,
     121,   43,   14,   14, 0x08,
     160,   43,   14,   14, 0x08,
     191,   43,   14,   14, 0x08,
     223,   14,   14,   14, 0x08,
     259,   14,   14,   14, 0x08,
     298,   14,   14,   14, 0x08,
     322,   14,   14,   14, 0x08,
     344,   14,   14,   14, 0x08,
     370,   14,   14,   14, 0x08,
     399,   14,   14,   14, 0x08,
     428,   14,   14,   14, 0x08,
     460,   14,   14,   14, 0x08,
     483,   14,   14,   14, 0x08,
     510,   14,   14,   14, 0x08,
     541,  533,   14,   14, 0x08,
     575,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NetworkEditor[] = {
    "NetworkEditor\0\0newNet\0newNetwork(Network*)\0"
    "i\0on_spinHiddenLayers_valueChanged(int)\0"
    "on_spinInputNeurons_valueChanged(int)\0"
    "on_spinOutputNeurons_valueChanged(int)\0"
    "on_spinWidth_valueChanged(int)\0"
    "on_spinHeight_valueChanged(int)\0"
    "on_listFaces_itemSelectionChanged()\0"
    "on_listNonFaces_itemSelectionChanged()\0"
    "on_pushCommit_clicked()\0on_pushDone_clicked()\0"
    "on_pushAddFaces_clicked()\0"
    "on_pushRemoveFaces_clicked()\0"
    "on_pushAddNonFaces_clicked()\0"
    "on_pushRemoveNonFaces_clicked()\0"
    "on_pushTrain_clicked()\0"
    "on_pushRandomize_clicked()\0"
    "on_pushToXML_clicked()\0message\0"
    "propagationException(const char*)\0"
    "propagationFinished()\0"
};

const QMetaObject NetworkEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NetworkEditor,
      qt_meta_data_NetworkEditor, 0 }
};

const QMetaObject *NetworkEditor::metaObject() const
{
    return &staticMetaObject;
}

void *NetworkEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkEditor))
	return static_cast<void*>(const_cast< NetworkEditor*>(this));
    if (!strcmp(_clname, "Ui::NetworkEditor"))
	return static_cast< Ui::NetworkEditor*>(const_cast< NetworkEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int NetworkEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newNetwork((*reinterpret_cast< Network*(*)>(_a[1]))); break;
        case 1: on_spinHiddenLayers_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: on_spinInputNeurons_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_spinOutputNeurons_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_spinWidth_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_spinHeight_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_listFaces_itemSelectionChanged(); break;
        case 7: on_listNonFaces_itemSelectionChanged(); break;
        case 8: on_pushCommit_clicked(); break;
        case 9: on_pushDone_clicked(); break;
        case 10: on_pushAddFaces_clicked(); break;
        case 11: on_pushRemoveFaces_clicked(); break;
        case 12: on_pushAddNonFaces_clicked(); break;
        case 13: on_pushRemoveNonFaces_clicked(); break;
        case 14: on_pushTrain_clicked(); break;
        case 15: on_pushRandomize_clicked(); break;
        case 16: on_pushToXML_clicked(); break;
        case 17: propagationException((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 18: propagationFinished(); break;
        }
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void NetworkEditor::newNetwork(Network * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
