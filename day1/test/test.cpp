#include "test.h"
#include <QFileDialog>

Test::Test(QWidget *parent)
    : QWidget(parent)
{
//    resize(700, 500);
    setMinimumSize(700, 600);
    setMaximumSize(700, 600);

    m_pMapLab = new QLabel;

    m_pUpdatePB = new QPushButton("更新");
    QFont font("Times", 20, QFont::Bold);
    m_pUpdatePB->setFont(font);
    QHBoxLayout *pPB = new QHBoxLayout;
    pPB->addStretch();
    pPB->addWidget(m_pUpdatePB);

    QVBoxLayout *pMain = new QVBoxLayout;
    pMain->addWidget(m_pMapLab);
    pMain->addLayout(pPB);

    setLayout(pMain);

    //关联信号槽
    connect(m_pUpdatePB, SIGNAL(clicked())
            , this, SLOT(handleUpdate()));
}

Test::~Test()
{

}

void Test::handleUpdate()
{
    QString file = QFileDialog::getOpenFileName();
    if (!file.isEmpty())
    {
//        m_pMapLab->setPixmap(QPixmap(file).scaled(m_pMapLab->width(), m_pMapLab->height()));
        m_pMapLab->setPixmap(QPixmap(file).scaled(m_pMapLab->size()));
    }
}




