#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QMessageBox>
#include <QHostAddress>

TcpClient::TcpClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    m_pTcpSocket = new QTcpSocket(this);
    connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError))
            , this, SLOT(handleError(QAbstractSocket::SocketError)));
    connect(m_pTcpSocket, SIGNAL(readyRead())
            , this, SLOT(recvMsg()));
}

TcpClient::~TcpClient()
{
    delete ui;
}

void TcpClient::on_connect_db_clicked()
{
    QString strIP = ui->ip_le->text();
    quint16 port = ui->port_le->text().toUShort();
    if (!strIP.isEmpty() && port > 0)
    {
        m_pTcpSocket->connectToHost(QHostAddress(strIP), port);
    }
}

void TcpClient::on_sendMsg_pb_clicked()
{
    QString msg = ui->input_le->text();
    if (!msg.isEmpty())
    {
        m_pTcpSocket->write(msg.toStdString().c_str(), msg.size());
        ui->recvMsg_te->append(QString("send:%1").arg(msg));
        ui->input_le->clear();
    }
}

void TcpClient::handleError(QAbstractSocket::SocketError socketError)
{
    QMessageBox::critical(this, "-_- !", QString("连接服务器失败:%1").arg(m_pTcpSocket->errorString()));
}

void TcpClient::recvMsg()
{
    qint64 size = m_pTcpSocket->bytesAvailable();
    QByteArray data;
    data.resize(size);
    data.clear();

    m_pTcpSocket->read(data.data(), size);
    ui->recvMsg_te->append(QString("recv:%1").arg(data.data()));
}

