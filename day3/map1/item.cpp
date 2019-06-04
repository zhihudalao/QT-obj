#include "item.h"

Item::Item()
{
    setPixmap(QPixmap("C:\\Users\\wtp\\Pictures\\hero1.png"));
    m_bShow = false;

    startTimer(100);
}

void Item::timerEvent(QTimerEvent *event)
{
    if (m_bShow)
    {
        setPixmap(QPixmap("C:\\Users\\wtp\\Pictures\\hero1.png"));
        m_bShow = false;
    }
    else
    {
        setPixmap(QPixmap("C:\\Users\\wtp\\Pictures\\hero2.png"));
        m_bShow = true;
    }
}

