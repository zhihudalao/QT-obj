#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QWidget>
#include <QUdpSocket>
#include <QByteArray>

namespace Ui {
class UdpClient;
}

class UdpClient : public QWidget
{
    Q_OBJECT

public:
    explicit UdpClient(QWidget *parent = 0);
    ~UdpClient();

private slots:
    void on_sendMsg_pb_clicked();
    void recvMsg();

private:
    Ui::UdpClient *ui;
    QUdpSocket *m_pUdpSocket;
};

#endif // UDPCLIENT_H
