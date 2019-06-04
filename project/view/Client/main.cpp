#include "client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CLient w;
    w.show();

    return a.exec();
}
