#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QWidget>
#include "testthread.h"

namespace Ui {
class MyThread;
}

class MyThread : public QWidget
{
    Q_OBJECT

public:
    explicit MyThread(QWidget *parent = 0);
    ~MyThread();

private slots:
    void on_first_clicked();
    void on_second_clicked();
    void recvMsg(QString msg);

private:
    Ui::MyThread *ui;
    TestThread *m_pFirstThread;
    TestThread *m_pSecondThread;
};

#endif // MYTHREAD_H
