#include "usrinfo.h"
#include <QGridLayout>

UsrInfo::UsrInfo(QWidget *parent)
    : QWidget(parent)
{
    m_pNameLab = new QLabel("姓名：");
    m_pNameLE = new QLineEdit;

    m_pPhoneLab = new QLabel("电话：");
    m_pPhoneLE = new QLineEdit;

    QGridLayout *pGL = new QGridLayout;
    pGL->addWidget(m_pNameLab, 0, 0);
    pGL->addWidget(m_pNameLE, 0, 1);
    pGL->addWidget(m_pPhoneLab, 1, 0);
    pGL->addWidget(m_pPhoneLE, 1, 1);

    m_pDetailPB = new QPushButton("详细信息");
    pGL->addWidget(m_pDetailPB, 2, 0, 1, 2);

    m_pDetail = new Detail;

    connect(m_pDetailPB, SIGNAL(clicked(bool))
            , this, SLOT(showDetail()));

    QVBoxLayout *pMain = new QVBoxLayout;
    pMain->addLayout(pGL);
    pMain->addWidget(m_pDetail);
    setLayout(pMain);

    m_pDetail->hide();

    pMain->setSizeConstraint(QLayout::SetFixedSize);
}

UsrInfo::~UsrInfo()
{

}

void UsrInfo::showDetail()
{
    if (m_pDetail->isHidden())
    {
        m_pDetail->show();
    }
    else
    {
        m_pDetail->hide();
    }
}
