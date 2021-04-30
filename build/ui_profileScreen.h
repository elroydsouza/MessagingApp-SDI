/********************************************************************************
** Form generated from reading UI file 'profileScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILESCREEN_H
#define UI_PROFILESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_profileScreen
{
public:
    QWidget *profilePanel;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelUsername;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QWidget *editPanel;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEditFirstName;
    QLabel *label_3;
    QLineEdit *lineEditLastName;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *buttonChangeName;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLineEdit *lineEditCurrentPassword;
    QLabel *label_5;
    QLineEdit *lineEditNewPassword;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *buttonChangePassword;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *buttonPicture1;
    QPushButton *buttonPicture2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *buttonPicture3;
    QPushButton *buttonPicture4;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonConfirm;

    void setupUi(QMainWindow *profileScreen)
    {
        if (profileScreen->objectName().isEmpty())
            profileScreen->setObjectName(QString::fromUtf8("profileScreen"));
        profileScreen->resize(750, 300);
        profilePanel = new QWidget(profileScreen);
        profilePanel->setObjectName(QString::fromUtf8("profilePanel"));
        profilePanel->setStyleSheet(QString::fromUtf8("#profilePanel {background-color: rgb(196, 197, 231)}"));
        verticalLayout_2 = new QVBoxLayout(profilePanel);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelUsername = new QLabel(profilePanel);
        labelUsername->setObjectName(QString::fromUtf8("labelUsername"));

        verticalLayout_2->addWidget(labelUsername);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, 0, -1);
        editPanel = new QWidget(profilePanel);
        editPanel->setObjectName(QString::fromUtf8("editPanel"));
        editPanel->setStyleSheet(QString::fromUtf8("#editPanel {border: 1px solid; background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgb(154, 145, 235), stop:1 rgb(201, 197, 230));}"));
        horizontalLayout_2 = new QHBoxLayout(editPanel);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, 9, 9, 9);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(editPanel);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        lineEditFirstName = new QLineEdit(editPanel);
        lineEditFirstName->setObjectName(QString::fromUtf8("lineEditFirstName"));
        lineEditFirstName->setMaxLength(15);

        verticalLayout_3->addWidget(lineEditFirstName);

        label_3 = new QLabel(editPanel);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        lineEditLastName = new QLineEdit(editPanel);
        lineEditLastName->setObjectName(QString::fromUtf8("lineEditLastName"));
        lineEditLastName->setMaxLength(15);

        verticalLayout_3->addWidget(lineEditLastName);

        verticalSpacer_3 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        buttonChangeName = new QPushButton(editPanel);
        buttonChangeName->setObjectName(QString::fromUtf8("buttonChangeName"));
        buttonChangeName->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_3->addWidget(buttonChangeName);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer_5 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, 0, -1);
        label_4 = new QLabel(editPanel);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        lineEditCurrentPassword = new QLineEdit(editPanel);
        lineEditCurrentPassword->setObjectName(QString::fromUtf8("lineEditCurrentPassword"));
        lineEditCurrentPassword->setMaxLength(15);
        lineEditCurrentPassword->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEditCurrentPassword);

        label_5 = new QLabel(editPanel);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        lineEditNewPassword = new QLineEdit(editPanel);
        lineEditNewPassword->setObjectName(QString::fromUtf8("lineEditNewPassword"));
        lineEditNewPassword->setMaxLength(15);
        lineEditNewPassword->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEditNewPassword);

        verticalSpacer_4 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        buttonChangePassword = new QPushButton(editPanel);
        buttonChangePassword->setObjectName(QString::fromUtf8("buttonChangePassword"));
        buttonChangePassword->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_4->addWidget(buttonChangePassword);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_6 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout_5->addWidget(editPanel);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, 0, -1);
        label = new QLabel(profilePanel);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, 0, -1);
        buttonPicture1 = new QPushButton(profilePanel);
        buttonPicture1->setObjectName(QString::fromUtf8("buttonPicture1"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonPicture1->sizePolicy().hasHeightForWidth());
        buttonPicture1->setSizePolicy(sizePolicy);
        buttonPicture1->setMinimumSize(QSize(75, 75));
        buttonPicture1->setStyleSheet(QString::fromUtf8(""));
        buttonPicture1->setIconSize(QSize(16, 16));
        buttonPicture1->setFlat(false);

        horizontalLayout_6->addWidget(buttonPicture1);

        buttonPicture2 = new QPushButton(profilePanel);
        buttonPicture2->setObjectName(QString::fromUtf8("buttonPicture2"));
        sizePolicy.setHeightForWidth(buttonPicture2->sizePolicy().hasHeightForWidth());
        buttonPicture2->setSizePolicy(sizePolicy);
        buttonPicture2->setMinimumSize(QSize(75, 75));

        horizontalLayout_6->addWidget(buttonPicture2);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        buttonPicture3 = new QPushButton(profilePanel);
        buttonPicture3->setObjectName(QString::fromUtf8("buttonPicture3"));
        sizePolicy.setHeightForWidth(buttonPicture3->sizePolicy().hasHeightForWidth());
        buttonPicture3->setSizePolicy(sizePolicy);
        buttonPicture3->setMinimumSize(QSize(75, 75));

        horizontalLayout_7->addWidget(buttonPicture3);

        buttonPicture4 = new QPushButton(profilePanel);
        buttonPicture4->setObjectName(QString::fromUtf8("buttonPicture4"));
        sizePolicy.setHeightForWidth(buttonPicture4->sizePolicy().hasHeightForWidth());
        buttonPicture4->setSizePolicy(sizePolicy);
        buttonPicture4->setMinimumSize(QSize(75, 75));

        horizontalLayout_7->addWidget(buttonPicture4);


        verticalLayout_4->addLayout(horizontalLayout_7);


        horizontalLayout_5->addLayout(verticalLayout_4);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonConfirm = new QPushButton(profilePanel);
        buttonConfirm->setObjectName(QString::fromUtf8("buttonConfirm"));

        horizontalLayout->addWidget(buttonConfirm);


        verticalLayout_2->addLayout(horizontalLayout);

        profileScreen->setCentralWidget(profilePanel);

        retranslateUi(profileScreen);

        QMetaObject::connectSlotsByName(profileScreen);
    } // setupUi

    void retranslateUi(QMainWindow *profileScreen)
    {
        profileScreen->setWindowTitle(QApplication::translate("profileScreen", "MainWindow", nullptr));
        labelUsername->setText(QApplication::translate("profileScreen", "Welcome!", nullptr));
        label_2->setText(QApplication::translate("profileScreen", "First Name:", nullptr));
        label_3->setText(QApplication::translate("profileScreen", "Last Name:", nullptr));
        buttonChangeName->setText(QApplication::translate("profileScreen", "Change Name", nullptr));
        label_4->setText(QApplication::translate("profileScreen", "Current Password:", nullptr));
        label_5->setText(QApplication::translate("profileScreen", "New Password:", nullptr));
        buttonChangePassword->setText(QApplication::translate("profileScreen", "Change Password", nullptr));
        label->setText(QApplication::translate("profileScreen", "Change profile picture:", nullptr));
        buttonPicture1->setText(QString());
        buttonPicture2->setText(QString());
        buttonPicture3->setText(QString());
        buttonPicture4->setText(QString());
        buttonConfirm->setText(QApplication::translate("profileScreen", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class profileScreen: public Ui_profileScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILESCREEN_H
