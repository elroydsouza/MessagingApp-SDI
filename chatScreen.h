#ifndef CHATSCREEN_H
#define CHATSCREEN_H

#include <QMqttClient>

#include <QMainWindow>

namespace Ui {
class chatScreen;
}

class chatScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit chatScreen(QWidget *parent = nullptr);
    ~chatScreen();

private slots:
    void updateLogStateChange();
    void brokerDisconnected();

    void on_buttonSend_clicked();

private:
    Ui::chatScreen *ui;
    QMqttClient *client;
};

#endif // CHATSCREEN_H
