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
