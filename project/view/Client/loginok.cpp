#include "loginok.h"

LoginOk::LoginOk(QWidget *parent) : QWidget(parent)
{
    resize(500, 400);
    m_pMapLab = new QLabel;
    m_pMapLab->setPixmap(QPixmap("E:\\1.jpg"));

    QHBoxLayout *p = new QHBoxLayout(this);
    p->addWidget(m_pMapLab);
}
