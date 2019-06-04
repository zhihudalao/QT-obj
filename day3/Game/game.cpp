#include "game.h"
#include <time.h>
#include <QDebug>

int i = 0;
Game::Game(QWidget *parent)
    : QWidget(parent)
{
    resize(700, 600);

    QFont font("Times", 20, QFont::Bold);
    setMouseTracking(true);

    m_pNoteLab = new QLabel(this);
    m_pNoteLab->setText("做我女朋友好吗？");
    m_pNoteLab->setFont(font);
    m_pNoteLab->move(100, 100);
    m_pNoteLab->setMouseTracking(true);

    m_pYesPB = new QPushButton("好的", this);
    m_pYesPB->setFont(font);
    m_pYesPB->move(200, 300);
    m_pYesPB->setMouseTracking(true);

    m_pNoPB = new QPushButton("不行", this);
    m_pNoPB->setFont(font);
    m_pNoPB->move(400, 300);
    m_pNoPB->setMouseTracking(true);
}

Game::~Game()
{

}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    QRect rectn = m_pNoPB->rect();
    if (rectn.contains(event->x()-m_pNoPB->x()
                       , event->y()-m_pNoPB->y()))
    {
        qsrand((unsigned)time(NULL));
        int data = qrand()%4;
        int x = m_pNoPB->x();
        int y = m_pNoPB->y();
        switch (data) {
        case 0: //left
            x -= m_pNoPB->width();
            break;
        case 1: //right
            x += m_pNoPB->width();
            break;
        case 2: //up
            y -= m_pNoPB->height();
            break;
        case 3: //down
            y += m_pNoPB->height();
            break;
        default:
            break;
        }
        m_pNoPB->move(x, y);
    }
#if 0
    QRect rectn = m_pNoPB->rect();
    QRect recty = m_pYesPB->rect();
    if (rectn.contains(event->x()-m_pNoPB->x()
                       , event->y()-m_pNoPB->y()))
    {
        if (QString("不行") == m_pNoPB->text())
        {
            m_pNoPB->setText("好的");
            m_pYesPB->setText("不行");
        }
    }
    else if (recty.contains(event->x()-m_pYesPB->x()
                            , event->y()-m_pYesPB->y()))
    {
        if (QString("不行") == m_pYesPB->text())
        {
            m_pYesPB->setText("好的");
            m_pNoPB->setText("不行");
        }
    }
#endif
}
