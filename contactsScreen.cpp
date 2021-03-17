#include "contactsScreen.h"
#include "ui_contactsScreen.h"

#include <iostream>

contactsScreen::contactsScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::contactsScreen)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("admin");
    db.setPassword("RF66Ycwa3vI9");
    db.setDatabaseName("messagingApp");

    if(db.open())
    {
        QMessageBox::information(this,"DATABASE CONNECTED", "Database connection ");

        QString contactUsername;

        QSqlQuery query("SELECT username "
                        "FROM users");

        while (query.next()) {
            contactUsername = query.value(0).toString();

            ui->comboBoxUsers->addItem(contactUsername);
        }
        db.close();

    } else {
        QMessageBox::information(this,"Not Connected","Database is not connected");
    }

}

contactsScreen::~contactsScreen()
{
    delete ui;
}
