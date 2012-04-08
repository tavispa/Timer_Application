/****************************************************************************
** Meta object code from reading C++ file 'timer.h'
**
** Created: Sat Apr 7 23:47:44 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "timer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_timer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      24,    6,    6,    6, 0x0a,
      38,    6,    6,    6, 0x0a,
      50,    6,    6,    6, 0x0a,
      62,    6,    6,    6, 0x0a,
      77,    6,    6,    6, 0x0a,
      86,    6,    6,    6, 0x0a,
      96,    6,    6,    6, 0x0a,
     106,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_timer[] = {
    "timer\0\0countdownStart()\0subtractOne()\0"
    "setMValue()\0setSValue()\0countupStart()\0"
    "addOne()\0setMLow()\0setSLow()\0"
    "on_actionAbout_triggered()\0"
};

void timer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        timer *_t = static_cast<timer *>(_o);
        switch (_id) {
        case 0: _t->countdownStart(); break;
        case 1: _t->subtractOne(); break;
        case 2: _t->setMValue(); break;
        case 3: _t->setSValue(); break;
        case 4: _t->countupStart(); break;
        case 5: _t->addOne(); break;
        case 6: _t->setMLow(); break;
        case 7: _t->setSLow(); break;
        case 8: _t->on_actionAbout_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData timer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject timer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_timer,
      qt_meta_data_timer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &timer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *timer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *timer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_timer))
        return static_cast<void*>(const_cast< timer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int timer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
