#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
//#include <QGraphicsLineItem>
//#include <QGraphicsEllipseItem>
//#include <QGraphicsRectItem>
#include "item.h"
#include <QKeyEvent>
#include "bullet.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();


    void keyPressEvent(QKeyEvent *event);


private:
    QGraphicsView *m_pView;
    QGraphicsScene *m_pScene;
    Item *item;
};

#endif // WIDGET_H
