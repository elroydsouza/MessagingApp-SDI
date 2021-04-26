#ifndef PROFILESCREEN_H
#define PROFILESCREEN_H

#include <QMainWindow>
#include <QtSql>
#include "user.h"

namespace Ui {
class profileScreen;
}

class profileScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit profileScreen(QWidget *parent = nullptr);
    ~profileScreen();
    void acceptUser(User _user);
    void run();

private slots:

    void on_buttonChangeName_clicked();

    void on_buttonChangePassword_clicked();

    void on_buttonConfirm_clicked();

    QString encryptPassword(QString password);

    void on_buttonPicture1_clicked();

    void on_buttonPicture2_clicked();

    void on_buttonPicture3_clicked();

    void on_buttonPicture4_clicked();

private:
    Ui::profileScreen *ui;
    User user;
};

#endif // PROFILESCREEN_H
