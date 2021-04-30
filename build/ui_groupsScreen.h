/********************************************************************************
** Form generated from reading UI file 'groupsScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPSSCREEN_H
#define UI_GROUPSSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_groupsScreen
{
public:
    QWidget *groupsPanel;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelSetGroupName;
    QLineEdit *lineEditGroupName;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBoxUsers;
    QPushButton *buttonAddMember;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonCreateGroup;
    QPushButton *buttonExit;

    void setupUi(QMainWindow *groupsScreen)
    {
        if (groupsScreen->objectName().isEmpty())
            groupsScreen->setObjectName(QString::fromUtf8("groupsScreen"));
        groupsScreen->resize(250, 500);
        groupsPanel = new QWidget(groupsScreen);
        groupsPanel->setObjectName(QString::fromUtf8("groupsPanel"));
        groupsPanel->setStyleSheet(QString::fromUtf8("#groupsPanel {background-color: rgb(196, 197, 231)}"));
        verticalLayout_4 = new QVBoxLayout(groupsPanel);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelSetGroupName = new QLabel(groupsPanel);
        labelSetGroupName->setObjectName(QString::fromUtf8("labelSetGroupName"));

        verticalLayout_4->addWidget(labelSetGroupName);

        lineEditGroupName = new QLineEdit(groupsPanel);
        lineEditGroupName->setObjectName(QString::fromUtf8("lineEditGroupName"));
        lineEditGroupName->setMaxLength(30);

        verticalLayout_4->addWidget(lineEditGroupName);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBoxUsers = new QComboBox(groupsPanel);
        comboBoxUsers->setObjectName(QString::fromUtf8("comboBoxUsers"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxUsers->sizePolicy().hasHeightForWidth());
        comboBoxUsers->setSizePolicy(sizePolicy);
        comboBoxUsers->setMinimumSize(QSize(144, 0));

        horizontalLayout->addWidget(comboBoxUsers);

        buttonAddMember = new QPushButton(groupsPanel);
        buttonAddMember->setObjectName(QString::fromUtf8("buttonAddMember"));

        horizontalLayout->addWidget(buttonAddMember);


        verticalLayout_4->addLayout(horizontalLayout);

        listWidget = new QListWidget(groupsPanel);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_4->addWidget(listWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        buttonCreateGroup = new QPushButton(groupsPanel);
        buttonCreateGroup->setObjectName(QString::fromUtf8("buttonCreateGroup"));

        horizontalLayout_2->addWidget(buttonCreateGroup);

        buttonExit = new QPushButton(groupsPanel);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));
        buttonExit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(buttonExit);


        verticalLayout_4->addLayout(horizontalLayout_2);

        groupsScreen->setCentralWidget(groupsPanel);

        retranslateUi(groupsScreen);

        QMetaObject::connectSlotsByName(groupsScreen);
    } // setupUi

    void retranslateUi(QMainWindow *groupsScreen)
    {
        groupsScreen->setWindowTitle(QApplication::translate("groupsScreen", "MainWindow", nullptr));
        labelSetGroupName->setText(QApplication::translate("groupsScreen", "Set Group Chat Name:", nullptr));
        buttonAddMember->setText(QApplication::translate("groupsScreen", "+Mem", nullptr));
        buttonCreateGroup->setText(QApplication::translate("groupsScreen", "Create Group", nullptr));
        buttonExit->setText(QApplication::translate("groupsScreen", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupsScreen: public Ui_groupsScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPSSCREEN_H
