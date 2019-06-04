#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(700, 600);
    m_pMousePosLab = new QLabel;
    QHBoxLayout *pHBL = new QHBoxLayout(this);
    pHBL->addWidget(m_pMousePosLab);

    setMouseTracking(true);
    m_pMousePosLab->setMouseTracking(true);
}

Widget::~Widget()
{
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QString str = QString("鼠标坐标：(%1, %2)").arg(event->pos().x()).arg(event->pos().y());
    m_pMousePosLab->setText(str);
}
