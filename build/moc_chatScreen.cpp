/****************************************************************************
** Meta object code from reading C++ file 'chatScreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/chatScreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_chatScreen_t {
    QByteArrayData data[19];
    char stringdata0[391];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chatScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chatScreen_t qt_meta_stringdata_chatScreen = {
    {
QT_MOC_LITERAL(0, 0, 10), // "chatScreen"
QT_MOC_LITERAL(1, 11, 21), // "connectedDisconnected"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 21), // "on_buttonSend_clicked"
QT_MOC_LITERAL(4, 56, 25), // "on_buttonUserChat_clicked"
QT_MOC_LITERAL(5, 82, 23), // "on_buttonLogout_clicked"
QT_MOC_LITERAL(6, 106, 28), // "on_buttonCreateGroup_clicked"
QT_MOC_LITERAL(7, 135, 26), // "on_buttonGroupChat_clicked"
QT_MOC_LITERAL(8, 162, 24), // "on_buttonPromote_clicked"
QT_MOC_LITERAL(9, 187, 23), // "on_buttonDemote_clicked"
QT_MOC_LITERAL(10, 211, 15), // "fillListWidgets"
QT_MOC_LITERAL(11, 227, 20), // "checkPermissionLevel"
QT_MOC_LITERAL(12, 248, 24), // "on_buttonRefresh_clicked"
QT_MOC_LITERAL(13, 273, 27), // "on_buttonAddContact_clicked"
QT_MOC_LITERAL(14, 301, 24), // "on_buttonProfile_clicked"
QT_MOC_LITERAL(15, 326, 6), // "logout"
QT_MOC_LITERAL(16, 333, 20), // "resetInactivityTimer"
QT_MOC_LITERAL(17, 354, 7), // "refresh"
QT_MOC_LITERAL(18, 362, 28) // "on_buttonUserPicture_clicked"

    },
    "chatScreen\0connectedDisconnected\0\0"
    "on_buttonSend_clicked\0on_buttonUserChat_clicked\0"
    "on_buttonLogout_clicked\0"
    "on_buttonCreateGroup_clicked\0"
    "on_buttonGroupChat_clicked\0"
    "on_buttonPromote_clicked\0"
    "on_buttonDemote_clicked\0fillListWidgets\0"
    "checkPermissionLevel\0on_buttonRefresh_clicked\0"
    "on_buttonAddContact_clicked\0"
    "on_buttonProfile_clicked\0logout\0"
    "resetInactivityTimer\0refresh\0"
    "on_buttonUserPicture_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chatScreen[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void chatScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<chatScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectedDisconnected(); break;
        case 1: _t->on_buttonSend_clicked(); break;
        case 2: _t->on_buttonUserChat_clicked(); break;
        case 3: _t->on_buttonLogout_clicked(); break;
        case 4: _t->on_buttonCreateGroup_clicked(); break;
        case 5: _t->on_buttonGroupChat_clicked(); break;
        case 6: _t->on_buttonPromote_clicked(); break;
        case 7: _t->on_buttonDemote_clicked(); break;
        case 8: _t->fillListWidgets(); break;
        case 9: _t->checkPermissionLevel(); break;
        case 10: _t->on_buttonRefresh_clicked(); break;
        case 11: _t->on_buttonAddContact_clicked(); break;
        case 12: _t->on_buttonProfile_clicked(); break;
        case 13: _t->logout(); break;
        case 14: _t->resetInactivityTimer(); break;
        case 15: _t->refresh(); break;
        case 16: _t->on_buttonUserPicture_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject chatScreen::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_chatScreen.data,
    qt_meta_data_chatScreen,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *chatScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chatScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_chatScreen.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int chatScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
