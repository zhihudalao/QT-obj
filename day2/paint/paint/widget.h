#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPen>
#include <QPainter>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void paintEvent(QPaintEvent *event);

private:
    QTimer *m_pTimer;

};

#endif // WIDGET_H
