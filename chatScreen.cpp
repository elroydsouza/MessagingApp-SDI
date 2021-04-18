#include "chatScreen.h"
#include "ui_chatScreen.h"
#include "user.h"

#include <iostream>
#include <QTime>
#include <thread>
#include <chrono>

chatScreen::chatScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chatScreen)
{
    ui->setupUi(this);
}

void chatScreen::run() {
    const QString hostName = "127.0.0.1";
    const int port = 1883;

    client = new QMqttClient(this);
    client -> setHostname(hostName);
    client -> setPort(port);

    connect(client, &QMqttClient::stateChanged, this, &chatScreen::updateLogStateChange); // Remove later

    //Fills combo box Users
    QString contactUsername;

    QSqlQuery query;
    query.prepare("SELECT contactUsername "
                  "FROM contacts "
                  "WHERE currentUserID = :currentUserID");

    query.bindValue(":currentUserID", user.getUserID());

    query.exec();

    while (query.next()) {
        contactUsername = query.value(0).toString();
        contactsInComboBox.push_back(contactUsername);
        ui->comboBoxContacts->addItem(contactUsername);
    }

    //Fills combo box Groups
    QString groupName;

    query.prepare("SELECT topic "
                  "FROM groupChat "
                  "WHERE memberID = :currentID");

    query.bindValue(":currentID", user.getUserID());

    query.exec();

    while (query.next()) {
        groupName = query.value(0).toString();
        groupsInComboBox.push_back(groupName);
        ui->comboBoxGroupChats->addItem(groupName);
    }

    //Sending of the message
    connect(client, &QMqttClient::messageReceived, this, [this](const QByteArray &message) {
        const QString messageContent = QTime::currentTime().toString()
                    + ": "
                    + message
                    + QLatin1Char('\n');
        ui->messageLog->insertPlainText(messageContent);
    });

    //Set promote/demote buttons visibility on load
    ui->buttonPromote->setEnabled(false);
    ui->buttonDemote->setEnabled(false);

    //Set verticalLayout for the 3 right hand panels hidden on load
    ui->verticalLayout3Panel_2->hide();

    updateLogStateChange();
}

chatScreen::~chatScreen()
{
    delete ui;
}

void chatScreen::on_buttonUserChat_clicked()
{
    QString selectedUser = ui->comboBoxContacts->currentText();

    if (selectedUser.toStdString() != "Select a User"){
        if(client->state() == QMqttClient::Disconnected){
            ui->labelChatName->setText(selectedUser);
            ui->comboBoxContacts->setEnabled(false);
            ui->comboBoxGroupChats->setEnabled(false);
            ui->buttonGroupChat->setEnabled(false);
            ui->buttonUserChat->setText("Stop Chatting");
            client->connectToHost();

            // Check contacts table, if not add contact
            QMessageBox::information(this,"Connected","You're now chatting with " + selectedUser + "!");
            QSqlQuery query;
            query.prepare("SELECT userID "
                            "FROM users "
                            "WHERE username = :selectedUser");

            query.bindValue(":selectedUser", selectedUser);
            query.exec();
            query.next();

            int contactID = query.value(0).toInt();
            int currentUserID = user.getUserID();

            query.prepare("SELECT topic "
                          "FROM contacts "
                          "WHERE currentUserID = :currentUserID "
                          "AND contactID = :contactID");

            query.bindValue(":currentUserID", currentUserID);
            query.bindValue(":contactID", contactID);

            query.exec();
            query.next();

            topic = query.value(0).toString();

            auto subscription = client->subscribe(topic, 1);
            if (!subscription) {
                QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
                return;
            }

            QString online = user.getUsername() + " is online!";

            if(client->publish(topic, online.toUtf8()) == -1){
                QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
            }

            //ui->labelChatName->setText(selectedUser + " [online]");

        } else {
            ui->labelChatName->setText("Select a user");
            ui->buttonUserChat->setText("Chat");

            ui->comboBoxContacts->setEnabled(true);
            ui->comboBoxGroupChats->setEnabled(true);
            ui->buttonGroupChat->setEnabled(true);

            client->disconnectFromHost();
        }
    }

}

void chatScreen::on_buttonGroupChat_clicked()
{
    topic = ui->comboBoxGroupChats->currentText();

    if (topic.toStdString() != "Select a Group"){
        if(client->state() == QMqttClient::Disconnected){
            ui->labelChatName->setText(topic);
            ui->comboBoxContacts->setEnabled(false);
            ui->comboBoxGroupChats->setEnabled(false);
            ui->buttonUserChat->setEnabled(false);
            ui->buttonGroupChat->setText("Stop Chatting");
            client->connectToHost();

            ui->verticalLayout3Panel_2->setVisible(true);

            QMessageBox::information(this,"Connected","You're now chatting in " + topic + "!");

            auto subscription = client->subscribe(topic, 1);
            if (!subscription) {
                QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
                return;
            }

            fillListWidgets();
            checkPermissionLevel();

        } else {
            ui->labelChatName->setText("Select a Chat");
            ui->buttonGroupChat->setText("Chat");

            ui->comboBoxContacts->setEnabled(true);
            ui->comboBoxGroupChats->setEnabled(true);
            ui->buttonUserChat->setEnabled(true);

            ui->verticalLayout3Panel_2->setVisible(false);

            ui->listWidgetAdmin->clear();
            ui->listWidgetModerators->clear();
            ui->listWidgetMembers->clear();

            client->disconnectFromHost();
        }
    }
}

void chatScreen::on_buttonSend_clicked()
{
    messageContents = ui->lineEditMessageContent->text();
    preparedMessage = user.getFullName() + ": " + messageContents;
    if(client->publish(topic, preparedMessage.toUtf8()) == -1){
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
    }
    ui->lineEditMessageContent->clear();
}

void chatScreen::updateLogStateChange() ////////////////////////////////////// Remove later
{
    const QString content = QTime::currentTime().toString()
                    + QLatin1String(": State Change ")
                    + QString::number(client->state())
                    + QLatin1Char('\n');
    ui->messageLog->insertPlainText(content);
}

void chatScreen::acceptUser(User _user){
    user = _user;
}

void chatScreen::on_buttonExit_clicked()
{
    this->hide();
    close();
}

void chatScreen::on_buttonCreateGroup_clicked()
{
    groupsScreen *openGroupScreen = new groupsScreen;
    openGroupScreen->acceptUser(user);
    openGroupScreen->show();
    openGroupScreen->run();
}

void chatScreen::on_buttonPromote_clicked()
{
    if(ui->listWidgetMembers->selectedItems().count() != 0){
        QString currentMember = ui->listWidgetMembers->currentItem()->text();

        QSqlQuery query;
        query.prepare("UPDATE groupChat "
                      "SET level = 2 "
                      "WHERE memberUsername = :currentMember "
                      "AND topic = :currentGroup");

        query.bindValue(":currentMember", currentMember);
        query.bindValue(":currentGroup", topic);
        query.exec();

        fillListWidgets();
        checkPermissionLevel();
    }
}

void chatScreen::on_buttonDemote_clicked()
{
    if(ui->listWidgetModerators->selectedItems().count() != 0){
        QString currentMember = ui->listWidgetModerators->currentItem()->text();

        QSqlQuery query;
        query.prepare("UPDATE groupChat "
                      "SET level = 3 "
                      "WHERE memberUsername = :currentMember "
                      "AND topic = :currentGroup");

        query.bindValue(":currentMember", currentMember);
        query.bindValue(":currentGroup", topic);
        query.exec();

        fillListWidgets();
        checkPermissionLevel();
    }
}

void chatScreen::fillListWidgets(){
    ui->listWidgetAdmin->clear();
    ui->listWidgetModerators->clear();
    ui->listWidgetMembers->clear();

    QSqlQuery query;

    QString admin;
    query.prepare("SELECT memberUsername "
                  "FROM groupChat "
                  "WHERE topic = :currentGroup "
                  "AND level = 1");
    query.bindValue(":currentGroup", topic);
    query.exec();
    query.next();
    admin = query.value(0).toString();
    ui->listWidgetAdmin->addItem(admin);

    QString moderator;
    query.prepare("SELECT memberUsername "
                  "FROM groupChat "
                  "WHERE topic = :currentGroup "
                  "AND level = 2");
    query.bindValue(":currentGroup", topic);
    query.exec();
    while(query.next()) {
        moderator = query.value(0).toString();
        ui->listWidgetModerators->addItem(moderator);
    }

    QString member;
    query.prepare("SELECT memberUsername "
                  "FROM groupChat "
                  "WHERE topic = :currentGroup "
                  "AND level = 3");
    query.bindValue(":currentGroup", topic);
    query.exec();
    while(query.next()) {
        member = query.value(0).toString();
        ui->listWidgetMembers->addItem(member);
    }
}

void chatScreen::checkPermissionLevel(){
    QSqlQuery query;
    query.prepare("SELECT level "
                  "FROM groupChat "
                  "WHERE topic = :currentGroup "
                  "AND memberUsername = :currentUser");

    query.bindValue(":currentGroup", topic);
    query.bindValue(":currentUser", user.getUsername());

    query.exec();
    query.next();

    int userLevel = query.value(0).toInt();

    switch(userLevel){
        case 3:
            ui->buttonPromote->setEnabled(false);
            ui->buttonDemote->setEnabled(false);
            break;
        default:
            ui->buttonPromote->setEnabled(true);
            ui->buttonDemote->setEnabled(true);
            break;
    }
}

void chatScreen::on_buttonRefresh_clicked()
{
    QString groupChatActive = ui->buttonGroupChat->text();
    if (groupChatActive == "Stop Chatting"){
        fillListWidgets();
        checkPermissionLevel();
    }

    std::vector<QString>::iterator searchGroups;
    QString groupName;

    QSqlQuery query;
    query.prepare("SELECT topic "
                  "FROM groupChat "
                  "WHERE memberID = :currentID");

    query.bindValue(":currentID", user.getUserID());

    query.exec();

    while (query.next()) {
        groupName = query.value(0).toString();
        searchGroups = std::find(groupsInComboBox.begin(), groupsInComboBox.end(), groupName);

        if (searchGroups == groupsInComboBox.end()) {
            groupsInComboBox.push_back(groupName);
            ui->comboBoxGroupChats->addItem(groupName);
        }
    }

    std::vector<QString>::iterator searchContacts;
    QString contactUsername;

    query.prepare("SELECT contactUsername "
                  "FROM contacts "
                  "WHERE currentUserID = :currentUserID");

    query.bindValue(":currentUserID", user.getUserID());

    query.exec();

    ui->comboBoxContacts->clear();
    ui->comboBoxContacts->addItem("Select a User");
    while (query.next()) {
        contactUsername = query.value(0).toString();
        searchContacts = std::find(contactsInComboBox.begin(), contactsInComboBox.end(), contactUsername);

        contactsInComboBox.push_back(contactUsername);
        ui->comboBoxContacts->addItem(contactUsername);
    }
}

void chatScreen::on_buttonAddContact_clicked()
{
    contactsScreen *openContactsScreen = new contactsScreen;
    openContactsScreen->acceptUser(user);
    openContactsScreen->show();
    openContactsScreen->run();
}
