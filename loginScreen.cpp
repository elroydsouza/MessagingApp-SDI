#include "loginScreen.h"
#include "ui_loginScreen.h"
#include "contactsScreen.h"
#include "currentUser.cpp"

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
    db.setPassword("RF66Ycwa3vI9");
    db.setDatabaseName("messagingApp");

    if(db.open()){
        QMessageBox::information(this,"DATABASE CONNECTED", "Database connection ");

        QString username = ui->username->text();
        QString password = ui->password->text();

        QSqlQuery query(QSqlDatabase::database("MyConnect"));
        query.prepare(QString("SELECT * FROM users "
                              "WHERE username = :username "
                              "AND password = :password"));

        query.bindValue(":username",username);
        query.bindValue(":password",password);

        query.exec();

        if(query.next()){
             QMessageBox::information(this,"Success","You are logged in");

             QSqlQuery query;
             query.prepare(QString("SELECT firstName, lastName "
                                   "FROM users "
                                   "WHERE username = :username"));

             query.bindValue(":username",username);

             query.exec();

             QString firstName = query.value(0).toString();
             QString lastName = query.value(1).toString();

             currentUser currentUser(username, firstName, lastName);

             std::cout << currentUser.currentUsername.toStdString() << std::endl;

             close();

         } else {
             QMessageBox::information(this,"Error","Wrong password or username");
         }

        db.close();

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
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("admin");
    db.setPassword("RF66Ycwa3vI9");
    db.setDatabaseName("messagingApp");

    if(db.open())
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

        db.close();

    } else {
        QMessageBox::information(this,"Not Connected","Database is not connected");
    }
}

void loginScreen::on_shutdownButton_clicked()
{
    this->hide();
    close();
}
