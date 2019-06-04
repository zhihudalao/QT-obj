#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QListWidget>
#include "usrinfo.h"
#include "login.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QStackedWidget *m_pSW;
    QListWidget *m_pLW;
    UsrInfo *m_pUsrInfo;
    Login *m_pLogin;
};

#endif // WIDGET_H
