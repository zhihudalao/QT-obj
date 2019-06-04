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
        qDebug() << m_strName << " --> " << ++i;
        sleep(1);
    }
}
