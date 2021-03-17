#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

#include <QWidget>

namespace Ui {
class loginScreen;
}

class loginScreen : public QWidget
{
    Q_OBJECT

public:
    explicit loginScreen(QWidget *parent = nullptr);
    ~loginScreen();

private slots:
    void on_loginButton_clicked();

    void on_shutdownButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::loginScreen *ui;

    QSqlDatabase database;

    QTimer *timer_ls;
};

#endif // LOGINSCREEN_H
