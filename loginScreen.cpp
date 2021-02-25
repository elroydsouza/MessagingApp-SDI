#include "loginScreen.h"
#include "ui_loginScreen.h"
#include<QDebug>

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
}

loginScreen::~loginScreen()
{
    delete ui;
}

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
        query.prepare(QString("SELECT * FROM users WHERE username = :username AND password = :password"));

        query.bindValue(":username",username);
        query.bindValue(":password",password);

        query.exec();

        if(query.next()){
             QMessageBox::information(this,"Success","You are logged in");

             //closes window
             this->hide();
             db.close();
             close();

         } else {
             QMessageBox::information(this,"Error","Wrong password or username");
         }

    } else {
        QMessageBox::information(this,"Not Connected","Database is not connected");
    }
}

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

    } else {
        QMessageBox::information(this,"Not Connected","Database is not connected");
    }
}

void loginScreen::on_shutdownButton_clicked()
{
    this->hide();
    close();
}
