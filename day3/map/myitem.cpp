#include "myitem.h"

MyItem::MyItem()
{
    setPixmap(QPixmap("E:\\1haitong\\QT obj\\day3\\map\\pic\\11.png"));
//    m_pFirst = new QPixmap("C:\\Users\\wtp\\Pictures\\t1.jpg");
//    m_pSecond = new QPixmap("C:\\Users\\wtp\\Pictures\\t2.jpg");
    m_bShow = false;
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
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
