#include "test.h"
#include "ui_test.h"
#include <QDebug>
#include <QFileDialog>

Test::Test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
}

Test::~Test()
{
    delete ui;
}

void Test::on_update_pb_clicked()
{
    QString file = QFileDialog::getOpenFileName();
    ui->map_lab->setPixmap(QPixmap(file));
    qDebug() << "xxxxxx";
}
