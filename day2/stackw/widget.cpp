#include "widget.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_pSW = new QStackedWidget;
    m_pLW = new QListWidget;
    m_pUsrInfo = new UsrInfo;
    m_pLogin = new Login;

    m_pSW->addWidget(m_pUsrInfo);
    m_pSW->addWidget(m_pLogin);

    //    m_pSW->setCurrentIndex(0);

    //    QStringList strList;
    //    strList << "UsrInfo" << "Login";
    //    m_pLW->addItems(strList);

    QHBoxLayout *pHBL = new QHBoxLayout;
    pHBL->addWidget(m_pLW);
    pHBL->addWidget(m_pSW);

    setLayout(pHBL);

    connect(m_pLW, SIGNAL(currentRowChanged(int))
            , m_pSW, SLOT(setCurrentIndex(int)));

    m_pLW->addItem(new QListWidgetItem(QIcon(QPixmap(":/user.png")), "UsrInfo"));
    m_pLW->addItem(new QListWidgetItem(QIcon(QPixmap(":/wtp.png")), "Login"));


}

Widget::~Widget()
{

}
