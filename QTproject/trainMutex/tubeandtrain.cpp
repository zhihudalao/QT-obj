#include "tubeandtrain.h"

tube *aTube = new tube;

tubeAndTrain::tubeAndTrain(QString name)
{
    m_name = name;
    connect(aTube,SIGNAL(sendMsgToTrain(QString))
            ,this,SLOT(revMsgFromTube(QString)));
}

tubeAndTrain::tubeAndTrain()
{
    m_name = "希望号";
}

void tubeAndTrain::run()
{
    aTube->cross(m_name);
}

void tubeAndTrain::revMsgFromTube(QString msg)
{
    sendMsgToMain(msg);
}

