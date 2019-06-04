#include "server.h"
#include <QSqlQuery>
#include <QDebug>

Server::Server(QWidget *parent)
    : QWidget(parent)
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("localhost");
    m_db.setDatabaseName("userinfo");
    m_db.setUserName("root");
    m_db.setPassword("root");
    bool ok = m_db.open();
    if (!ok)
    {
        qDebug() << "sssssssssss";
    }

    m_pTcpServer = new QTcpServer(this);
    m_pTcpServer->listen(QHostAddress("127.0.0.1"), 8080);
    connect(m_pTcpServer, SIGNAL(newConnection())
            , this, SLOT(recvNewConnection()));
}

Server::~Server()
{
}

void Server::recvNewConnection()
{
    QTcpSocket *ts = m_pTcpServer->nextPendingConnection();
    QTcpSocket *tmp = new QTcpSocket;
    tmp->setSocketDescriptor(ts->socketDescriptor());
    connect(tmp, SIGNAL(readyRead())
            , this, SLOT(recvMsg()));
    m_list.push_back(tmp);
}

void Server::recvMsg()
{
    QList<QTcpSocket *>::iterator iter = m_list.begin();
    for (; iter != m_list.end(); iter++)
    {
        if ((*iter)->bytesAvailable()>0)
        {
            PDU pdu;
            (*iter)->read((char*)&pdu, sizeof(PDU));
            if (1 == pdu.iMsgType)
            {
                QString str = QString("select * from user where usrName = '%1'").arg(pdu.caName);
                qDebug() << str;
                QSqlQuery query(str);
                query.exec();
                PDU respdu;
                respdu.iMsgType = 2;//注册回复
                if (!query.next())
                {
                    qDebug() << "no such people";
                    str = QString("insert user(usrName, usrPwd, isOnline) value('%1','%2', 0)").arg(pdu.caName).arg(pdu.caPwd);
                    query.exec(str);

                    strcpy(respdu.caResult, "注册成功");
                }
                else
                {
                    qDebug() << "has people";

                    strcpy(respdu.caResult, "注册失败，用户名已存在");
                }
                (*iter)->write((char*)&respdu, sizeof(PDU));
            }
            else if (3 == pdu.iMsgType)
            {
                QString str = QString("select * from user where usrName = '%1' and usrPwd = '%2'").arg(pdu.caName).arg(pdu.caPwd);
                qDebug() << str;
                QSqlQuery query(str);
                query.exec();
                PDU respdu;
                respdu.iMsgType = 4; //登录回复
                if (query.next())
                {
                    strcpy(respdu.caResult, "ok");
                }
                else
                {
                    strcpy(respdu.caResult, "failed");
                }
                (*iter)->write((char*)&respdu, sizeof(PDU));
            }
        }
    }
}
