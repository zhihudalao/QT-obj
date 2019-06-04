#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(700, 600);

    m_pScene = new QGraphicsScene(0, 0, width(), height());
    MyItem *item = new MyItem;
    m_pScene->addItem(item);

    m_pView = new QGraphicsView(this);
    m_pView->setScene(m_pScene);
}

Widget::~Widget()
{

}


















