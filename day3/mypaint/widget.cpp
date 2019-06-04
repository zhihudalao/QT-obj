#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(700, 600);
    m_pPixmap = new QPixmap(size());
    m_pPixmap->fill(Qt::white);
}

Widget::~Widget()
{
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    m_start = event->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QPen pen;
    pen.setWidth(10);
    pen.setColor(Qt::yellow);

    QPainter painter;
    painter.begin(m_pPixmap);
    painter.setPen(pen);
    painter.drawLine(m_start, event->pos());
    painter.end();
    m_start = event->pos();

    update();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, *m_pPixmap);
}
