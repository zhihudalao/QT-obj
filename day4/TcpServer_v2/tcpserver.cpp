#include "tcpserver.h"
#include "ui_tcpserver.h"

TcpServer::TcpServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    m_pTcpServer = new MyTcpServer;
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



