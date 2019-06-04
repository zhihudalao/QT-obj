#include "pic.h"
#include "ui_pic.h"
#include <QFileDialog>
pic::pic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pic)
{
    ui->setupUi(this);
}

pic::~pic()
{
    delete ui;
}

void pic::on_pushButton_clicked()
{
    QString file = QFileDialog:: getOpenFileName();
    ui-> map_lab -> setPixmap(QPixmap(file));
//    qDebug() << "xxxxxx";
}
