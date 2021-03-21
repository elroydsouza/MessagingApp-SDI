#include "user.h"

User::User(){

}

QString User::getUsername() {
    return currentUsername;
};

QString User::getFirstName() {
    return currentFirstName;
};

QString User::getLastName() {
    return currentLastName;
};
