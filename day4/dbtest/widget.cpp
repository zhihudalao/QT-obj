#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("localhost");
    m_db.setDatabaseName("chaoliu");
    m_db.setUserName("root");
    m_db.setPassword("root");
    bool ok = m_db.open();
    if (ok)
    {
        qDebug() << "ok";
//        m_db.close();
    }
    else
    {
        qDebug() << "failed";
    }

    m_pQueryPB = new QPushButton("QUERY");
    QHBoxLayout *pMain = new QHBoxLayout(this);
    pMain->addWidget(m_pQueryPB);

    connect(m_pQueryPB, SIGNAL(clicked(bool))
            , this, SLOT(showData()));
}

Widget::~Widget()
{

}

void Widget::showData()
{
    QSqlQuery query;
    if (query.exec("select * from student"))
    {
        qDebug() << "query ok";
        QSqlRecord record = query.record();
        int colums = record.count();
        while (query.next())
        {
            for (int i=0; i<colums; i++)
            {
                qDebug () << query.value(i).toString();
            }
        }
    }
    else
    {
        qDebug() << "query failed";
    }
}
