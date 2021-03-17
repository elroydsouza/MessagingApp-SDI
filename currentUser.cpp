#include <QMessageBox>

class currentUser
{
public:
    QString currentUsername;
    QString currentFirstName;
    QString currentLastName;

    currentUser(QString username, QString firstName, QString lastName) {
        currentUsername = username;
        currentFirstName = firstName;
        currentLastName = lastName;
    }
};
