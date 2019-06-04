#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpsocket = new QUdpSocket(this);
    udpsocket->bind(QHostAddress::Any,8080);
    connect(udpsocket,SIGNAL(readyRead()),this,SLOT(readyReadSlot()));//收到网络数据报就开始往outputDevice写入，进行播放

    QAudioFormat format;
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setSampleType(QAudioFormat::SignedInt);
    format.setByteOrder(QAudioFormat::LittleEndian);

    output = new QAudioOutput(format,this);

    outputDevice = output->start();//开始播放

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::readyReadSlot(){
    while(udpsocket->hasPendingDatagrams()){
        QHostAddress senderip;
        quint16 senderport;
        qDebug()<<"audio is being received..."<<endl;
        video vp;
        memset(&vp,0,sizeof(vp));
        udpsocket->readDatagram((char*)&vp,sizeof(vp),&senderip,&senderport);
        outputDevice->write(vp.data,vp.lens);
    }
}
