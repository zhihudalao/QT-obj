#include "detail.h"
#include <QGridLayout>

Detail::Detail(QWidget *parent)
    : QWidget(parent)
{
    m_pAddrLab = new QLabel("住址：");
    m_pAddrLE = new QLineEdit("上海");

    m_pAgeLab = new QLabel("年龄：");
    m_pAgeLE = new QLineEdit("16");

    QGridLayout *pGL = new QGridLayout;
    pGL->addWidget(m_pAddrLab, 0, 0);
    pGL->addWidget(m_pAddrLE, 0, 1);
    pGL->addWidget(m_pAgeLab, 1, 0);
    pGL->addWidget(m_pAgeLE, 1, 1);

    setLayout(pGL);
}
