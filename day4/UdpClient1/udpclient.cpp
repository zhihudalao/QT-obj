#include "udpclient.h"
#include "ui_udpclient.h"

UdpClient::UdpClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UdpClient)
{
    ui->setupUi(this);
    m_pUdpSocket = new QUdpSocket(this);
    connect(m_pUdpSocket, SIGNAL(readyRead())
            , this, SLOT(recvMsg()));
}

UdpClient::~UdpClient()
{
    delete ui;
}

void UdpClient::on_sendMsg_pb_clicked()
{
    QString strIP = ui->ip_le->text();
    quint16 port = ui->port_le->text().toUShort();
    if (!strIP.isEmpty() && port > 0)
    {
        QString msg = ui->input_le->text();
        if (!msg.isEmpty())
        {
            QByteArray data(msg.toStdString().c_str(), msg.size());
            m_pUdpSocket->writeDatagram(data, QHostAddress(strIP), port);
            ui->recvMsg_te->append(QString("send:%1").arg(msg));
            ui->input_le->clear();
        }
    }
}

void UdpClient::recvMsg()
{
    qint64 size = m_pUdpSocket->pendingDatagramSize();
    QByteArray data;
    data.resize(size);
    data.clear();

    m_pUdpSocket->readDatagram(data.data(), size);
    ui->recvMsg_te->append(QString("recv:%1").arg(data.data()));
}





