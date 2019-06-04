#include "udpserver.h"
#include "ui_udpserver.h"

UdpServer::UdpServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UdpServer)
{
    ui->setupUi(this);
    m_pUdpSocket = new QUdpSocket(this);
    connect(m_pUdpSocket, SIGNAL(readyRead())
            , this, SLOT(recvMsg()));
}

UdpServer::~UdpServer()
{
    delete ui;
}

void UdpServer::on_start_pb_clicked()
{
    QString strIP = ui->ip_le->text();
    quint16 port = ui->port_le->text().toUShort();
    if (!strIP.isEmpty() && port > 0)
    {
        m_pUdpSocket->bind(QHostAddress(strIP), port);
    }
}

void UdpServer::recvMsg()
{
    qint64 size = m_pUdpSocket->pendingDatagramSize();
    QByteArray data;
    data.resize(size);
    data.clear();

    QHostAddress clientIP;
    quint16 port;
    m_pUdpSocket->readDatagram(data.data(), size, &clientIP, &port);
    ui->recvMsg_te->append(QString("ip:%1,port:%2 --> %3").arg(clientIP.toString()).arg(port).arg(data.data()));

    QString respond = "^)_(^";
    m_pUdpSocket->writeDatagram(QByteArray().append(respond), clientIP, port);
}
