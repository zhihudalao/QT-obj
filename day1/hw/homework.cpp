#include "homework.h"

homework::homework(QWidget *parent)
    : QWidget(parent)
{
    resize(500,600);
    m_pDetilTE=new QTextEdit;
    QVBoxLayout *pDetil=new QVBoxLayout;
    pDetil->addWidget(m_pDetilTE);

    m_pIntputLE=new QLineEdit;
    m_pSendPB=new QPushButton("发送");
    QHBoxLayout *pLP =  new QHBoxLayout;
    pLP->addWidget(m_pIntputLE);
    pLP->addWidget(m_pSendPB);

    QVBoxLayout *pVBL = new QVBoxLayout;
    pVBL->addLayout(pDetil);
    pVBL->addLayout(pLP);

    setLayout(pVBL);

    connect(m_pSendPB,SIGNAL(clicked(bool))
            ,this,SLOT(handlePB()));

}
homework::~homework(){}

void homework::handlePB()
{
    QString data =  m_pIntputLE->text();
    emit senMsg(data);
    m_pIntputLE->clear();
    m_pDetilTE->append(data);
}
