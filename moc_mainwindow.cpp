/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Oct 29 14:54:53 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      23,   11,   11,   11, 0x0a,
      35,   11,   11,   11, 0x0a,
      68,   51,   11,   11, 0x0a,
     100,   11,   11,   11, 0x0a,
     112,   11,   11,   11, 0x0a,
     129,   11,   11,   11, 0x0a,
     146,   11,   11,   11, 0x0a,
     166,  160,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0OpenPort()\0ClosePort()\0"
    "DataAvailable()\0plotItem,checked\0"
    "CurveToggled(QwtPlotItem*,bool)\0"
    "ResetZoom()\0TestCreatePlot()\0"
    "TestAddSamples()\0TestAddKnob()\0param\0"
    "ParamChangedValue(DynamicParam*)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: OpenPort(); break;
        case 1: ClosePort(); break;
        case 2: DataAvailable(); break;
        case 3: CurveToggled((*reinterpret_cast< QwtPlotItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: ResetZoom(); break;
        case 5: TestCreatePlot(); break;
        case 6: TestAddSamples(); break;
        case 7: TestAddKnob(); break;
        case 8: ParamChangedValue((*reinterpret_cast< DynamicParam*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
