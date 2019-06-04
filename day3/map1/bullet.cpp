#include "bullet.h"

Bullet::Bullet(QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap("C:\\Users\\wtp\\Pictures\\bullet1.png"));

    startTimer(200);
}

void Bullet::timerEvent(QTimerEvent *event)
{
    setPos(x(), y()-40);
}
