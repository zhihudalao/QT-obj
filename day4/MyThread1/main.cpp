#include "mythread.h"
#include <QApplication>
//#include "testthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyThread w;
    w.show();

//    TestThread th1("aaa");
////    th.run();
//    th1.start();

//    TestThread th2("bbb");
////    th.run();
//    th2.start();

    return a.exec();
}
