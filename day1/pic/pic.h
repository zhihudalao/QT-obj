#ifndef PIC_H
#define PIC_H

#include <QMainWindow>
#include <QWidget>
namespace Ui {
class pic;
}

class pic : public QMainWindow
{
    Q_OBJECT

public:
    explicit pic(QWidget *parent = 0);
    ~pic();

private slots:
    void on_pushButton_clicked();


private:
    Ui::pic *ui;


};


#endif // PIC_H
