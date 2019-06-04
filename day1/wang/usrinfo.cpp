#include "usrinfo.h"
#include <QGridLayout>

UsrInfo::UsrInfo(QWidget *parent)
    : QWidget(parent)
{
    init();
}

UsrInfo::~UsrInfo()
{

}

void UsrInfo::init()
{
    QGridLayout *pGL = new QGridLayout;

    m_pUsrNameLab = new QLabel("用户名:");
    m_pUsrNameLE = new QLineEdit;
    pGL->addWidget(m_pUsrNameLab, 0, 0);
    pGL->addWidget(m_pUsrNameLE, 0, 1);
//    QHBoxLayout *pUNHBL = new QHBoxLayout;
//    pUNHBL->addWidget(m_pUsrNameLab);
//    pUNHBL->addWidget(m_pUsrNameLE);

    m_pNameLab = new QLabel("姓名:");
    m_pNameLE = new QLineEdit;

    pGL->addWidget(m_pNameLab, 1, 0);
    pGL->addWidget(m_pNameLE, 1, 1);
//    QHBoxLayout *pNHBL = new QHBoxLayout;
//    pNHBL->addWidget(m_pNameLab);
//    pNHBL->addWidget(m_pNameLE);

    m_pAgeLab = new QLabel("年龄:");
    m_pAgeCB = new QComboBox;
    QStringList s;
    s << "1" << "2" << "3" << "4" << "5" << "6";
    m_pAgeCB->addItems(s);
    pGL->addWidget(m_pAgeLab, 2, 0);
    pGL->addWidget(m_pAgeCB, 2, 1);

//    QHBoxLayout *pAgeHBL = new QHBoxLayout;
//    pAgeHBL->addWidget(m_pAgeLab);
//    pAgeHBL->addWidget(m_pAgeCB);

    m_pGenderLab = new QLabel("性别:");
    m_pGenderCB = new QComboBox;
    m_pGenderCB->addItem("男");
    m_pGenderCB->addItem("女");

    pGL->addWidget(m_pGenderLab, 3, 0);
    pGL->addWidget(m_pGenderCB, 3, 1);

//    QHBoxLayout *pGHBL = new QHBoxLayout;
//    pGHBL->addWidget(m_pGenderLab, 1);
//    pGHBL->addWidget(m_pGenderCB, 10);

    m_pDepartLab = new QLabel("部门:");
    m_pDepartTE = new QTextEdit;
    pGL->addWidget(m_pDepartLab, 4, 0);
    pGL->addWidget(m_pDepartTE, 4, 1);

//    QHBoxLayout *pDPHBL = new QHBoxLayout;
//    pDPHBL->addWidget(m_pDepartLab);
//    pDPHBL->addWidget(m_pDepartTE);

    m_pNoteLab = new QLabel("备注:");
    m_pNoteLab->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    pGL->addWidget(m_pNoteLab, 5, 0, 1, 2);
    setLayout(pGL);

//    QVBoxLayout *pLeft = new QVBoxLayout;
//    pLeft->addLayout(pUNHBL);
//    pLeft->addLayout(pNHBL);
//    pLeft->addLayout(pAgeHBL);
//    pLeft->addLayout(pGHBL);
//    pLeft->addLayout(pDPHBL);
//    pLeft->addWidget(m_pNoteLab);

//    m_pPictureLab = new QLabel("头像:");
//    m_pShowPictureLab = new QLabel;
//    m_pShowPictureLab->setPixmap(QPixmap("C:\\Users\\wtp\\Pictures\\t1.jpg"));
//    m_pUpdatePB = new QPushButton("更新");

//    QHBoxLayout *pMapHBL = new QHBoxLayout;
////    pMapHBL->setMargin(100);
//    pMapHBL->addWidget(m_pPictureLab);
////    pMapHBL->setSpacing(30);
//    pMapHBL->addWidget(m_pShowPictureLab);
//    pMapHBL->addWidget(m_pUpdatePB);

//    m_pDetailLab = new QLabel("详细信息:");
//    m_pDetailTE = new QTextEdit;

//    QVBoxLayout *pRight = new QVBoxLayout;
//    pRight->addLayout(pMapHBL);
//    pRight->addWidget(m_pDetailLab);
//    pRight->addWidget(m_pDetailTE);

//    QHBoxLayout *pMainHBL = new QHBoxLayout;
//    pMainHBL->addLayout(pLeft);
//    pMainHBL->addLayout(pRight);
//    setLayout(pMainHBL);

}
