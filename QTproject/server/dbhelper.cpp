#include "dbhelper.h"
#include <QDebug>
DBHelper* DBHelper::instance = 0;

DBHelper* DBHelper::getInstance()
{
    if(instance == 0){
        instance = new DBHelper();
    }
    return instance;
}

DBHelper::DBHelper()
{
    db = QSqlDatabase::addDatabase("QMYSQL");

}

void DBHelper::createConn()
{
    db.setHostName("localhost");
    db.setDatabaseName("userinfo");
    db.setUserName("root");
    db.setPassword("12345678");

    bool ok = db.open();
    if (!ok)
    {
        qDebug() << "打开失败";
    }
}
void DBHelper::destoryConn()
{
    db.close();
    db.removeDatabase("userinfo");
}
