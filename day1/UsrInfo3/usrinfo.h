#ifndef USRINFO_H
#define USRINFO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "detail.h"

class UsrInfo : public QWidget
{
    Q_OBJECT

public:
    UsrInfo(QWidget *parent = 0);
    ~UsrInfo();

public slots:
    void showDetail();

private:
    QLabel *m_pNameLab;
    QLineEdit *m_pNameLE;

    QLabel *m_pPhoneLab;
    QLineEdit *m_pPhoneLE;

    QPushButton *m_pDetailPB;

    Detail *m_pDetail;
};

#endif // USRINFO_H
