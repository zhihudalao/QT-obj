#ifndef TUBEANDTRAIN_H
#define TUBEANDTRAIN_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QMutex>
#include <unistd.h>

class tube : public QObject
{
    Q_OBJECT
public:
    tube(){}
    void cross(QString &train)
    {
        mutex.lock();
        QString temp1 = train;
        QString temp2 = train;
        temp1.append("进入隧道~~~");
        temp2.append("驶出隧道~~~");
        emit sendMsgToTrain(temp1);
        sleep(2);
        emit sendMsgToTrain(temp2);
        mutex.unlock();
    }
signals:
    void sendMsgToTrain(QString);
private:
    QMutex mutex;
};

class tubeAndTrain : public QThread
{
    Q_OBJECT
public:
    tubeAndTrain(QString name);
    tubeAndTrain();
    void run();
signals:
    void sendMsgToMain(QString msg);
public slots:
    void revMsgFromTube(QString msg);
private:
    QString m_name;
};

#endif // TUBEANDTRAIN_H
