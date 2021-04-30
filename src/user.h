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
    int getProfilePicture();
    void setUser(int setUserID, QString setUsername, QString setFirstName, QString setLastName, int setProfilePicture) {
        currentUserID = setUserID;
        currentUsername = setUsername;
        currentFirstName = setFirstName;
        currentLastName = setLastName;
        currentProfilePicture = setProfilePicture;
    }
    void updateFirstName(QString name);
    void updateLastName(QString name);
    void updateProfilePicture(int picture);

private:
    int currentUserID;
    QString currentUsername;
    QString currentFirstName;
    QString currentLastName;
    int currentProfilePicture;
};

#endif // USER_H
