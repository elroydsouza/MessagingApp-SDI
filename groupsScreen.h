#ifndef GROUPSSCREEN_H
#define GROUPSSCREEN_H

#include <QMainWindow>
#include <QMqttClient>
#include <QtSql>
#include "user.h"
#include <vector>

namespace Ui {
class groupsScreen;
}

class groupsScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit groupsScreen(QWidget *parent = nullptr);
    void acceptUser(User _user);
    void run();
    ~groupsScreen();

private slots:
    void on_buttonAddMember_clicked();

    void on_buttonCreateGroup_clicked();

private:
    Ui::groupsScreen *ui;
    User user;
    std::vector<QString> groupMembers;
};

#endif // GROUPSSCREEN_H
