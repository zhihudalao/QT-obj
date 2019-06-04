#include "client.h"
#include "ui_client.h"
#include <QHostAddress>
#include <QMessageBox>

CLient::CLient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CLient)
{

    ui->setupUi(this);

    m_pLoginOK = new LoginOk;
    m_pTcpSocket = new QTcpSocket(this);
    connect(m_pTcpSocket, SIGNAL(readyRead())
            , this, SLOT(recvMsg()));
    m_pTcpSocket->connectToHost(QHostAddress("127.0.0.1"), 8080);
}

CLient::~CLient()
{
    delete ui;
}

void CLient::recvMsg()
{
    PDU pdu;
    m_pTcpSocket->read((char*)&pdu, sizeof(PDU));
    if (2 == pdu.iMsgType)
    {
        QMessageBox::information(this, "Result", pdu.caResult);
    }
    else if(4 == pdu.iMsgType)
    {
        if (0 == strcmp(pdu.caResult, "ok"))
        {
            m_pLoginOK->show();
            this->hide();
        }
        else if (0 == strcmp(pdu.caResult, "failed"))
        {
            QMessageBox::information(this, "账号或者密码错误", pdu.caResult);
        }
    }
}

void CLient::on_login_pb_clicked()
{
    QString name = ui->name_le->text();
    QString pwd = ui->pwd_le->text();
    if (!name.isEmpty() && !pwd.isEmpty())
    {
        PDU pdu;
        strcpy(pdu.caName, name.toStdString().c_str());
        strcpy(pdu.caPwd, pwd.toStdString().c_str());
        pdu.iMsgType = 3;  //3表示登录
         m_pTcpSocket->write((char*)&pdu, sizeof(PDU));
    }
}

void CLient::on_regist_pb_clicked()
{
    QString name = ui->name_le->text();
    QString pwd = ui->pwd_le->text();
    if (!name.isEmpty() && !pwd.isEmpty())
    {
        PDU pdu;
        strcpy(pdu.caName, name.toStdString().c_str());
        strcpy(pdu.caPwd, pwd.toStdString().c_str());
        pdu.iMsgType = 1;  //1表示注册
        m_pTcpSocket->write((char*)&pdu, sizeof(PDU));
    }
}







