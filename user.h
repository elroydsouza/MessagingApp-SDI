#ifndef USER_H
#define USER_H
#include <QString>

class User
{
public:
    User();
    QString getUsername();
    QString getFirstName();
    QString getLastName();
    void setUser(QString setUsername, QString setFirstName, QString setLastName) {
        currentUsername = setUsername;
        currentFirstName = setFirstName;
        currentLastName = setLastName;
    }

private:
    QString currentUsername;
    QString currentFirstName;
    QString currentLastName;
};

#endif // USER_H
