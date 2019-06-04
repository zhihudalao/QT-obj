#include "item.h"

Item::Item()
{
    setPixmap(QPixmap("E:\\1haitong\\QT obj\\day3\\map\\pic\\11.png"));
    m_bShow = false;

    startTimer(100);
}

void Item::timerEvent(QTimerEvent *event)
{
    if (m_bShow)
    {
        setPixmap(QPixmap("E:\\1haitong\\QT obj\\day3\\map\\pic\\11.png"));
        m_bShow = false;
    }
    else
    {
        setPixmap(QPixmap("E:\\1haitong\\QT obj\\day3\\map\\pic\\22.png"));
        m_bShow = true;
    }
}

