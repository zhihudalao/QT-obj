#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QKeyEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void keyPressEvent(QKeyEvent *event);


private:
    QTextEdit *m_pTE;
};

#endif // WIDGET_H
