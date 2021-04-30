/****************************************************************************
** Meta object code from reading C++ file 'profileScreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/profileScreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profileScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_profileScreen_t {
    QByteArrayData data[11];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_profileScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_profileScreen_t qt_meta_stringdata_profileScreen = {
    {
QT_MOC_LITERAL(0, 0, 13), // "profileScreen"
QT_MOC_LITERAL(1, 14, 27), // "on_buttonChangeName_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 31), // "on_buttonChangePassword_clicked"
QT_MOC_LITERAL(4, 75, 24), // "on_buttonConfirm_clicked"
QT_MOC_LITERAL(5, 100, 15), // "encryptPassword"
QT_MOC_LITERAL(6, 116, 8), // "password"
QT_MOC_LITERAL(7, 125, 25), // "on_buttonPicture1_clicked"
QT_MOC_LITERAL(8, 151, 25), // "on_buttonPicture2_clicked"
QT_MOC_LITERAL(9, 177, 25), // "on_buttonPicture3_clicked"
QT_MOC_LITERAL(10, 203, 25) // "on_buttonPicture4_clicked"

    },
    "profileScreen\0on_buttonChangeName_clicked\0"
    "\0on_buttonChangePassword_clicked\0"
    "on_buttonConfirm_clicked\0encryptPassword\0"
    "password\0on_buttonPicture1_clicked\0"
    "on_buttonPicture2_clicked\0"
    "on_buttonPicture3_clicked\0"
    "on_buttonPicture4_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_profileScreen[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void profileScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<profileScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_buttonChangeName_clicked(); break;
        case 1: _t->on_buttonChangePassword_clicked(); break;
        case 2: _t->on_buttonConfirm_clicked(); break;
        case 3: { QString _r = _t->encryptPassword((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->on_buttonPicture1_clicked(); break;
        case 5: _t->on_buttonPicture2_clicked(); break;
        case 6: _t->on_buttonPicture3_clicked(); break;
        case 7: _t->on_buttonPicture4_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject profileScreen::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_profileScreen.data,
    qt_meta_data_profileScreen,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *profileScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *profileScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_profileScreen.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int profileScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
