#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class UdpServer;
}

class UdpServer : public QWidget
{
    Q_OBJECT

public:
    explicit UdpServer(QWidget *parent = 0);
    ~UdpServer();

private slots:
    void on_start_pb_clicked();
    void recvMsg();

private:
    Ui::UdpServer *ui;
    QUdpSocket *m_pUdpSocket;

};

#endif // UDPSERVER_H
