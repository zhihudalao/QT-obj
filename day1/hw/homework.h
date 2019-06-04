#ifndef HOMEWORK_H
#define HOMEWORK_H

#include <QWidget>
#include<QLineEdit>
#include<QTextEdit>
#include<QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>

class homework : public QWidget
{
    Q_OBJECT

public:
    homework(QWidget *parent = 0);
    ~homework();
signals:
    void senMsg(QString data);

public  slots:
    void handlePB();

private:

    QTextEdit *m_pDetilTE;
    QLineEdit *m_pIntputLE;
    QPushButton *m_pSendPB;
};

#endif // HOMEWORK_H
