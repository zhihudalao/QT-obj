#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(700, 600);
    m_pMapLab = new QLabel(this);
    m_pMapLab->setPixmap(QPixmap("C:\\Users\\wtp\\Pictures\\t3.jpg"));
    m_pMapLab->move(100, 100);
}

Widget::~Widget()
{

}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_ok)
    {
        m_pMapLab->move(event->x()-m_xlen, event->y()-m_ylen);
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    QRect rect = m_pMapLab->rect();
    if (rect.contains(event->x()-m_pMapLab->x()
                      , event->y()-m_pMapLab->y()))
    {
        m_xlen = event->x()-m_pMapLab->x();
        m_ylen = event->y()-m_pMapLab->y();
        m_ok = true;
    }
    else
    {
        m_ok = false;
    }
}






