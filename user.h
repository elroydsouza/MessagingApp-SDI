#ifndef USER_H
#define USER_H
#include <QString>

class User
{
public:
    User();
    int getUserID();
    QString getUsername();
    QString getFirstName();
    QString getLastName();
    QString getFullName();
    void setUser(int setUserID, QString setUsername, QString setFirstName, QString setLastName) {
        currentUserID = setUserID;
        currentUsername = setUsername;
        currentFirstName = setFirstName;
        currentLastName = setLastName;
        currentFullName = setFirstName + " " + setLastName;
    }

private:
    int currentUserID;
    QString currentUsername;
    QString currentFirstName;
    QString currentLastName;
    QString currentFullName;
};

#endif // USER_H
