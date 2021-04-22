#include "profileScreen.h"
#include "ui_profileScreen.h"

#include "loginScreen.h"

profileScreen::profileScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::profileScreen)
{
    ui->setupUi(this);
}

void profileScreen::run(){
    ui->labelUsername->setText("Welcome " + user.getUsername() + "!");

    ui->lineEditFirstName->setText(user.getFirstName());
    ui->lineEditLastName->setText(user.getLastName());
}

profileScreen::~profileScreen()
{
    delete ui;
}

void profileScreen::acceptUser(User _user){
    user = _user;
}

void profileScreen::on_buttonChangeName_clicked()
{
    QString firstName = ui->lineEditFirstName->text();
    QString lastName = ui->lineEditLastName->text();

    if(!firstName.isEmpty() || !lastName.isEmpty()){
        QSqlQuery query;
        query.prepare("UPDATE users "
                      "SET firstName = :firstName, lastName = :lastName "
                      "WHERE userID = :userID");

        query.bindValue(":firstName", firstName);
        query.bindValue(":lastName", lastName);
        query.bindValue(":userID", user.getUserID());

        query.exec();

        user.updateFirstName(firstName);
        user.updateLastName(lastName);

        QMessageBox::information(this,"Name changed!","Name has been successfully changed!");

    } else {
        QMessageBox::information(this,"Name not changed!","Name fields cannot be null!");
    }
}

void profileScreen::on_buttonChangePassword_clicked()
{
    QString currentPassword = ui->lineEditCurrentPassword->text();
    QString newPassword = ui->lineEditNewPassword->text();

    if(!currentPassword.isEmpty() || !newPassword.isEmpty()){
        QSqlQuery query;
        query.prepare("SELECT password "
                      "FROM users "
                      "WHERE userID = :userID");
        query.bindValue(":userID", user.getUserID());
        query.exec();
        query.next();

        QString actualPassword = query.value(0).toString();

        currentPassword = encryptPassword(currentPassword);

        if(actualPassword == currentPassword){
            newPassword = encryptPassword(newPassword);
            query.prepare("UPDATE users "
                          "SET password = :newPassword "
                          "WHERE userID = :userID");
            query.bindValue(":userID", user.getUserID());
            query.bindValue(":newPassword", newPassword);
            query.exec();

            QMessageBox::information(this,"Password changed!","Password successfully changed!");
        } else {
            QMessageBox::information(this,"Password not changed!","Current password incorrect!");
        }

    } else {
        QMessageBox::information(this,"Password not changed!","Password fields cannot be null!");
    }
}

QString profileScreen::encryptPassword(QString password) {
    int key = 2;
    std::string encryptedPassword;

    std::string standardPassword = password.toStdString();

    for (int charCodeValue : standardPassword) {
        charCodeValue = charCodeValue + key;

        if (charCodeValue >= 128){
            throw std::invalid_argument("Invalid character!");
        }
        encryptedPassword.push_back(charCodeValue);

    }

    password = QString::fromStdString(encryptedPassword);

    return password;
}

void profileScreen::on_buttonConfirm_clicked()
{
    chatScreen *openChat = new chatScreen;
    openChat->acceptUser(user);
    openChat->show();
    openChat->run();
    close();
}
