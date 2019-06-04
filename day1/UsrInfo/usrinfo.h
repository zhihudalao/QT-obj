#ifndef USRINFO_H
#define USRINFO_H

#include <QWidget>
#include <QLabel>      //标签
#include <QLineEdit>   //行编辑窗口
#include <QTextEdit>   //文本编辑窗口
#include <QPushButton> //按钮
#include <QHBoxLayout> //水平布局
#include <QVBoxLayout> //垂直布局


class UsrInfo : public QWidget
{
    Q_OBJECT

public:
    UsrInfo(QWidget *parent = 0);
    ~UsrInfo();

private:
    QLabel *m_pPictureLab;
    QLabel *m_pNameLab;
    QLineEdit *m_pNameLE;

    QLabel *m_pPwdLab;
    QLineEdit *m_pPwdLE;

    QLabel *m_pDetailLab;
    QTextEdit *m_pDetailTE;
};

#endif // USRINFO_H
