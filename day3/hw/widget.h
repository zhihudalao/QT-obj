#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void mouseMoveEvent(QMouseEvent *event);
private:
    QLabel *m_pLabel;
    QPushButton *m_p1PB;
    QPushButton *m_p2PB;
    QPushButton *m_p3PB;
    QPushButton *m_p4PB;
};

#endif // WIDGET_H
