#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimerEvent>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = nullptr);


    void timerEvent(QTimerEvent *event);
signals:

public slots:
};

#endif // BULLET_H
