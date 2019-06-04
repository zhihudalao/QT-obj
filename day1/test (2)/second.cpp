#include "second.h"
#include <QHBoxLayout>
#include <QDebug>

Second::Second(QWidget *first, QWidget *parent)
    : QWidget(parent)
{
    m_pFirstInterface = first;

    resize(400, 300);
    m_pFirst = new QPushButton("上一个界面");

    QHBoxLayout *pMain = new QHBoxLayout;
    pMain->addWidget(m_pFirst);
    setLayout(pMain);

    qDebug() << m_pFirstInterface;

    connect(m_pFirst, SIGNAL(clicked(bool))
            , this, SLOT(showFirst()));

}

void Second::showFirst()
{
    if (m_pFirstInterface->isHidden())
    {
        m_pFirstInterface->show();
    }
    hide();
}
