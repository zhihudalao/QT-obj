#include "mythread.h"
#include "ui_mythread.h"

MyThread::MyThread(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyThread)
{
    ui->setupUi(this);
    m_pFirstThread = new TestThread("$_$");
    m_pSecondThread = new TestThread("0_0");

    connect(m_pFirstThread, SIGNAL(sendMsg(QString))
            , this, SLOT(recvMsg(QString)));
    connect(m_pSecondThread, SIGNAL(sendMsg(QString))
            , this, SLOT(recvMsg(QString)));
}

MyThread::~MyThread()
{
    delete ui;
}

void MyThread::on_first_clicked()
{
    m_pFirstThread->start();
}

void MyThread::on_second_clicked()
{
    m_pSecondThread->start();
}

void MyThread::recvMsg(QString msg)
{
    if (!msg.isEmpty())
    {
        ui->msg->append(msg);
    }
}
