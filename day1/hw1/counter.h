#ifndef COUNTER_H
#define COUNTER_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
class counter : public QWidget
{
    Q_OBJECT

public:
    counter(QWidget *parent = 0);
    ~counter();

private:
    QLineEdit *m_1pOutputLE;
    QLineEdit *m_2pOutputLE;
    QLineEdit *m_3pOutputLE;
    QPushButton *m_1pPushPB;
    QPushButton *m_2pPushPB;
    QPushButton *m_3pPushPB;
    QPushButton *m_4pPushPB;
    QPushButton *m_5pPushPB;
    QPushButton *m_6pPushPB;
    QPushButton *m_7pPushPB;
    QPushButton *m_8pPushPB;
    QPushButton *m_9pPushPB;
    QPushButton *m_10pPushPB;
    QPushButton *m_11pPushPB;
    QPushButton *m_12pPushPB;
    QPushButton *m_13pPushPB;
    QPushButton *m_14pPushPB;
    QPushButton *m_15pPushPB;
    QPushButton *m_16pPushPB;

};

#endif // COUNTER_H
