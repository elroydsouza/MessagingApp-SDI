/********************************************************************************
** Form generated from reading UI file 'chatScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATSCREEN_H
#define UI_CHATSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatScreen
{
public:
    QWidget *chatPanel;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *buttonUserPicture;
    QLabel *labelUsername;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBoxGroupChats;
    QPushButton *buttonGroupChat;
    QComboBox *comboBoxContacts;
    QPushButton *buttonUserChat;
    QHBoxLayout *horizontalLayout;
    QGroupBox *messageLogPanel;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *messageLog;
    QListWidget *listWidgetActivity;
    QWidget *verticalLayout3Panel_2;
    QVBoxLayout *verticalLayout3Panel;
    QLabel *labelAdmin;
    QListWidget *listWidgetAdmin;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lableModerators;
    QPushButton *buttonDemote;
    QListWidget *listWidgetModerators;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelMembers;
    QPushButton *buttonPromote;
    QListWidget *listWidgetMembers;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEditMessageContent;
    QPushButton *buttonSend;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonCreateGroup;
    QPushButton *buttonAddContact;
    QPushButton *buttonProfile;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonRefresh;
    QPushButton *buttonLogout;

    void setupUi(QMainWindow *chatScreen)
    {
        if (chatScreen->objectName().isEmpty())
            chatScreen->setObjectName(QString::fromUtf8("chatScreen"));
        chatScreen->resize(750, 550);
        chatPanel = new QWidget(chatScreen);
        chatPanel->setObjectName(QString::fromUtf8("chatPanel"));
        chatPanel->setStyleSheet(QString::fromUtf8("#chatPanel {background-color: rgb(196, 197, 231)}"));
        verticalLayout = new QVBoxLayout(chatPanel);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        buttonUserPicture = new QPushButton(chatPanel);
        buttonUserPicture->setObjectName(QString::fromUtf8("buttonUserPicture"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonUserPicture->sizePolicy().hasHeightForWidth());
        buttonUserPicture->setSizePolicy(sizePolicy);
        buttonUserPicture->setMinimumSize(QSize(50, 50));
        buttonUserPicture->setMaximumSize(QSize(50, 50));
        buttonUserPicture->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(buttonUserPicture);

        labelUsername = new QLabel(chatPanel);
        labelUsername->setObjectName(QString::fromUtf8("labelUsername"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelUsername->sizePolicy().hasHeightForWidth());
        labelUsername->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(18);
        labelUsername->setFont(font);

        horizontalLayout_4->addWidget(labelUsername);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        comboBoxGroupChats = new QComboBox(chatPanel);
        comboBoxGroupChats->addItem(QString());
        comboBoxGroupChats->setObjectName(QString::fromUtf8("comboBoxGroupChats"));
        sizePolicy.setHeightForWidth(comboBoxGroupChats->sizePolicy().hasHeightForWidth());
        comboBoxGroupChats->setSizePolicy(sizePolicy);
        comboBoxGroupChats->setMinimumSize(QSize(130, 0));

        horizontalLayout_4->addWidget(comboBoxGroupChats);

        buttonGroupChat = new QPushButton(chatPanel);
        buttonGroupChat->setObjectName(QString::fromUtf8("buttonGroupChat"));

        horizontalLayout_4->addWidget(buttonGroupChat);

        comboBoxContacts = new QComboBox(chatPanel);
        comboBoxContacts->addItem(QString());
        comboBoxContacts->setObjectName(QString::fromUtf8("comboBoxContacts"));
        comboBoxContacts->setMinimumSize(QSize(120, 0));

        horizontalLayout_4->addWidget(comboBoxContacts);

        buttonUserChat = new QPushButton(chatPanel);
        buttonUserChat->setObjectName(QString::fromUtf8("buttonUserChat"));

        horizontalLayout_4->addWidget(buttonUserChat);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        messageLogPanel = new QGroupBox(chatPanel);
        messageLogPanel->setObjectName(QString::fromUtf8("messageLogPanel"));
        sizePolicy1.setHeightForWidth(messageLogPanel->sizePolicy().hasHeightForWidth());
        messageLogPanel->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(messageLogPanel);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        messageLog = new QPlainTextEdit(messageLogPanel);
        messageLog->setObjectName(QString::fromUtf8("messageLog"));
        messageLog->setReadOnly(true);

        verticalLayout_2->addWidget(messageLog);

        listWidgetActivity = new QListWidget(messageLogPanel);
        listWidgetActivity->setObjectName(QString::fromUtf8("listWidgetActivity"));
        listWidgetActivity->setMaximumSize(QSize(16777215, 80));

        verticalLayout_2->addWidget(listWidgetActivity);


        horizontalLayout->addWidget(messageLogPanel);

        verticalLayout3Panel_2 = new QWidget(chatPanel);
        verticalLayout3Panel_2->setObjectName(QString::fromUtf8("verticalLayout3Panel_2"));
        verticalLayout3Panel = new QVBoxLayout(verticalLayout3Panel_2);
        verticalLayout3Panel->setObjectName(QString::fromUtf8("verticalLayout3Panel"));
        labelAdmin = new QLabel(verticalLayout3Panel_2);
        labelAdmin->setObjectName(QString::fromUtf8("labelAdmin"));

        verticalLayout3Panel->addWidget(labelAdmin);

        listWidgetAdmin = new QListWidget(verticalLayout3Panel_2);
        listWidgetAdmin->setObjectName(QString::fromUtf8("listWidgetAdmin"));
        sizePolicy.setHeightForWidth(listWidgetAdmin->sizePolicy().hasHeightForWidth());
        listWidgetAdmin->setSizePolicy(sizePolicy);
        listWidgetAdmin->setMaximumSize(QSize(16777215, 30));

        verticalLayout3Panel->addWidget(listWidgetAdmin);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        lableModerators = new QLabel(verticalLayout3Panel_2);
        lableModerators->setObjectName(QString::fromUtf8("lableModerators"));

        horizontalLayout_5->addWidget(lableModerators);

        buttonDemote = new QPushButton(verticalLayout3Panel_2);
        buttonDemote->setObjectName(QString::fromUtf8("buttonDemote"));
        buttonDemote->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(buttonDemote);


        verticalLayout3Panel->addLayout(horizontalLayout_5);

        listWidgetModerators = new QListWidget(verticalLayout3Panel_2);
        listWidgetModerators->setObjectName(QString::fromUtf8("listWidgetModerators"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listWidgetModerators->sizePolicy().hasHeightForWidth());
        listWidgetModerators->setSizePolicy(sizePolicy2);

        verticalLayout3Panel->addWidget(listWidgetModerators);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 0, -1, -1);
        labelMembers = new QLabel(verticalLayout3Panel_2);
        labelMembers->setObjectName(QString::fromUtf8("labelMembers"));

        horizontalLayout_6->addWidget(labelMembers);

        buttonPromote = new QPushButton(verticalLayout3Panel_2);
        buttonPromote->setObjectName(QString::fromUtf8("buttonPromote"));
        buttonPromote->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(buttonPromote);


        verticalLayout3Panel->addLayout(horizontalLayout_6);

        listWidgetMembers = new QListWidget(verticalLayout3Panel_2);
        listWidgetMembers->setObjectName(QString::fromUtf8("listWidgetMembers"));
        sizePolicy2.setHeightForWidth(listWidgetMembers->sizePolicy().hasHeightForWidth());
        listWidgetMembers->setSizePolicy(sizePolicy2);

        verticalLayout3Panel->addWidget(listWidgetMembers);


        horizontalLayout->addWidget(verticalLayout3Panel_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        lineEditMessageContent = new QLineEdit(chatPanel);
        lineEditMessageContent->setObjectName(QString::fromUtf8("lineEditMessageContent"));

        horizontalLayout_3->addWidget(lineEditMessageContent);

        buttonSend = new QPushButton(chatPanel);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));

        horizontalLayout_3->addWidget(buttonSend);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        buttonCreateGroup = new QPushButton(chatPanel);
        buttonCreateGroup->setObjectName(QString::fromUtf8("buttonCreateGroup"));
        buttonCreateGroup->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(buttonCreateGroup);

        buttonAddContact = new QPushButton(chatPanel);
        buttonAddContact->setObjectName(QString::fromUtf8("buttonAddContact"));
        buttonAddContact->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(buttonAddContact);

        buttonProfile = new QPushButton(chatPanel);
        buttonProfile->setObjectName(QString::fromUtf8("buttonProfile"));
        buttonProfile->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(buttonProfile);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonRefresh = new QPushButton(chatPanel);
        buttonRefresh->setObjectName(QString::fromUtf8("buttonRefresh"));

        horizontalLayout_2->addWidget(buttonRefresh);

        buttonLogout = new QPushButton(chatPanel);
        buttonLogout->setObjectName(QString::fromUtf8("buttonLogout"));

        horizontalLayout_2->addWidget(buttonLogout);


        verticalLayout->addLayout(horizontalLayout_2);

        chatScreen->setCentralWidget(chatPanel);

        retranslateUi(chatScreen);

        QMetaObject::connectSlotsByName(chatScreen);
    } // setupUi

    void retranslateUi(QMainWindow *chatScreen)
    {
        chatScreen->setWindowTitle(QApplication::translate("chatScreen", "MainWindow", nullptr));
        buttonUserPicture->setText(QString());
        labelUsername->setText(QApplication::translate("chatScreen", "User", nullptr));
        comboBoxGroupChats->setItemText(0, QApplication::translate("chatScreen", "Select a Group", nullptr));

        buttonGroupChat->setText(QApplication::translate("chatScreen", "Chat", nullptr));
        comboBoxContacts->setItemText(0, QApplication::translate("chatScreen", "Select a User", nullptr));

        comboBoxContacts->setCurrentText(QApplication::translate("chatScreen", "Select a User", nullptr));
        buttonUserChat->setText(QApplication::translate("chatScreen", "Chat", nullptr));
        messageLogPanel->setTitle(QApplication::translate("chatScreen", "Message Log", nullptr));
        labelAdmin->setText(QApplication::translate("chatScreen", "Admin", nullptr));
        lableModerators->setText(QApplication::translate("chatScreen", "Moderators", nullptr));
        buttonDemote->setText(QApplication::translate("chatScreen", "+Demote", nullptr));
        labelMembers->setText(QApplication::translate("chatScreen", "Members", nullptr));
        buttonPromote->setText(QApplication::translate("chatScreen", "+Promote", nullptr));
        buttonSend->setText(QApplication::translate("chatScreen", "Send", nullptr));
        buttonCreateGroup->setText(QApplication::translate("chatScreen", "Create Group", nullptr));
        buttonAddContact->setText(QApplication::translate("chatScreen", "Add Contact", nullptr));
        buttonProfile->setText(QApplication::translate("chatScreen", "Edit Profile", nullptr));
        buttonRefresh->setText(QApplication::translate("chatScreen", "Refresh", nullptr));
        buttonLogout->setText(QApplication::translate("chatScreen", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatScreen: public Ui_chatScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATSCREEN_H
