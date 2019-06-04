#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(700, 600);

    m_pScene = new QGraphicsScene(0, 0, width(), height());
    item = new Item;
    item->setFlag(QGraphicsItem::ItemIsMovable);
    m_pScene->addItem(item);

    m_pView = new QGraphicsView(this);
    m_pView->setScene(m_pScene);
}

Widget::~Widget()
{

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    //返回按下的键盘按键
    int ret = event->key();
    int x = item->x();
    int y = item->y();
    if (Qt::Key_A == ret)
    {
        x -= 20;
        item->setPos(x, y);
    }
    else if (Qt::Key_D == ret)
    {
        x += 20;
        item->setPos(x, y);
    }
    else if (Qt::Key_W == ret)
    {
        y -= 20;
        item->setPos(x, y);
    }
    else if (Qt::Key_S == ret)
    {
        y += 20;
        item->setPos(x, y);
    }
    else if (Qt::Key_Space == ret)
    {
        qDebug() << "ssssssssssssssss";
        Bullet *bullet = new Bullet;
        bullet->setPos(item->x()+item->boundingRect().width()/2-bullet->boundingRect().width()/2
                       , item->y()-bullet->boundingRect().height()-5);
        m_pScene->addItem(bullet);
    }


}


















