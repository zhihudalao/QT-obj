#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>

class Game : public QWidget
{
    Q_OBJECT

public:
    Game(QWidget *parent = 0);
    ~Game();


    void mouseMoveEvent(QMouseEvent *event);

public slots:
    void show();
private:
    QLabel *m_pNoteLab;
    QLabel *m_pNext;
    QPushButton *m_pYesPB;
    QPushButton *m_pNoPB;
};

#endif // GAME_H
