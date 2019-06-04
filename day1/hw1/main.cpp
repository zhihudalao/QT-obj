#include "counter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    counter w;
    w.show();

    return a.exec();
}
