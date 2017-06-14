/****************************************************************************
** Meta object code from reading C++ file 'LeptonThread.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "LeptonThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LeptonThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LeptonThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   33,   33,   33, 0x05,
      34,   33,   33,   33, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,   33,   33,   33, 0x0a,
      67,   33,   33,   33, 0x0a,
      78,   33,   33,   33, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LeptonThread[] = {
    "LeptonThread\0updateText(QString)\0\0"
    "updateImage(QImage)\0performFFC()\0"
    "snapshot()\0drawSquare(float)\0"
};

void LeptonThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LeptonThread *_t = static_cast<LeptonThread *>(_o);
        switch (_id) {
        case 0: _t->updateText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->updateImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->performFFC(); break;
        case 3: _t->snapshot(); break;
        case 4: _t->drawSquare((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LeptonThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LeptonThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_LeptonThread,
      qt_meta_data_LeptonThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LeptonThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LeptonThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LeptonThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LeptonThread))
        return static_cast<void*>(const_cast< LeptonThread*>(this));
    return QThread::qt_metacast(_clname);
}

int LeptonThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void LeptonThread::updateText(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LeptonThread::updateImage(QImage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
