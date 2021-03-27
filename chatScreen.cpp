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

    QSqlQuery query("SELECT username "
                    "FROM users");

    while (query.next()) {
        contactUsername = query.value(0).toString();
        if (contactUsername != user.getUsername()){
            ui->comboBoxUsers->addItem(contactUsername);
        }
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

    ui->verticalLayout3Panel_2->hide();

    //std::thread refresh (&chatScreen::refreshPanel, this);

    updateLogStateChange();
}

chatScreen::~chatScreen()
{
    delete ui;
}

void chatScreen::on_buttonUserChat_clicked()
{
    QString selectedUser = ui->comboBoxUsers->currentText();

    if (selectedUser.toStdString() != "Select a User"){
        if(client->state() == QMqttClient::Disconnected){
            ui->labelChatName->setText(selectedUser);
            ui->comboBoxUsers->setEnabled(false);
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

            if(query.first()){
                topic = query.value(0).toString();

                auto subscription = client->subscribe(topic, 1);
                if (!subscription) {
                    QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
                    return;
                }

                ui->labelChatName->setText(selectedUser + " [online]");

            } else {
                const QString generatedTopic = user.getUsername() + selectedUser;

                query.prepare("INSERT INTO contacts (currentUserID, contactID, topic) "
                              "VALUES (:currentUserID, :contactID, :generatedTopic)");
                query.bindValue(":currentUserID", currentUserID);
                query.bindValue(":contactID", contactID);
                query.bindValue(":generatedTopic", generatedTopic);

                query.exec();

                query.prepare("INSERT INTO contacts (currentUserID, contactID, topic) "
                              "VALUES (:contactID, :currentUserID, :generatedTopic)");
                query.bindValue(":contactID", contactID);
                query.bindValue(":currentUserID", currentUserID);
                query.bindValue(":generatedTopic", generatedTopic);

                query.exec();

                topic = generatedTopic;

                auto subscription = client->subscribe(topic, 1);
                if (!subscription) {
                    QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
                    return;
                }
            }

        } else {
            ui->labelChatName->setText("Select a user");
            ui->comboBoxUsers->setEnabled(true);
            ui->comboBoxGroupChats->setEnabled(true);
            ui->buttonGroupChat->setEnabled(true);
            ui->buttonUserChat->setText("Chat");
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
            ui->comboBoxUsers->setEnabled(false);
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
            ui->comboBoxUsers->setEnabled(true);
            ui->comboBoxGroupChats->setEnabled(true);
            ui->buttonUserChat->setEnabled(true);
            ui->buttonGroupChat->setText("Chat");
            client->disconnectFromHost();
            ui->verticalLayout3Panel_2->setVisible(false);
            ui->listWidgetAdmin->clear();
            ui->listWidgetModerators->clear();
            ui->listWidgetMembers->clear();
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


void chatScreen::updateLogStateChange() // Remove later
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
    QString currentMember = ui->listWidgetMembers->currentItem()->text();

    if(currentMember != ""){
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

//void chatScreen::refreshPanel(){
//    while(true){
//        std::cout << "5 seconds" << std::endl;
////        fillListWidgets();
////        checkPermissionLevel();

//        std::this_thread::sleep_for(std::chrono::seconds(5));
//    }
//}

void chatScreen::fillListWidgets(){
    ui->listWidgetAdmin->clear();
    ui->listWidgetModerators->clear();
    ui->listWidgetMembers->clear();

    QString admin;
    QSqlQuery query;
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

    std::cout << userLevel << std::endl;

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
