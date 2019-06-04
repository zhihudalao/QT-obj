/********************************************************************************
** Form generated from reading UI file 'udpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPCLIENT_H
#define UI_UDPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UdpClient
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *ip_lab;
    QLineEdit *ip_le;
    QLabel *port_lab;
    QLineEdit *port_le;
    QTextEdit *recvMsg_te;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *input_le;
    QPushButton *sendMsg_pb;

    void setupUi(QWidget *UdpClient)
    {
        if (UdpClient->objectName().isEmpty())
            UdpClient->setObjectName(QStringLiteral("UdpClient"));
        UdpClient->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(UdpClient);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ip_lab = new QLabel(UdpClient);
        ip_lab->setObjectName(QStringLiteral("ip_lab"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(20);
        ip_lab->setFont(font);

        horizontalLayout->addWidget(ip_lab);

        ip_le = new QLineEdit(UdpClient);
        ip_le->setObjectName(QStringLiteral("ip_le"));
        ip_le->setFont(font);

        horizontalLayout->addWidget(ip_le);

        port_lab = new QLabel(UdpClient);
        port_lab->setObjectName(QStringLiteral("port_lab"));
        port_lab->setFont(font);

        horizontalLayout->addWidget(port_lab);

        port_le = new QLineEdit(UdpClient);
        port_le->setObjectName(QStringLiteral("port_le"));
        port_le->setFont(font);

        horizontalLayout->addWidget(port_le);


        verticalLayout->addLayout(horizontalLayout);

        recvMsg_te = new QTextEdit(UdpClient);
        recvMsg_te->setObjectName(QStringLiteral("recvMsg_te"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(16);
        recvMsg_te->setFont(font1);

        verticalLayout->addWidget(recvMsg_te);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        input_le = new QLineEdit(UdpClient);
        input_le->setObjectName(QStringLiteral("input_le"));
        input_le->setFont(font);

        horizontalLayout_2->addWidget(input_le);

        sendMsg_pb = new QPushButton(UdpClient);
        sendMsg_pb->setObjectName(QStringLiteral("sendMsg_pb"));
        sendMsg_pb->setFont(font);

        horizontalLayout_2->addWidget(sendMsg_pb);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(UdpClient);

        QMetaObject::connectSlotsByName(UdpClient);
    } // setupUi

    void retranslateUi(QWidget *UdpClient)
    {
        UdpClient->setWindowTitle(QApplication::translate("UdpClient", "UdpClient", Q_NULLPTR));
        ip_lab->setText(QApplication::translate("UdpClient", "IP:", Q_NULLPTR));
        port_lab->setText(QApplication::translate("UdpClient", "PORT:", Q_NULLPTR));
        sendMsg_pb->setText(QApplication::translate("UdpClient", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UdpClient: public Ui_UdpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPCLIENT_H
