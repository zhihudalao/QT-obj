#include "first.h"

First::First(QWidget *parent)
    : QWidget(parent)
{
    m_pInputLE = new QLineEdit;
    m_pSendPB = new QPushButton("发送");
    QHBoxLayout *pMain = new QHBoxLayout;
    pMain->addWidget(m_pInputLE);
    pMain->addWidget(m_pSendPB);

    setLayout(pMain);


    connect(m_pSendPB, SIGNAL(clicked(bool))
            , this, SLOT(handlePB()));
}

First::~First()
{}

void First::handlePB()
{
    QString data = m_pInputLE->text();
    emit senMsg(data);
    m_pInputLE->clear();
}





