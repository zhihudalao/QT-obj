#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(700, 600);
    m_pTE = new QTextEdit("A");
    m_pTE->setReadOnly(true);
    QHBoxLayout *p = new QHBoxLayout(this);
    p->addWidget(m_pTE);
}

Widget::~Widget()
{

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    if (key >= Qt::Key_0 && key <= Qt::Key_9)
    {
        m_pTE->append(QString("%1").arg((char)(key-Qt::Key_0+'0')));
    }
    else if (key >= Qt::Key_A && key <= Qt::Key_Z)
    {
        m_pTE->append(QString("%1").arg((char)(key-Qt::Key_A+'A')));
    }
}
