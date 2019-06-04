#include "testthread.h"
#include <QDebug>

TestThread::TestThread(QString name)
{
    m_strName = name;
}

void TestThread::run()
{
    int i = 0;
    while (true)
    {
        emit sendMsg(QString("%1 --> %2").arg(m_strName).arg(++i));
        sleep(1);
    }
}
