#include "second.h"

Second::Second(QWidget *parent) : QWidget(parent)
{
    resize(700, 600);
    m_pDataTE = new QTextEdit;
    m_pDataTE->setReadOnly(true);
    QHBoxLayout *pMain = new QHBoxLayout;
    pMain->addWidget(m_pDataTE);
    setLayout(pMain);
}

void Second::recvMsg(QString msg)
{
    m_pDataTE->append(msg);
}
