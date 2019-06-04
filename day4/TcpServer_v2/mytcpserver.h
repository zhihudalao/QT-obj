#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
#include "mytcpsocket.h"
#include <QList>

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    MyTcpServer();

    void incomingConnection(qintptr socketDescriptor);
private:
    QList<MyTcpSocket *> m_tcpSocket;
};

#endif // MYTCPSERVER_H
