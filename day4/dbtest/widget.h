#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSqlRecord>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void showData();

private:
    QSqlDatabase m_db;
    QPushButton *m_pQueryPB;
};

#endif // WIDGET_H
