#include "homework.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    homework w;
    w.show();

    return a.exec();
}
