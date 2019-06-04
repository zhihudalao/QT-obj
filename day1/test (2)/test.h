#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "second.h"

class Test : public QWidget
{
    Q_OBJECT

public:
    Test(QWidget *parent = 0);
    ~Test();

public slots:
    void showSecond();

private:
    QPushButton *m_pNext;
    Second *m_pSecond;
};

#endif // TEST_H
