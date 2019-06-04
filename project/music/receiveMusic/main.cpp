#include "receive.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    receive w;
    w.show();

    return a.exec();
}
