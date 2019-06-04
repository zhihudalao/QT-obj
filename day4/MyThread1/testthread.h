#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <QThread>
#include <QString>

class TestThread : public QThread
{
    Q_OBJECT
public:
    TestThread(QString name = "thread");
    void run();

signals:
    void sendMsg(QString msg);

private:
    QString m_strName;

};

#endif // TESTTHREAD_H
