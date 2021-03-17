#include "loginScreen.h"
#include "contactsScreen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    contactsScreen w;
    w.show();
    return a.exec();
}
