#include "usrinfo.h"
#include "ui_usrinfo.h"

UsrInfo::UsrInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UsrInfo)
{
    ui->setupUi(this);
}

UsrInfo::~UsrInfo()
{
    delete ui;
}
