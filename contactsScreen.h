#ifndef CONTACTSSCREEN_H
#define CONTACTSSCREEN_H

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

#include <QMainWindow>

namespace Ui {
class contactsScreen;
}

class contactsScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit contactsScreen(QWidget *parent = nullptr);
    ~contactsScreen();

private slots:
    void on_buttonAddContact_clicked();

private:
    Ui::contactsScreen *ui;
};

#endif // CONTACTSSCREEN_H
