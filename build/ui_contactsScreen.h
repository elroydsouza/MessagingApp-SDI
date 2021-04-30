/********************************************************************************
** Form generated from reading UI file 'contactsScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTSSCREEN_H
#define UI_CONTACTSSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_contactsScreen
{
public:
    QWidget *contactsPanel;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *buttonAddContact;
    QListWidget *listWidgetUsers;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QPushButton *deleteContact;
    QListWidget *listWidgetContacts;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;

    void setupUi(QMainWindow *contactsScreen)
    {
        if (contactsScreen->objectName().isEmpty())
            contactsScreen->setObjectName(QString::fromUtf8("contactsScreen"));
        contactsScreen->resize(250, 500);
        contactsPanel = new QWidget(contactsScreen);
        contactsPanel->setObjectName(QString::fromUtf8("contactsPanel"));
        contactsPanel->setStyleSheet(QString::fromUtf8("#contactsPanel {background-color: rgb(196, 197, 231)}"));
        verticalLayout_2 = new QVBoxLayout(contactsPanel);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        label_2 = new QLabel(contactsPanel);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        buttonAddContact = new QPushButton(contactsPanel);
        buttonAddContact->setObjectName(QString::fromUtf8("buttonAddContact"));
        buttonAddContact->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(buttonAddContact);


        verticalLayout_2->addLayout(horizontalLayout_2);

        listWidgetUsers = new QListWidget(contactsPanel);
        listWidgetUsers->setObjectName(QString::fromUtf8("listWidgetUsers"));

        verticalLayout_2->addWidget(listWidgetUsers);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        label = new QLabel(contactsPanel);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        deleteContact = new QPushButton(contactsPanel);
        deleteContact->setObjectName(QString::fromUtf8("deleteContact"));
        deleteContact->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(deleteContact);


        verticalLayout_2->addLayout(horizontalLayout_3);

        listWidgetContacts = new QListWidget(contactsPanel);
        listWidgetContacts->setObjectName(QString::fromUtf8("listWidgetContacts"));

        verticalLayout_2->addWidget(listWidgetContacts);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        pushButton = new QPushButton(contactsPanel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout);

        contactsScreen->setCentralWidget(contactsPanel);

        retranslateUi(contactsScreen);

        QMetaObject::connectSlotsByName(contactsScreen);
    } // setupUi

    void retranslateUi(QMainWindow *contactsScreen)
    {
        contactsScreen->setWindowTitle(QApplication::translate("contactsScreen", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("contactsScreen", "Users Not Added:", nullptr));
        buttonAddContact->setText(QApplication::translate("contactsScreen", "+ Add", nullptr));
        label->setText(QApplication::translate("contactsScreen", "Contacts:", nullptr));
        deleteContact->setText(QApplication::translate("contactsScreen", "- Delete", nullptr));
        pushButton->setText(QApplication::translate("contactsScreen", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class contactsScreen: public Ui_contactsScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTSSCREEN_H
