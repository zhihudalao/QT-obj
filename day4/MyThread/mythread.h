#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QWidget>

namespace Ui {
class MyThread;
}

class MyThread : public QWidget
{
    Q_OBJECT

public:
    explicit MyThread(QWidget *parent = 0);
    ~MyThread();

private slots:
    void on_first_clicked();

    void on_second_clicked();

private:
    Ui::MyThread *ui;
};

#endif // MYTHREAD_H
