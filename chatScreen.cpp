#include "chatScreen.h"
#include "ui_chatScreen.h"
#include "user.h"
#include "loginScreen.h"

#include <iostream>
#include <QTime>
#include <thread>
#include <chrono>

chatScreen::chatScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chatScreen)
{
    ui->setupUi(this);
    this->setWindowFlags(((windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowCloseButtonHint));
}

void chatScreen::run() {
    this->setWindowTitle("User logged in: " + user.getUsername());

    const QString hostName = "127.0.0.1";
    const int port = 1883;

    client = new QMqttClient(this);
    client -> setHostname(hostName);
    client -> setPort(port);

    connect(client, &QMqttClient::stateChanged, this, &chatScreen::connectedDisconnected);

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
        if (message == "checkActivity"){
            ui->listWidgetActivity->clear();
            messageUsers.clear();

            QString online = "ca/" + user.getUsername();

            if(client->publish(topic, online.toUtf8()) == -1){
                QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
            }
        } else if(message.startsWith("ca/")){
            std::string messageSTD = message.toStdString();
            QString activeUser = QString::fromStdString(messageSTD.substr(3));

            messageUsers.push_back(activeUser);

            ui->listWidgetActivity->clear();

            for(QString user : messageUsers){
                ui->listWidgetActivity->addItem(user + " is active!");
            }

        } else if(message.startsWith("dc/")){
            std::string messageSTD = message.toStdString();
            QString activeUser = QString::fromStdString(messageSTD.substr(3));

            std::vector<QString>::iterator searchActivity;
            searchActivity = std::find(messageUsers.begin(), messageUsers.end(), activeUser);

            if (searchActivity != messageUsers.end()){
                messageUsers.erase(searchActivity);
            }

            ui->listWidgetActivity->clear();

            for(QString user : messageUsers){
                ui->listWidgetActivity->addItem(user + " is active!");
            }

        } else {
            const QString messageContent = QTime::currentTime().toString()
                        + ": "
                        + message
                        + QLatin1Char('\n');
            ui->messageLog->insertPlainText(messageContent);
        }
    });

    connect(client, &QMqttClient::pingResponseReceived, this, [this]() {
        minutesInactive++;
        if (minutesInactive >= 2){
            QMessageBox::information(this,"Disconnected!","You have been logged out for inactivity within a chat room.");
            logout();
        }
    });

    //Set promote/demote buttons visibility on load
    ui->buttonPromote->setEnabled(false);
    ui->buttonDemote->setEnabled(false);

    //Set verticalLayout for the 3 right hand panels hidden on load
    ui->verticalLayout3Panel_2->hide();

    ui->messageLogPanel->setTitle("Select a Group or User:");
    ui->labelUsername->setText(user.getUsername());

    if(user.getProfilePicture() == 1){
        ui->buttonUserPicture->setIcon(QIcon("../MessagingApplication/icons/SDI-photo-1.png"));
        ui->buttonUserPicture->setIconSize(QSize(50,50));
    } else if(user.getProfilePicture() == 2){
        ui->buttonUserPicture->setIcon(QIcon("../MessagingApplication/icons/SDI-photo-2.png"));
        ui->buttonUserPicture->setIconSize(QSize(50,50));
    } else if(user.getProfilePicture() == 3){
        ui->buttonUserPicture->setIcon(QIcon("../MessagingApplication/icons/SDI-photo-3.png"));
        ui->buttonUserPicture->setIconSize(QSize(50,50));
    } else if(user.getProfilePicture() == 4){
       ui->buttonUserPicture->setIcon(QIcon("../MessagingApplication/icons/SDI-photo-4.png"));
       ui->buttonUserPicture->setIconSize(QSize(50,50));
    }

    connectedDisconnected();
    ui->messageLog->clear();
}

chatScreen::~chatScreen()
{
    delete ui;
}

void chatScreen::on_buttonUserChat_clicked()
{
    QString selectedUser = ui->comboBoxContacts->currentText();

    if (selectedUser.toStdString() != "Select a User"){
        otherUser = ui->comboBoxContacts->currentText();
        if(client->state() == QMqttClient::Disconnected){
            ui->messageLogPanel->setTitle("You're chatting with " + selectedUser);
            ui->comboBoxContacts->setEnabled(false);
            ui->comboBoxGroupChats->setEnabled(false);
            ui->buttonGroupChat->setEnabled(false);
            ui->buttonAddContact->setEnabled(false);
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
                QMessageBox::critical(this, QLatin1String("Error!"), QLatin1String("Could not connect to chat!"));
                return;
            }

            QString connectUser = "checkActivity";
            if(client->publish(topic, connectUser.toUtf8()) == -1){
                QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
            }

        } else {
            QString disconnectUser = "dc/" + user.getUsername();
            if(client->publish(topic, disconnectUser.toUtf8()) == -1){
                QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
            }

            ui->listWidgetActivity->clear();

            ui->messageLogPanel->setTitle("Select a Group or User:");
            ui->buttonUserChat->setText("Chat");

            ui->comboBoxContacts->setEnabled(true);
            ui->comboBoxGroupChats->setEnabled(true);
            ui->buttonGroupChat->setEnabled(true);
            ui->buttonAddContact->setEnabled(true);

            client->disconnectFromHost();

            resetInactivityTimer();
        }
    }
    refresh();
}

void chatScreen::on_buttonGroupChat_clicked()
{
    topic = ui->comboBoxGroupChats->currentText();

    if (topic.toStdString() != "Select a Group"){
        if(client->state() == QMqttClient::Disconnected){
            ui->messageLogPanel->setTitle("You're chatting in " + topic);
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

            QString connectUser = "checkActivity";
            if(client->publish(topic, connectUser.toUtf8()) == -1){
                QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
            }

            fillListWidgets();
            checkPermissionLevel();

        } else {

            QString disconnectUser = "dc/" + user.getUsername();
            if(client->publish(topic, disconnectUser.toUtf8()) == -1){
                QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
            }

            ui->listWidgetActivity->clear();

            ui->messageLogPanel->setTitle("Select a Group or User:");
            ui->buttonGroupChat->setText("Chat");

            ui->comboBoxContacts->setEnabled(true);
            ui->comboBoxGroupChats->setEnabled(true);
            ui->buttonUserChat->setEnabled(true);

            ui->verticalLayout3Panel_2->setVisible(false);

            ui->listWidgetAdmin->clear();
            ui->listWidgetModerators->clear();
            ui->listWidgetMembers->clear();

            client->disconnectFromHost();

            resetInactivityTimer();
        }
    }
    refresh();
}

void chatScreen::on_buttonSend_clicked()
{
    messageContents = ui->lineEditMessageContent->text();
    preparedMessage = user.getFullName() + ": " + messageContents;
    if(client->publish(topic, preparedMessage.toUtf8()) == -1){
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
    }
    ui->lineEditMessageContent->clear();
    refresh();
    resetInactivityTimer();
}

void chatScreen::connectedDisconnected()
{
    if(client->state() == 2){
        ui->messageLog->insertPlainText("Connected to chat!\n");
    } else if(client->state() == 0){
        ui->messageLog->insertPlainText("Disconnected from chat!\n");
    }
}

void chatScreen::acceptUser(User _user){
    user = _user;
}

void chatScreen::on_buttonLogout_clicked()
{
    logout();
}

void chatScreen::on_buttonCreateGroup_clicked()
{
    groupsScreen *openGroupScreen = new groupsScreen;
    openGroupScreen->acceptUser(user);
    openGroupScreen->show();
    openGroupScreen->run();
    refresh();
    resetInactivityTimer();
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
    resetInactivityTimer();
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
    resetInactivityTimer();
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
    resetInactivityTimer();
    refresh();
}

void chatScreen::on_buttonAddContact_clicked()
{
    contactsScreen *openContactsScreen = new contactsScreen;
    openContactsScreen->acceptUser(user);
    openContactsScreen->show();
    openContactsScreen->run();
    refresh();
    resetInactivityTimer();
}

void chatScreen::on_buttonProfile_clicked()
{
    QString disconnectUser = "dc/" + user.getUsername();
    client->publish(topic, disconnectUser.toUtf8());

    if(client->state() != QMqttClient::Disconnected){
        client->disconnectFromHost();
    }

    profileScreen *openProfileScreen = new profileScreen;
    openProfileScreen->acceptUser(user);
    openProfileScreen->show();
    openProfileScreen->run();
    close();
}

void chatScreen::logout(){
    QString disconnectUser = "dc/" + user.getUsername();
    client->publish(topic, disconnectUser.toUtf8());

    if(client->state() != QMqttClient::Disconnected){
        client->disconnectFromHost();
    }

    loginScreen *openLoginScreen = new loginScreen;
    openLoginScreen->show();

    close();
}

void chatScreen::resetInactivityTimer(){
    minutesInactive = 0;
}

void chatScreen::refresh(){
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
    ui->comboBoxContacts->setCurrentText(otherUser);
    resetInactivityTimer();
}

void chatScreen::on_buttonUserPicture_clicked()
{
    on_buttonProfile_clicked();
}
