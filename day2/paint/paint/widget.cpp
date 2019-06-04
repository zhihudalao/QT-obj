#include "widget.h"
#include <QTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(700, 600);
    m_pTimer = new QTimer;
    m_pTimer->start(1000);
    connect(m_pTimer, SIGNAL(timeout())
            , this, SLOT(update()));

}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPen pen;
//    pen.setStyle(Qt::DotLine);
//    pen.setJoinStyle(Qt::RoundJoin);
    pen.setWidth(5);
    pen.setColor(Qt::blue);

    QPainter painter(this);
    painter.setPen(pen);

//    painter.drawLine(50, 50,  200, 300);
//    painter.drawRect(100, 100, 300, 200);
//    painter.drawEllipse(0, 0, 300, 200);
//    painter.drawEllipse(QPoint(0, 0), 150, 100);
//    painter.drawPixmap(100, 100, QPixmap("C:\\Users\\wtp\\Pictures\\t3.jpg"));

    int r = width();
    if (r > height())
    {
        r = height();
    }

    painter.drawEllipse(QPoint(width()/2, height()/2), r/2, r/2);

    painter.translate(QPoint(width()/2, height()/2));

    for (int i = 0; i < 12; i++)
    {
        painter.drawLine(0, -r/2, 0, -r/2+r/9);
        painter.rotate(30);
    }

    for (int i = 0; i < 60; i++)
    {
        if (0 != i%5)
        {
            painter.drawLine(0, -r/2, 0, -r/2+r/18);
        }
        painter.rotate(6);
    }

    QTime time = QTime::currentTime();
    int hour = time.hour();
    int minute = time.minute();
    int second = time.second();

//    pen.setColor(Qt::red);
    float span = hour*30+minute*(30.0/60)+second*(30.0/3600);
    painter.rotate(span);
    painter.drawLine(0, 0, 0, -r/8);
    painter.rotate(-span);

//    pen.setColor(Qt::yellow);
    span = minute*6+second*(6.0/60);
    painter.rotate(span);
    painter.drawLine(0, 0, 0, -r/5);
    painter.rotate(-span);

    span = second*6;
    painter.rotate(span);
    painter.drawLine(0, 0, 0, -r/3);
    painter.rotate(-span);

    QString strTime = time.toString();
    painter.drawText(0, 0, strTime);
}





