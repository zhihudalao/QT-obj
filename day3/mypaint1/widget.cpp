#include "widget.h"
#include <QDebug>
#include <QMessageBox>
//窗口
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
    pen.setColor(Qt::blue);

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

void Widget::resizeEvent(QResizeEvent *event)
{
    QPixmap *pixmap = new QPixmap(size());
    pixmap->fill(Qt::white);
    QPainter painter;
    painter.begin(pixmap);
    painter.drawPixmap(0, 0, *m_pPixmap);
    painter.end();
    delete m_pPixmap;
    m_pPixmap = pixmap;
    update();
}

void Widget::closeEvent(QCloseEvent *event)
{
    qDebug() << "ssss";
    int ret = QMessageBox::warning(this, "|_|", "Are you sure to close?"
                         , QMessageBox::Ok, QMessageBox::Cancel);
    if (QMessageBox::Ok == ret)
    {
        qDebug() << "byebye";
    }
    else if (QMessageBox::Cancel == ret)
    {
        event->ignore();
    }
}
