#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

namespace Ui {
class TcpServer;
}

class TcpServer : public QWidget
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = 0);
    ~TcpServer();

private slots:
    void on_listen_pb_clicked();
    void acceptClient();
    void recvMsg();

private:
    Ui::TcpServer *ui;

    QTcpServer *m_pTcpServer;
    QList<QTcpSocket *> m_tcpSocket;
};

#endif // TCPSERVER_H
