#include "tcpserver.h"
#include "ui_tcpserver.h"

TcpServer::TcpServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    m_pTcpServer = new QTcpServer(this);
    connect(m_pTcpServer, SIGNAL(newConnection())
            , this, SLOT(acceptClient()));
}

TcpServer::~TcpServer()
{
    delete ui;
}

void TcpServer::on_listen_pb_clicked()
{
    QString strIP = ui->ip_le->text();
    quint16 port = ui->port_le->text().toUShort();
    if (!strIP.isEmpty() && port > 0)
    {
        m_pTcpServer->listen(QHostAddress(strIP), port);
    }
}

void TcpServer::acceptClient()
{
//    m_pTcpServer->hasPendingConnections();
    QTcpSocket *tcpSocket = m_pTcpServer->nextPendingConnection();
    QTcpSocket *tmp = new QTcpSocket;
    connect(tmp, SIGNAL(readyRead())
            , this, SLOT(recvMsg()));
    tmp->setSocketDescriptor(tcpSocket->socketDescriptor());
    m_tcpSocket.push_back(tmp);
}

void TcpServer::recvMsg()
{
    QList<QTcpSocket *>::iterator iter = m_tcpSocket.begin();
    qint64 size = 0;
    for (; iter != m_tcpSocket.end(); iter++)
    {
        size = (*iter)->bytesAvailable();
        if (size > 0)
        {
            QByteArray data;
            data.resize(size);
            data.clear();

            (*iter)->read(data.data(), size);
            ui->recvMsg_te->append(data.data());

            QString msg = "886";
            (*iter)->write(msg.toStdString().c_str(), msg.size());
        }
    }
}




