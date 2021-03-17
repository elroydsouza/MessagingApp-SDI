#include "chatScreen.h"
#include "ui_chatscreen.h"

#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>

chatScreen::chatScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chatScreen)
{
    ui->setupUi(this);

    client = new QMqttClient(this);
    client -> setHostname("127.0.0.1");
    client -> setPort(5555);

    connect(client, &QMqttClient::stateChanged, this, &chatScreen::updateLogStateChange);
    connect(client, &QMqttClient::disconnected, this, &chatScreen::brokerDisconnected);
}

chatScreen::~chatScreen()
{
    delete ui;
}

void chatScreen::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(client->state())
                    + QLatin1Char('\n');
    ui->messageLog->insertPlainText(content);
}

void chatScreen::brokerDisconnected()
{
    //ui->buttonConnect->setText(tr("Connect"));
}

void chatScreen::on_buttonSend_clicked()
{

}
