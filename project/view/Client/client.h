#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include "loginok.h"

namespace Ui {
class CLient;
}

class CLient : public QWidget
{
    Q_OBJECT

public:
    explicit CLient(QWidget *parent = 0);
    ~CLient();

    struct PDU
    {
        char caName[32];
        char caPwd[32];
        int iMsgType;
        char caResult[64];
    };

public slots:
    void recvMsg();

private slots:
    void on_login_pb_clicked();

    void on_regist_pb_clicked();

private:
    Ui::CLient *ui;

    QTcpSocket *m_pTcpSocket;

    LoginOk *m_pLoginOK;
};

#endif // CLIENT_H
