#include "contactsScreen.h"
#include "ui_contactsScreen.h"
#include "user.h"
#include "loginScreen.h"

#include <iostream>
#include <QMessageBox>

contactsScreen::contactsScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::contactsScreen)
{
    ui->setupUi(this);
}

void contactsScreen::run(){
    ui->labelWelcome->setText("Welcome " + user.getFirstName() + " " + user.getLastName() + "!");

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("admin");
    db.setPassword("RF66Ycwa3vI9");
    db.setDatabaseName("messagingApp");

    if(db.open())
    {
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

void contactsScreen::on_buttonAddContact_clicked()
{

}

void contactsScreen::acceptUser(User _user){
    user = _user;
}
