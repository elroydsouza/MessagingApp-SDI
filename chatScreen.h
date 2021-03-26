#ifndef CHATSCREEN_H
#define CHATSCREEN_H

#include <QMainWindow>
#include <QMqttClient>
#include <QtCore/QDateTime>
#include <QtSql>
#include <QMessageBox>
#include "user.h"

namespace Ui {
class chatScreen;
}

class chatScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit chatScreen(QWidget *parent = nullptr);
    void acceptUser(User _user);
    void run();
    ~chatScreen();

private slots:
    void updateLogStateChange();

    void on_buttonSend_clicked();

    void on_buttonChat_clicked();

    void on_buttonExit_clicked();

private:
    Ui::chatScreen *ui;
    QMqttClient *client;
    User user;
    QString topic;
    QString messageContents;
    QString preparedMessage;
};

#endif // CHATSCREEN_H
