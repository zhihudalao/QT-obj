/********************************************************************************
** Form generated from reading UI file 'chatroom.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOM_H
#define UI_CHATROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ChatRoom
{
public:
    QTextEdit *textEdit;
    QPushButton *send;
    QPushButton *chatlist_btn;
    QTextBrowser *textBrowser;
    QPushButton *video;
    QPushButton *audio;
    QPushButton *bs;
    QPushButton *gift;
    QListWidget *listWidget;
    QLabel *cur_user;
    QLabel *videosurface;
    QLabel *textscroll;
    QLabel *audioinput;
    QTextBrowser *textBrowser_2;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *ChatRoom)
    {
        if (ChatRoom->objectName().isEmpty())
            ChatRoom->setObjectName(QStringLiteral("ChatRoom"));
        ChatRoom->resize(1000, 600);
        ChatRoom->setMinimumSize(QSize(1000, 600));
        ChatRoom->setMaximumSize(QSize(1000, 600));
        textEdit = new QTextEdit(ChatRoom);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 510, 471, 31));
        send = new QPushButton(ChatRoom);
        send->setObjectName(QStringLiteral("send"));
        send->setGeometry(QRect(430, 550, 81, 31));
        chatlist_btn = new QPushButton(ChatRoom);
        chatlist_btn->setObjectName(QStringLiteral("chatlist_btn"));
        chatlist_btn->setGeometry(QRect(860, 70, 51, 41));
        textBrowser = new QTextBrowser(ChatRoom);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(25, 10, 481, 281));
        video = new QPushButton(ChatRoom);
        video->setObjectName(QStringLiteral("video"));
        video->setGeometry(QRect(520, 30, 71, 41));
        audio = new QPushButton(ChatRoom);
        audio->setObjectName(QStringLiteral("audio"));
        audio->setGeometry(QRect(520, 130, 71, 41));
        bs = new QPushButton(ChatRoom);
        bs->setObjectName(QStringLiteral("bs"));
        bs->setGeometry(QRect(520, 210, 71, 41));
        gift = new QPushButton(ChatRoom);
        gift->setObjectName(QStringLiteral("gift"));
        gift->setGeometry(QRect(520, 290, 71, 41));
        listWidget = new QListWidget(ChatRoom);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(710, 160, 201, 411));
        cur_user = new QLabel(ChatRoom);
        cur_user->setObjectName(QStringLiteral("cur_user"));
        cur_user->setGeometry(QRect(540, 20, 151, 21));
        videosurface = new QLabel(ChatRoom);
        videosurface->setObjectName(QStringLiteral("videosurface"));
        videosurface->setGeometry(QRect(20, 10, 481, 281));
        textscroll = new QLabel(ChatRoom);
        textscroll->setObjectName(QStringLiteral("textscroll"));
        textscroll->setGeometry(QRect(30, 10, 481, 281));
        audioinput = new QLabel(ChatRoom);
        audioinput->setObjectName(QStringLiteral("audioinput"));
        audioinput->setGeometry(QRect(540, 90, 41, 41));
        textBrowser_2 = new QTextBrowser(ChatRoom);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(30, 360, 471, 131));
        label_2 = new QLabel(ChatRoom);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 330, 72, 21));
        label = new QLabel(ChatRoom);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(710, 130, 72, 15));

        retranslateUi(ChatRoom);

        QMetaObject::connectSlotsByName(ChatRoom);
    } // setupUi

    void retranslateUi(QDialog *ChatRoom)
    {
        ChatRoom->setWindowTitle(QApplication::translate("ChatRoom", "Dialog", Q_NULLPTR));
        send->setText(QApplication::translate("ChatRoom", "\345\217\221\351\200\201", Q_NULLPTR));
        chatlist_btn->setText(QApplication::translate("ChatRoom", "\345\210\267\346\226\260", Q_NULLPTR));
        video->setText(QApplication::translate("ChatRoom", "\350\247\206\351\242\221", Q_NULLPTR));
        audio->setText(QApplication::translate("ChatRoom", "\350\257\255\351\237\263", Q_NULLPTR));
        bs->setText(QApplication::translate("ChatRoom", "\345\274\271\345\271\225", Q_NULLPTR));
        gift->setText(QApplication::translate("ChatRoom", "\351\200\201\347\244\274", Q_NULLPTR));
        cur_user->setText(QString());
        videosurface->setText(QString());
        textscroll->setText(QApplication::translate("ChatRoom", "<html><head/><body><p align=\"center\"><br/></p></body></html>", Q_NULLPTR));
        audioinput->setText(QApplication::translate("ChatRoom", "\346\255\243\345\234\250", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChatRoom", "\350\201\212\345\244\251\350\256\260\345\275\225\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("ChatRoom", "\347\224\250\346\210\267\345\210\227\350\241\250\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatRoom: public Ui_ChatRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOM_H
