#ifndef USRINFO_H
#define USRINFO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class UsrInfo : public QWidget
{
    Q_OBJECT

public:
    UsrInfo(QWidget *parent = 0);
    ~UsrInfo();

    void init();

private:
    QLabel *m_pUsrNameLab;
    QLineEdit *m_pUsrNameLE;

    QLabel *m_pNameLab;
    QLineEdit *m_pNameLE;

    QLabel *m_pAgeLab;
    QComboBox *m_pAgeCB;

    QLabel *m_pGenderLab;
    QComboBox *m_pGenderCB;

    QLabel *m_pDepartLab;
    QTextEdit *m_pDepartTE;


    QLabel *m_pNoteLab;

    QLabel *m_pPictureLab;
    QLabel *m_pShowPictureLab;
    QPushButton *m_pUpdatePB;

    QLabel *m_pDetailLab;
    QTextEdit *m_pDetailTE;

};

#endif // USRINFO_H
