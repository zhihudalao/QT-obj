#include "mythread.h"
#include "ui_mythread.h"
#include "testthread.h"

MyThread::MyThread(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyThread)
{
    ui->setupUi(this);
}

MyThread::~MyThread()
{
    delete ui;
}

void MyThread::on_first_clicked()
{
    static TestThread test("11111");
    test.start();
//    test.run();
}

void MyThread::on_second_clicked()
{
    static TestThread test("22222");
    test.start();
//    test.run();
}
