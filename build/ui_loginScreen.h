/********************************************************************************
** Form generated from reading UI file 'loginScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSCREEN_H
#define UI_LOGINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginScreen
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_27;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonLogo;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_7;
    QWidget *Form;
    QHBoxLayout *horizontalLayout_24;
    QWidget *registerForm;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *registerUsername;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *registerPassword;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *registerFirstName;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *registerLastName;
    QPushButton *registerButton;
    QSpacerItem *horizontalSpacer_7;
    QWidget *loginForm;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_14;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_15;
    QLineEdit *password;
    QSpacerItem *verticalSpacer_6;
    QPushButton *loginButton;
    QSpacerItem *verticalSpacer;
    QWidget *topPanel;
    QHBoxLayout *horizontalLayout_23;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *shutdownButton;

    void setupUi(QWidget *loginScreen)
    {
        if (loginScreen->objectName().isEmpty())
            loginScreen->setObjectName(QString::fromUtf8("loginScreen"));
        loginScreen->resize(750, 500);
        loginScreen->setStyleSheet(QString::fromUtf8("#loginScreen {background-color: rgb(196, 197, 231)}"));
        verticalLayout = new QVBoxLayout(loginScreen);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_8);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        horizontalLayout_27->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer);

        buttonLogo = new QPushButton(loginScreen);
        buttonLogo->setObjectName(QString::fromUtf8("buttonLogo"));
        buttonLogo->setMinimumSize(QSize(150, 150));

        horizontalLayout_27->addWidget(buttonLogo);

        label_20 = new QLabel(loginScreen);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        QFont font;
        font.setPointSize(20);
        label_20->setFont(font);

        horizontalLayout_27->addWidget(label_20);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_27);

        verticalSpacer_7 = new QSpacerItem(20, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        Form = new QWidget(loginScreen);
        Form->setObjectName(QString::fromUtf8("Form"));
        Form->setStyleSheet(QString::fromUtf8("#Form {border: 1px solid; background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgb(154, 145, 235), stop:1 rgb(201, 197, 230));}"));
        horizontalLayout_24 = new QHBoxLayout(Form);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(9, 9, 9, 9);
        registerForm = new QWidget(Form);
        registerForm->setObjectName(QString::fromUtf8("registerForm"));
        registerForm->setStyleSheet(QString::fromUtf8("#registerForm {border: 1px solid;}"));
        verticalLayout_4 = new QVBoxLayout(registerForm);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_3 = new QLabel(registerForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_10->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(8, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        registerUsername = new QLineEdit(registerForm);
        registerUsername->setObjectName(QString::fromUtf8("registerUsername"));
        registerUsername->setMaxLength(15);

        horizontalLayout_10->addWidget(registerUsername);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_4 = new QLabel(registerForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_9->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        registerPassword = new QLineEdit(registerForm);
        registerPassword->setObjectName(QString::fromUtf8("registerPassword"));
        registerPassword->setMaxLength(15);
        registerPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_9->addWidget(registerPassword);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, 0, -1, -1);
        label_2 = new QLabel(registerForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_8->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(4, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);

        registerFirstName = new QLineEdit(registerForm);
        registerFirstName->setObjectName(QString::fromUtf8("registerFirstName"));
        registerFirstName->setMaxLength(15);

        horizontalLayout_8->addWidget(registerFirstName);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(registerForm);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_6->addWidget(label);

        horizontalSpacer_6 = new QSpacerItem(6, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        registerLastName = new QLineEdit(registerForm);
        registerLastName->setObjectName(QString::fromUtf8("registerLastName"));
        registerLastName->setMaxLength(15);

        horizontalLayout_6->addWidget(registerLastName);


        verticalLayout_4->addLayout(horizontalLayout_6);

        registerButton = new QPushButton(registerForm);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));

        verticalLayout_4->addWidget(registerButton);


        horizontalLayout_24->addWidget(registerForm);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_7);

        loginForm = new QWidget(Form);
        loginForm->setObjectName(QString::fromUtf8("loginForm"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginForm->sizePolicy().hasHeightForWidth());
        loginForm->setSizePolicy(sizePolicy);
        loginForm->setMinimumSize(QSize(0, 0));
        loginForm->setStyleSheet(QString::fromUtf8("#loginForm { border: 1px solid; }"));
        verticalLayout_6 = new QVBoxLayout(loginForm);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(9, 9, 9, 9);
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_17 = new QLabel(loginForm);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(0, 25));

        horizontalLayout_25->addWidget(label_17);

        horizontalSpacer_14 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_14);

        username = new QLineEdit(loginForm);
        username->setObjectName(QString::fromUtf8("username"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(username->sizePolicy().hasHeightForWidth());
        username->setSizePolicy(sizePolicy1);
        username->setMinimumSize(QSize(0, 0));
        username->setMaxLength(15);

        horizontalLayout_25->addWidget(username);


        verticalLayout_6->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        horizontalLayout_26->setContentsMargins(-1, 0, -1, 0);
        label_18 = new QLabel(loginForm);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_26->addWidget(label_18);

        horizontalSpacer_15 = new QSpacerItem(7, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_15);

        password = new QLineEdit(loginForm);
        password->setObjectName(QString::fromUtf8("password"));
        sizePolicy1.setHeightForWidth(password->sizePolicy().hasHeightForWidth());
        password->setSizePolicy(sizePolicy1);
        password->setMaxLength(15);
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout_26->addWidget(password);


        verticalLayout_6->addLayout(horizontalLayout_26);

        verticalSpacer_6 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_6);

        loginButton = new QPushButton(loginForm);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        verticalLayout_6->addWidget(loginButton);


        horizontalLayout_24->addWidget(loginForm);


        verticalLayout->addWidget(Form);

        verticalSpacer = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        topPanel = new QWidget(loginScreen);
        topPanel->setObjectName(QString::fromUtf8("topPanel"));
        topPanel->setStyleSheet(QString::fromUtf8("#topPanel { border: 1px solid; background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgb(154, 145, 235), stop:1 rgb(201, 197, 230)); }"));
        horizontalLayout_23 = new QHBoxLayout(topPanel);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_13);

        shutdownButton = new QPushButton(topPanel);
        shutdownButton->setObjectName(QString::fromUtf8("shutdownButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(shutdownButton->sizePolicy().hasHeightForWidth());
        shutdownButton->setSizePolicy(sizePolicy2);
        shutdownButton->setMinimumSize(QSize(40, 40));
        shutdownButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_23->addWidget(shutdownButton);


        verticalLayout->addWidget(topPanel);


        retranslateUi(loginScreen);

        QMetaObject::connectSlotsByName(loginScreen);
    } // setupUi

    void retranslateUi(QWidget *loginScreen)
    {
        loginScreen->setWindowTitle(QApplication::translate("loginScreen", "Form", nullptr));
        buttonLogo->setText(QString());
        label_20->setText(QApplication::translate("loginScreen", "Messaging Application", nullptr));
        label_3->setText(QApplication::translate("loginScreen", "Username:", nullptr));
        label_4->setText(QApplication::translate("loginScreen", "Password:", nullptr));
        label_2->setText(QApplication::translate("loginScreen", "First Name:", nullptr));
        label->setText(QApplication::translate("loginScreen", "Last Name:", nullptr));
        registerButton->setText(QApplication::translate("loginScreen", "Register", nullptr));
        label_17->setText(QApplication::translate("loginScreen", "Username:", nullptr));
        label_18->setText(QApplication::translate("loginScreen", "Password:", nullptr));
        loginButton->setText(QApplication::translate("loginScreen", "Login", nullptr));
        shutdownButton->setText(QApplication::translate("loginScreen", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginScreen: public Ui_loginScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSCREEN_H
