#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class MyItem : public QGraphicsPixmapItem
{
public:
    MyItem();


    void mousePressEvent(QGraphicsSceneMouseEvent *event);


private:
    QPixmap *m_pFirst;
    QPixmap *m_pSecond;
    bool m_bShow;
};

#endif // MYITEM_H
