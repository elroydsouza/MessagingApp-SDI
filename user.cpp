#include "user.h"

User::User(){

}

int User::getUserID() {
    return currentUserID;
};

QString User::getUsername() {
    return currentUsername;
};

QString User::getFirstName() {
    return currentFirstName;
};

QString User::getLastName() {
    return currentLastName;
};

QString User::getFullName() {
    QString currentFullName = getFirstName() + " " + getLastName();
    return currentFullName;
};

void User::updateFirstName(QString name){
    currentFirstName = name;
};

void User::updateLastName(QString name){
    currentLastName = name;
};
