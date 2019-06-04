#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QMouseEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void mouseMoveEvent(QMouseEvent *event);


private:
    QLabel *m_pMousePosLab;
};

#endif // WIDGET_H
