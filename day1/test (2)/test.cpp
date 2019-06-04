#include "test.h"
#include <QFileDialog>
#include <QDebug>

Test::Test(QWidget *parent)
    : QWidget(parent)
{
    resize(700, 600);

    m_pSecond = new Second(this);

    m_pNext = new QPushButton("下一个窗口");
    QHBoxLayout *pM = new QHBoxLayout;
    pM->addWidget(m_pNext);
    setLayout(pM);

    connect(m_pNext, SIGNAL(clicked(bool))
            , this, SLOT(showSecond()));


    qDebug() << this;
}

Test::~Test()
{
}

void Test::showSecond()
{
    if (m_pSecond->isHidden())
    {
        m_pSecond->show();
    }

    this->hide();
}





