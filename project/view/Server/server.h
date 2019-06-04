#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QSqlDatabase>
#include <QTcpServer>
#include <QList>
#include <QTcpSocket>

class Server : public QWidget
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);
    ~Server();

    struct PDU
    {
        char caName[32];
        char caPwd[32];
        int iMsgType;
        char caResult[64];
    };

public slots:
    void recvNewConnection();
    void recvMsg();

private:
    QSqlDatabase m_db;
    QTcpServer *m_pTcpServer;
    QList<QTcpSocket *> m_list;
};

#endif // SERVER_H
