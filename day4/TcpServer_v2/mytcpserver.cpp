#include "mytcpserver.h"

MyTcpServer::MyTcpServer()
{
}

void MyTcpServer::incomingConnection(qintptr socketDescriptor)
{
    MyTcpSocket *tcpSocket = new MyTcpSocket;
    tcpSocket->setSocketDescriptor(socketDescriptor);
    m_tcpSocket.push_back(tcpSocket);
}
