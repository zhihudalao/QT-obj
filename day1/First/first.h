#ifndef FIRST_H
#define FIRST_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>

class First : public QWidget
{
    Q_OBJECT

public:
    First(QWidget *parent = 0);
    ~First();

signals:
    void senMsg(QString data);

public slots:
    void handlePB();

private:
    QLineEdit *m_pInputLE;
    QPushButton *m_pSendPB;
};

#endif // FIRST_H
