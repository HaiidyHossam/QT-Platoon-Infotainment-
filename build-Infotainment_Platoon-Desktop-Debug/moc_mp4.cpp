/****************************************************************************
** Meta object code from reading C++ file 'mp4.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../11-Infotainment_Platoon/mp4.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mp4.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mp4_t {
    QByteArrayData data[20];
    char stringdata0[393];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mp4_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mp4_t qt_meta_stringdata_Mp4 = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Mp4"
QT_MOC_LITERAL(1, 4, 22), // "on_home_button_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 25), // "on_listWidget_itemClicked"
QT_MOC_LITERAL(4, 54, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 71, 4), // "item"
QT_MOC_LITERAL(6, 76, 10), // "updateList"
QT_MOC_LITERAL(7, 87, 22), // "on_back_button_clicked"
QT_MOC_LITERAL(8, 110, 4), // "back"
QT_MOC_LITERAL(9, 115, 4), // "play"
QT_MOC_LITERAL(10, 120, 24), // "on_repeat_button_clicked"
QT_MOC_LITERAL(11, 145, 29), // "on_start_pause_button_clicked"
QT_MOC_LITERAL(12, 175, 30), // "on_seek_forward_button_clicked"
QT_MOC_LITERAL(13, 206, 31), // "on_seek_backward_button_clicked"
QT_MOC_LITERAL(14, 238, 36), // "on_verticalSlider_sound_value..."
QT_MOC_LITERAL(15, 275, 5), // "value"
QT_MOC_LITERAL(16, 281, 40), // "on_horizontalSlider_duration_..."
QT_MOC_LITERAL(17, 322, 8), // "position"
QT_MOC_LITERAL(18, 331, 43), // "on_horizontalSlider_duration_..."
QT_MOC_LITERAL(19, 375, 17) // "updateProgressBar"

    },
    "Mp4\0on_home_button_clicked\0\0"
    "on_listWidget_itemClicked\0QListWidgetItem*\0"
    "item\0updateList\0on_back_button_clicked\0"
    "back\0play\0on_repeat_button_clicked\0"
    "on_start_pause_button_clicked\0"
    "on_seek_forward_button_clicked\0"
    "on_seek_backward_button_clicked\0"
    "on_verticalSlider_sound_valueChanged\0"
    "value\0on_horizontalSlider_duration_sliderMoved\0"
    "position\0on_horizontalSlider_duration_sliderReleased\0"
    "updateProgressBar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mp4[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    1,   85,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    1,   96,    2, 0x08 /* Private */,
      16,    1,   99,    2, 0x08 /* Private */,
      18,    0,  102,    2, 0x08 /* Private */,
      19,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Mp4::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mp4 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_home_button_clicked(); break;
        case 1: _t->on_listWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->updateList(); break;
        case 3: _t->on_back_button_clicked(); break;
        case 4: _t->back(); break;
        case 5: _t->play(); break;
        case 6: _t->on_repeat_button_clicked(); break;
        case 7: _t->on_start_pause_button_clicked(); break;
        case 8: _t->on_seek_forward_button_clicked(); break;
        case 9: _t->on_seek_backward_button_clicked(); break;
        case 10: _t->on_verticalSlider_sound_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_horizontalSlider_duration_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_horizontalSlider_duration_sliderReleased(); break;
        case 13: _t->updateProgressBar(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Mp4::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Mp4.data,
    qt_meta_data_Mp4,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mp4::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mp4::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mp4.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Mp4::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
