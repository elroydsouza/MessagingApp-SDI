#include "loginScreen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginScreen w;
    w.show();
    return a.exec();
}
