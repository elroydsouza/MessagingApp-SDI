#ifndef CHATSCREEN_H
#define CHATSCREEN_H

#include <QMainWindow>
#include <QMqttClient>
#include <QtCore/QDateTime>
#include <QtSql>
#include <QMessageBox>
#include "user.h"
#include "groupsScreen.h"
#include "contactsScreen.h"
#include "profileScreen.h"

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
    void connectedDisconnected();

    void on_buttonSend_clicked();

    void on_buttonUserChat_clicked();

    void on_buttonLogout_clicked();

    void on_buttonCreateGroup_clicked();

    void on_buttonGroupChat_clicked();

    void on_buttonPromote_clicked();

    void on_buttonDemote_clicked();

    void fillListWidgets();

    void checkPermissionLevel();

    void on_buttonRefresh_clicked();

    void on_buttonAddContact_clicked();

    void on_buttonProfile_clicked();

    void logout();

    void resetInactivityTimer();

    void refresh();

    void on_buttonUserPicture_clicked();

private:
    Ui::chatScreen *ui;
    QMqttClient *client;
    User user;
    QString topic;
    QString messageContents;
    QString preparedMessage;
    QString currentGroup;
    std::vector<QString> groupsInComboBox;
    std::vector<QString> contactsInComboBox;
    std::vector<QString> messageUsers;
    int minutesInactive = 0;
    QString otherUser;
};

#endif // CHATSCREEN_H
