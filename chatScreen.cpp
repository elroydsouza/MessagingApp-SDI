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

    QString contactUsername;

    std::cout << user.getUsername().toStdString() << std::endl;

    QSqlQuery query("SELECT username "
                    "FROM users");

    while (query.next()) {
        contactUsername = query.value(0).toString();
        if (contactUsername != user.getUsername()){
            ui->comboBoxUsers->addItem(contactUsername);
        }
    }

    // sending of the message
    connect(client, &QMqttClient::messageReceived, this, [this](const QByteArray &message) {
        const QString messageContent = QDateTime::currentDateTime().toString()
                    + QLatin1String(" Message: ")
                    + message
                    + QLatin1Char('\n');
        ui->messageLog->insertPlainText(messageContent);
    });

    // pinging
    connect(client, &QMqttClient::pingResponseReceived, this, [this]() {
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" PingResponse")
                    + QLatin1Char('\n');
        ui->messageLog->insertPlainText(content);
    });

    updateLogStateChange();
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
        query.next();

        if(query.first()){
            std::cout << "exec";
            topic = query.value(0).toString();
            std::cout << topic.toStdString() << std::endl;

            auto subscription = client->subscribe(topic);
            if (!subscription) {
                QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
                return;
            }
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

            auto subscription = client->subscribe(topic);
            if (!subscription) {
                QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
                return;
            }
        }

    } else {
        ui->labelContactName->setText("Select a user");
        ui->comboBoxUsers->setEnabled(true);
        ui->buttonChat->setText("Chat");
        client->disconnectFromHost();
    }
}

void chatScreen::on_buttonSend_clicked()
{
    if(client->publish(topic, ui->lineEditMessageContent->text().toUtf8()) == -1){
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
    }
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
