#include "loginScreen.h"
#include "ui_loginScreen.h"
#include "contactsScreen.h"
#include "chatScreen.h"
#include "user.h"

#include <QDebug>
#include <QTimer>
#include <QTime>

#include <iostream>

loginScreen::loginScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginScreen)
{
    ui->setupUi(this);

    ui->username->setPlaceholderText("Enter Username");
    ui->password->setPlaceholderText("Enter Password");

    ui->registerUsername->setPlaceholderText("Enter Username");
    ui->registerPassword->setPlaceholderText("Enter Password");
    ui->registerFirstName->setPlaceholderText("Enter First Name");
    ui->registerLastName->setPlaceholderText("Enter Last Name");

    timer_ls = new QTimer(this);
    QObject::connect(timer_ls, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer_ls -> start(1000);

    ui->currentDateTime->setText(QTime::currentTime().toString("hh:mm:ss"));
}

loginScreen::~loginScreen()
{
    delete ui;
}

/*!
 *  The login button pressed function
 *
 *  When the button is pressed the application establishes a connection to the database,
 *  the database is then checked to see if the user exists within the 'users' table. If
 *  it does, then the user should be successfully logged in, if not it displays an error.
 */
void loginScreen::on_loginButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("admin");
    db.setPassword("q8YqwopxETsR");
    db.setDatabaseName("messagingApp");

    if(db.open()){
        QString username = ui->username->text();
        QString password = ui->password->text();

        QSqlQuery query;
        query.prepare(QString("SELECT * FROM users "
                              "WHERE username = :username "
                              "AND password = :password"));

        query.bindValue(":username",username);
        query.bindValue(":password",password);

        query.exec();

        if(query.next()){
             QMessageBox::information(this,"Success","You are logged in");

             QSqlQuery query;
             query.prepare(QString("SELECT userID, firstName, lastName "
                                   "FROM users "
                                   "WHERE username = :username"));

             query.bindValue(":username",username);
             query.exec();
             query.next();

             int userID = query.value(0).toInt();
             QString firstName = query.value(1).toString();
             QString lastName = query.value(2).toString();

             User user = User();
             user.setUser(userID, username, firstName, lastName);

             chatScreen *openChat = new chatScreen;
             openChat->acceptUser(user);
             openChat->show();
             openChat->run();
             close();

         } else {
             QMessageBox::information(this,"Error","Wrong password or username");
         }


    } else {
        QMessageBox::information(this,"Not Connected","Database is not connected");
    }
}

/*!
 *  The register button pressed function
 *
 *  When the button is pressed the application establishes a connection to the database,
 *  It inserts the user's information into the 'users' table.
 */
void loginScreen::on_registerButton_clicked()
{
    QMessageBox::information(this,"DATABASE CONNECTED", "Database connection ");

    QString registerUsername = ui->registerUsername->text();
    QString registerPassword = ui->registerPassword->text();
    QString registerFirstName = ui->registerFirstName->text();
    QString registerLastName = ui->registerLastName->text();

    QSqlQuery query;
    query.prepare(QString("INSERT INTO users (username, password, firstName, lastName)"
                          "VALUES (:registerUsername, :registerPassword, :registerFirstName, :registerLastName)"));

    query.bindValue(":registerUsername",registerUsername);
    query.bindValue(":registerPassword",registerPassword);
    query.bindValue(":registerFirstName",registerFirstName);
    query.bindValue(":registerLastName",registerLastName);

    if(query.exec()){
        ui->registerUsername->clear();
        ui->registerPassword->clear();
        ui->registerFirstName->clear();
        ui->registerLastName->clear();

        QMessageBox::information(this,"Registration successful","Account has been created");

    } else {
        QMessageBox::information(this,"Registration unsuccessful","Account was not created");
    }

}

void loginScreen::on_shutdownButton_clicked()
{
    this->hide();
    close();
}
