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

//    QPushButton *contactButtons[10];
//    QVBoxLayout *layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
//    for (int i = 0; i == 10; i++){
//        contactButtons[i] = new QPushButton;
//        contactButtons[i]->setText("hi");
//        layout->addWidget(contactButtons[i]);
//    }

//    QVBoxLayout *layout = new QVBoxLayout(ui->scrollArea);

//    QPushButton *button;

//    for (int i = 0; i == 10; i++){
//        button = new QPushButton();
//        layout->addWidget(button);
//    }
//    ui->scrollArea->show();

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
