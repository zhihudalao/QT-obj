#include "myitem.h"

MyItem::MyItem()
{
    setPixmap(QPixmap("C:\\Users\\wtp\\Pictures\\hero1.png"));
//    m_pFirst = new QPixmap("C:\\Users\\wtp\\Pictures\\t1.jpg");
//    m_pSecond = new QPixmap("C:\\Users\\wtp\\Pictures\\t2.jpg");
    m_bShow = false;
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}
