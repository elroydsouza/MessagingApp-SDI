#include "groupsScreen.h"
#include "ui_groupsScreen.h"

#include <iostream>

groupsScreen::groupsScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::groupsScreen)
{
    ui->setupUi(this);
    this->setWindowFlags(((windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowCloseButtonHint));
}

void groupsScreen::run() {
    this->setWindowTitle("Create Group");

    QString admin = user.getUsername();
    QString member;

    QSqlQuery query("SELECT username "
                    "FROM users");

    while (query.next()) {
        member = query.value(0).toString();
        if (member != admin){
            ui->comboBoxUsers->addItem(member);
        }
    }

}

groupsScreen::~groupsScreen()
{
    delete ui;
}

void groupsScreen::acceptUser(User _user){
    user = _user;
}

void groupsScreen::on_buttonAddMember_clicked()
{
    QString selectedUser = ui->comboBoxUsers->currentText();

    std::vector<QString>::iterator searchMembers;

    searchMembers = std::find(groupMembers.begin(), groupMembers.end(), selectedUser);

    if (searchMembers == groupMembers.end()) {
        groupMembers.push_back(selectedUser);
        ui->listWidget->addItem(selectedUser);
    }
}

void groupsScreen::on_buttonCreateGroup_clicked()
{
    QString groupName = ui->lineEditGroupName->text();
    int memberID;

    QSqlQuery query;
    query.prepare("INSERT INTO groupChat (memberID, memberUsername, level, topic)"
                "VALUES (:memberID, :memberUsername, 1, :groupName)");

    query.bindValue(":memberID", user.getUserID());
    query.bindValue(":memberUsername", user.getUsername());
    query.bindValue(":groupName", groupName);

    query.exec();

    for (QString addMember : groupMembers) {
        query.prepare("SELECT userID "
                "FROM users "
                "WHERE username = :memberUsername");

        query.bindValue(":memberUsername", addMember);

        query.exec();
        query.next();

        memberID = query.value(0).toInt();

        query.prepare("INSERT INTO groupChat (memberID, memberUsername, level, topic)"
                "VALUES (:memberID, :memberUsername, 3, :groupName)");

        query.bindValue(":memberID", memberID);
        query.bindValue(":memberUsername", addMember);
        query.bindValue(":groupName", groupName);

        query.exec();
    }

    this->hide();
    close();
}

void groupsScreen::on_buttonExit_clicked()
{
    close();
}
