#include "myedit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyEdit w;
    w.show();

    return a.exec();
}
