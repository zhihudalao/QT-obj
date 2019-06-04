#ifndef USRINFO_H
#define USRINFO_H

#include <QWidget>

namespace Ui {
class UsrInfo;
}

class UsrInfo : public QWidget
{
    Q_OBJECT

public:
    explicit UsrInfo(QWidget *parent = 0);
    ~UsrInfo();

private:
    Ui::UsrInfo *ui;
};

#endif // USRINFO_H
