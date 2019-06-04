#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    resize(700,600);

    m_pLabel = new QLabel("qqqqqqqqqqqqqqqqqqqq");
    QHBoxLayout *plabel = new QHBoxLayout;
    plabel->addWidget(m_pLabel);

    m_p1PB = new QPushButton("1");
    m_p2PB  = new QPushButton("2");
    m_p3PB  = new QPushButton("3");
    m_p4PB  = new QPushButton("4");
    QGridLayout *pGL = new QGridLayout;
    pGL->addWidget(m_p1PB,0,2);
    pGL->addWidget(m_p2PB,1,0);
    pGL->addWidget(m_p3PB,1,3);
    pGL->addWidget(m_p4PB,2,2);
    setLayout(pGL);


    QVBoxLayout *pVBL = new QVBoxLayout;
    pVBL->addLayout(plabel);
    pVBL->addLayout(pGL);

    setLayout(pVBL);


}

void Widget::mouseMoveEvent(QMouseEvent *event)
{

}




Widget::~Widget(){}
