#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>
#include "mytcpserver.h"


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

private:
    Ui::TcpServer *ui;

    MyTcpServer *m_pTcpServer;
};

#endif // TCPSERVER_H
