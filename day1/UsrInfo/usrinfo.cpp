#include "usrinfo.h"

UsrInfo::UsrInfo(QWidget *parent)
    : QWidget(parent)
{
    resize(900, 700);

    //产生标签对象
    m_pPictureLab = new QLabel;
    QPixmap pixmap("C:\\Users\\wtp\\Pictures\\hero1.png");
    //设置标签上显示的像素图片对象
    m_pPictureLab->setPixmap(pixmap);
    //产生一个水平布局对象
    QHBoxLayout *pMapHBL = new QHBoxLayout;
    //添加一个弹簧
    pMapHBL->addStretch();
    //将标签加入布局器中
    pMapHBL->addWidget(m_pPictureLab);
    pMapHBL->addStretch();

    QFont font("Times", 20, QFont::Bold);

    //产生一个标签并设置标签上显示的内容
    m_pNameLab = new QLabel("Name:");
    m_pNameLE = new QLineEdit;
    //将名字标签及输入框设置为水平布局
    QHBoxLayout *pNameHBL = new QHBoxLayout;
    pNameHBL->addWidget(m_pNameLab);
    pNameHBL->addWidget(m_pNameLE);

    m_pPwdLab = new QLabel;
    m_pPwdLab->setText(" Pwd:");
    m_pPwdLE = new QLineEdit;
    //设置行编辑窗口的显示模式为密码的显示样式
    //及不显示明文，用黑点表示输入的密码
    m_pPwdLE->setEchoMode(QLineEdit::Password);

    QHBoxLayout *pPwdHBL = new QHBoxLayout;
    pPwdHBL->addWidget(m_pPwdLab);
    pPwdHBL->addWidget(m_pPwdLE);

    m_pDetailLab = new QLabel("Detail:");
    m_pDetailTE = new QTextEdit;

    //设置字体
    m_pNameLab->setFont(font);
    m_pNameLE->setFont(font);

    m_pPwdLab->setFont(font);
    m_pPwdLE->setFont(font);

    m_pDetailLab->setFont(font);
    m_pDetailTE->setFont(font);

    QVBoxLayout *pVBL = new QVBoxLayout;
    pVBL->addLayout(pMapHBL);
    pVBL->addLayout(pNameHBL);
    pVBL->addLayout(pPwdHBL);
    pVBL->addWidget(m_pDetailLab);
    pVBL->addWidget(m_pDetailTE);

    //设置窗口的布局
    setLayout(pVBL);
}

UsrInfo::~UsrInfo()
{

}
