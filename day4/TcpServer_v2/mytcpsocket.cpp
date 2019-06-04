#include "mytcpsocket.h"
#include <QDebug>

MyTcpSocket::MyTcpSocket()
{
    connect(this, SIGNAL(readyRead())
            , this, SLOT(recvMsg()));
}

void MyTcpSocket::recvMsg()
{
    qint64 size = bytesAvailable();
    QByteArray data;
    data.resize(size);

    read(data.data(), data.size());

    qDebug() << "recv msg --> " << data.data();
}
