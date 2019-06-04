#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QPoint>
#include <QMouseEvent>
#include <QPaintEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent *event);



private:
    QPixmap *m_pPixmap;
    QPoint m_start;
};

#endif // WIDGET_H
