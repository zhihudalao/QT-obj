#include "widget.h"
#include "ui_widget.h"
#include <QByteArray>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(800, 700);
    m_pUdpSocket = new QUdpSocket(this);
    m_pUdpSocket->bind(QHostAddress("127.0.0.1"), 8080);

    connect(m_pUdpSocket, SIGNAL(readyRead())
            , this, SLOT(recvMsg()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::recvMsg()
{
    qint64 size = m_pUdpSocket->bytesAvailable();
    QByteArray data;
    data.resize(size);
    m_pUdpSocket->readDatagram(data.data(), data.size());
    QImage image;
    image.loadFromData(data,"JPG");
    QPixmap pixmap = QPixmap::fromImage(image);

    ui->label->setPixmap(pixmap.scaled(700, 600));
}
