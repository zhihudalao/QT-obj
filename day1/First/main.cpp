#include "first.h"
#include "second.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    First first;
    Second second;
    first.show();
    second.show();

    QObject::connect(&first, SIGNAL(senMsg(QString))
                     , &second, SLOT(recvMsg(QString)));

    return a.exec();
}
