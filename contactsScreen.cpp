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
    fillListWidgets();
}

contactsScreen::~contactsScreen()
{
    delete ui;
}


void contactsScreen::acceptUser(User _user){
    user = _user;
}

void contactsScreen::on_buttonAddContact_clicked()
{
    if(ui->listWidgetUsers->selectedItems().count() != 0){
        QString selectedUser = ui->listWidgetUsers->currentItem()->text();

        QSqlQuery query;
        query.prepare("SELECT userID "
                        "FROM users "
                        "WHERE username = :selectedUser");

        query.bindValue(":selectedUser", selectedUser);
        query.exec();
        query.next();

        int contactID = query.value(0).toInt();
        int currentUserID = user.getUserID();

        const QString generatedTopic = user.getUsername() + selectedUser;

        query.prepare("INSERT INTO contacts (currentUserID, contactID, topic, contactUsername) "
                      "VALUES (:currentUserID, :contactID, :generatedTopic, :contactUsername)");
        query.bindValue(":currentUserID", currentUserID);
        query.bindValue(":contactID", contactID);
        query.bindValue(":generatedTopic", generatedTopic);
        query.bindValue(":contactUsername", selectedUser);

        query.exec();

        query.prepare("INSERT INTO contacts (currentUserID, contactID, topic, contactUsername) "
                      "VALUES (:contactID, :currentUserID, :generatedTopic, :contactUsername)");
        query.bindValue(":contactID", contactID);
        query.bindValue(":currentUserID", currentUserID);
        query.bindValue(":generatedTopic", generatedTopic);
        query.bindValue(":contactUsername", user.getUsername());

        query.exec();

        fillListWidgets();
    }
}

void contactsScreen::on_deleteContact_clicked()
{
    if(ui->listWidgetContacts->selectedItems().count() != 0){
        QString selectedUser = ui->listWidgetContacts->currentItem()->text();

        QSqlQuery query;
        query.prepare("SELECT userID "
                        "FROM users "
                        "WHERE username = :selectedUser");

        query.bindValue(":selectedUser", selectedUser);
        query.exec();
        query.next();

        int contactID = query.value(0).toInt();
        int currentUserID = user.getUserID();

        const QString generatedTopic = user.getUsername() + selectedUser;

        query.prepare("DELETE FROM contacts "
                      "WHERE currentUserID = :currentUserID "
                      "AND contactID = :contactID");
        query.bindValue(":currentUserID", currentUserID);
        query.bindValue(":contactID", contactID);

        query.exec();

        query.prepare("DELETE FROM contacts "
                      "WHERE currentUserID = :contactID "
                      "AND contactID = :currentUserID");
        query.bindValue(":contactID", contactID);
        query.bindValue(":currentUserID", currentUserID);

        query.exec();

        fillListWidgets();
    }
}

void contactsScreen::fillListWidgets(){
    ui->listWidgetUsers->clear();
    ui->listWidgetContacts->clear();

    std::vector<QString> userContacts;
    std::vector<QString>::iterator searchUserContacts;

    userContacts.push_back(user.getUsername());

    QSqlQuery query;

    QString contacts;
    query.prepare("SELECT contactUsername "
                  "FROM contacts "
                  "WHERE currentUserID = :currentUserID ");
    query.bindValue(":currentUserID", user.getUserID());
    query.exec();
    while(query.next()) {
        contacts = query.value(0).toString();
        ui->listWidgetContacts->addItem(contacts);
        userContacts.push_back(contacts);
    }

    QString users;
    query.prepare("SELECT username "
                  "FROM users");
    query.exec();
    while(query.next()) {
        users = query.value(0).toString();
        searchUserContacts = std::find(userContacts.begin(), userContacts.end(), users);
        if (searchUserContacts == userContacts.end()){
            ui->listWidgetUsers->addItem(users);
        }
    }
}

void contactsScreen::on_pushButton_clicked()
{
    close();
}
