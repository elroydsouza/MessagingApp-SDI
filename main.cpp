#include "loginScreen.h"
#include "contactsScreen.h"
#include "chatScreen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("admin");
    db.setPassword("RF66Ycwa3vI9");
    db.setDatabaseName("messagingApp");

    loginScreen w;
    w.show();
    return a.exec();
}
