#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimerEvent>

class Item : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Item();

    void timerEvent(QTimerEvent *event);

private:
    bool m_bShow;
};

#endif // ITEM_H
