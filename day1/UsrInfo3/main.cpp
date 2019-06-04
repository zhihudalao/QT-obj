#include "usrinfo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UsrInfo w;
    w.show();

    return a.exec();
}
