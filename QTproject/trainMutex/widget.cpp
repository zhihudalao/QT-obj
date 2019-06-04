#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(600,700);
    m_pOutTE = new QTextEdit(this);

    tubeAndTrain *thread1 = new tubeAndTrain("一号");
    tubeAndTrain *thread2 = new tubeAndTrain("二号");
    tubeAndTrain *thread3 = new tubeAndTrain("三号");
    tubeAndTrain *thread4 = new tubeAndTrain("四号");
    tubeAndTrain *thread5 = new tubeAndTrain("五号");

    connect(thread1,SIGNAL(sendMsgToMain(QString))
            ,this,SLOT(out(QString)));

    thread1->start();
    thread2->start();
    thread3->start();
    thread4->start();
    thread5->start();
}

Widget::~Widget()
{
}

void Widget::out(QString msg)
{
    m_pOutTE->append(msg);
}
