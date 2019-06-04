#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
//#include <QGraphicsLineItem>
//#include <QGraphicsEllipseItem>
//#include <QGraphicsRectItem>
#include "myitem.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QGraphicsView *m_pView;
    QGraphicsScene *m_pScene;
};

#endif // WIDGET_H
