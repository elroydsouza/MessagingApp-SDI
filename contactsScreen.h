#ifndef CONTACTSSCREEN_H
#define CONTACTSSCREEN_H

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QString>
#include <QMainWindow>
#include "user.h"
#include <iostream>

namespace Ui {
class contactsScreen;
}

class contactsScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit contactsScreen(QWidget *parent = nullptr);
    void acceptUser(User _user);
    void run();
    ~contactsScreen();

private slots:
    void on_buttonAddContact_clicked();

private:
    Ui::contactsScreen *ui;
    User user;
};

#endif // CONTACTSSCREEN_H
