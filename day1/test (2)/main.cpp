#include "test.h"
#include "second.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Test w;
//    Second w;
    w.show();

    return a.exec();
}
