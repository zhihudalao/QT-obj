/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QListWidget *chatroom;
    QPushButton *destory;
    QPushButton *exit_btn;
    QPushButton *roomlist_btn;
    QListWidget *user;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(500, 540);
        Dialog->setMinimumSize(QSize(500, 540));
        Dialog->setMaximumSize(QSize(500, 540));
        chatroom = new QListWidget(Dialog);
        chatroom->setObjectName(QStringLiteral("chatroom"));
        chatroom->setGeometry(QRect(10, 130, 281, 351));
        destory = new QPushButton(Dialog);
        destory->setObjectName(QStringLiteral("destory"));
        destory->setGeometry(QRect(40, 490, 71, 41));
        exit_btn = new QPushButton(Dialog);
        exit_btn->setObjectName(QStringLiteral("exit_btn"));
        exit_btn->setGeometry(QRect(410, 490, 71, 41));
        roomlist_btn = new QPushButton(Dialog);
        roomlist_btn->setObjectName(QStringLiteral("roomlist_btn"));
        roomlist_btn->setGeometry(QRect(190, 90, 51, 41));
        user = new QListWidget(Dialog);
        user->setObjectName(QStringLiteral("user"));
        user->setGeometry(QRect(10, 10, 281, 81));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 100, 111, 16));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        destory->setText(QApplication::translate("Dialog", "\346\263\250\351\224\200", Q_NULLPTR));
        exit_btn->setText(QApplication::translate("Dialog", "\351\200\200\345\207\272", Q_NULLPTR));
        roomlist_btn->setText(QApplication::translate("Dialog", "\345\210\267\346\226\260", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "\350\201\212\345\244\251\345\256\244\345\210\227\350\241\250\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
