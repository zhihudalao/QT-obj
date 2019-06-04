#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class TcpClient;
}

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = 0);
    ~TcpClient();

private slots:
    void on_connect_db_clicked();

    void on_sendMsg_pb_clicked();

    void handleError(QAbstractSocket::SocketError socketError);

    void recvMsg();

private:
    Ui::TcpClient *ui;
    QTcpSocket *m_pTcpSocket;
};

#endif // TCPCLIENT_H
