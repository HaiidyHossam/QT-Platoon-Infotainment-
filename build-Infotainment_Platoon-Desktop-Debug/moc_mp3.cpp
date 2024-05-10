/****************************************************************************
** Meta object code from reading C++ file 'mp3.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../11-Infotainment_Platoon/mp3.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mp3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mp3_t {
    QByteArrayData data[17];
    char stringdata0[322];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mp3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mp3_t qt_meta_stringdata_Mp3 = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Mp3"
QT_MOC_LITERAL(1, 4, 25), // "on_listWidget_itemClicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 48, 4), // "item"
QT_MOC_LITERAL(5, 53, 17), // "updateProgressBar"
QT_MOC_LITERAL(6, 71, 31), // "on_horizontalSlider_sliderMoved"
QT_MOC_LITERAL(7, 103, 8), // "position"
QT_MOC_LITERAL(8, 112, 34), // "on_horizontalSlider_sliderRel..."
QT_MOC_LITERAL(9, 147, 30), // "on_verticalSlider_valueChanged"
QT_MOC_LITERAL(10, 178, 5), // "value"
QT_MOC_LITERAL(11, 184, 10), // "updateList"
QT_MOC_LITERAL(12, 195, 28), // "on_start_stop_button_clicked"
QT_MOC_LITERAL(13, 224, 22), // "on_next_button_clicked"
QT_MOC_LITERAL(14, 247, 26), // "on_previous_button_clicked"
QT_MOC_LITERAL(15, 274, 24), // "on_repeat_button_clicked"
QT_MOC_LITERAL(16, 299, 22) // "on_home_button_clicked"

    },
    "Mp3\0on_listWidget_itemClicked\0\0"
    "QListWidgetItem*\0item\0updateProgressBar\0"
    "on_horizontalSlider_sliderMoved\0"
    "position\0on_horizontalSlider_sliderReleased\0"
    "on_verticalSlider_valueChanged\0value\0"
    "updateList\0on_start_stop_button_clicked\0"
    "on_next_button_clicked\0"
    "on_previous_button_clicked\0"
    "on_repeat_button_clicked\0"
    "on_home_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mp3[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    1,   73,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,
      15,    0,   84,    2, 0x08 /* Private */,
      16,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Mp3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mp3 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_listWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->updateProgressBar(); break;
        case 2: _t->on_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_horizontalSlider_sliderReleased(); break;
        case 4: _t->on_verticalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateList(); break;
        case 6: _t->on_start_stop_button_clicked(); break;
        case 7: _t->on_next_button_clicked(); break;
        case 8: _t->on_previous_button_clicked(); break;
        case 9: _t->on_repeat_button_clicked(); break;
        case 10: _t->on_home_button_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Mp3::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Mp3.data,
    qt_meta_data_Mp3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mp3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mp3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mp3.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Mp3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
