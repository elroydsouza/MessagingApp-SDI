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
    void setUser(int setUserID, QString setUsername, QString setFirstName, QString setLastName) {
        currentUserID = setUserID;
        currentUsername = setUsername;
        currentFirstName = setFirstName;
        currentLastName = setLastName;
    }

private:
    int currentUserID;
    QString currentUsername;
    QString currentFirstName;
    QString currentLastName;
};

#endif // USER_H
