#include "chatScreen.h"
#include "ui_chatScreen.h"
#include "user.h"

#include <iostream>

chatScreen::chatScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chatScreen)
{
    ui->setupUi(this);

    const QString hostName = "127.0.0.1";
    const int port = 1883;

    client = new QMqttClient(this);
    client -> setHostname(hostName);
    client -> setPort(port);

    connect(client, &QMqttClient::stateChanged, this, &chatScreen::updateLogStateChange); //Remove later

    // Set combo box to all users in database
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

    } else {
        QMessageBox::information(this,"Not Connected","Database is not connected");
    }

    db.close();
    QSqlDatabase::removeDatabase("QMYSQL");

    connect(client, &QMqttClient::messageReceived, this, [this](const QByteArray &message) {
        const QString messageContent = QDateTime::currentDateTime().toString()
                    + QLatin1String(" Message: ")
                    + message
                    + QLatin1Char('\n');
        ui->messageLog->insertPlainText(messageContent);
    });

}

chatScreen::~chatScreen()
{
    delete ui;
}

void chatScreen::on_buttonChat_clicked()
{
    if(client->state() == QMqttClient::Disconnected){
        QString selectedUser = ui->comboBoxUsers->currentText();
        ui->labelContactName->setText(selectedUser);
        ui->comboBoxUsers->setEnabled(false);
        ui->buttonChat->setText("Stop Chatting");
        client->connectToHost();

        // Check contacts table, if not add contact
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("admin");
        db.setPassword("RF66Ycwa3vI9");
        db.setDatabaseName("messagingApp");

        if(db.open())
        {
            QMessageBox::information(this,"Connected","Database is connected");
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

            if(query.first()){
                std::cout << "exec";
                query.next();
                topic = query.value(0).toString();
            } else {
                std::cout << "else";
                QString generatedTopic = user.getUsername() + selectedUser;

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
            }



        } else {
            QMessageBox::information(this,"Not Connected","Database is not connected");
        }

        db.close();


    } else {
        ui->labelContactName->setText("Select a user");
        ui->comboBoxUsers->setEnabled(true);
        ui->buttonChat->setText("Chat");
        client->disconnectFromHost();
    }
}

void chatScreen::on_buttonSend_clicked()
{
    client->publish(topic, ui->lineEditMessageContent->text().toUtf8());
}


void chatScreen::updateLogStateChange() // Remove later
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(client->state())
                    + QLatin1Char('\n');
    ui->messageLog->insertPlainText(content);
}

void chatScreen::acceptUser(User _user){
    user = _user;
}
