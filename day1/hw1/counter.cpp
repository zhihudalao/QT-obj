#include "counter.h"

counter::counter(QWidget *parent)
    : QWidget(parent)
{
    resize(500,600);
    m_1pOutputLE=new QLineEdit;
    m_2pOutputLE=new QLineEdit;
    m_3pOutputLE=new QLineEdit;
    QVBoxLayout *p_1LE= new QVBoxLayout;
    p_1LE->addWidget(m_1pOutputLE);
    p_1LE->addWidget(m_2pOutputLE);
    p_1LE->addWidget(m_3pOutputLE);

    m_1pPushPB = new QPushButton("1");
    m_2pPushPB = new QPushButton("2");
    m_3pPushPB = new QPushButton("3");
    m_4pPushPB = new QPushButton("+");
    m_5pPushPB = new QPushButton("4");
    m_6pPushPB = new QPushButton("5");
    m_7pPushPB = new QPushButton("6");
    m_8pPushPB = new QPushButton("-");
    m_9pPushPB = new QPushButton("7");
    m_10pPushPB = new QPushButton("8");
    m_11pPushPB = new QPushButton("9");
    m_12pPushPB = new QPushButton("*");
    m_13pPushPB = new QPushButton("c");
    m_14pPushPB = new QPushButton("0");
    m_15pPushPB = new QPushButton("=");
    m_16pPushPB = new QPushButton("/");
    QGridLayout *pGL =new QGridLayout;
    pGL->addWidget(m_1pPushPB,0,0);
    pGL->addWidget(m_2pPushPB,0,1);
    pGL->addWidget(m_3pPushPB,0,2);
    pGL->addWidget(m_4pPushPB,0,3);
    pGL->addWidget(m_5pPushPB,1,0);
    pGL->addWidget(m_6pPushPB,1,1);
    pGL->addWidget(m_7pPushPB,1,2);
    pGL->addWidget(m_8pPushPB,1,3);
    pGL->addWidget(m_9pPushPB,2,0);
    pGL->addWidget(m_10pPushPB,2,1);
    pGL->addWidget(m_11pPushPB,2,2);
    pGL->addWidget(m_12pPushPB,2,3);
    pGL->addWidget(m_13pPushPB,3,0);
    pGL->addWidget(m_14pPushPB,3,1);
    pGL->addWidget(m_15pPushPB,3,2);
    pGL->addWidget(m_16pPushPB,3,3);




    QVBoxLayout *pVBL = new QVBoxLayout;
    pVBL->addLayout(p_1LE);
    pVBL->addLayout(pGL);
//    pVBL->addLayout(pPwdHBL);
//    pVBL->addWidget(m_pDetailLab);
//    pVBL->addWidget(m_pDetailTE);
    setLayout(pVBL);
}

counter::~counter()
{

}
