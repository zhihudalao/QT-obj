#include "receive.h"
#include "ui_receive.h"
#include <QUdpSocket>
#include <QDebug>
#include <QHostAddress>

receive::receive(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::receive)
{
    ui->setupUi(this);
    udpSocket= new QUdpSocket(this);
    udpSocket->bind(QHostAddress::Any,8080);//绑定10004端口，不绑定也行，因为是发送端不涉及到接收

    QAudioFormat format;//定义音频处理的类型
    format.setSampleRate(8000);//采集频率为1s 8000次
    format.setChannelCount(1);//设定为1个省道
    format.setSampleSize(16);//设定采样大小，8也行，但是要发送端和接收端对应
    format.setCodec("audio/pcm");//设定为PCM编码
    format.setSampleType(QAudioFormat::SignedInt);
    format.setByteOrder(QAudioFormat::LittleEndian);//设定小尾的数据类型
    input = new QAudioInput(format,this);
    inputDevice = input->start();//input开始读入输入的音频信号，写入QIODevice，这里是inputDevice
    connect(inputDevice,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    //槽函数，当inputDevice收到input写入的音频数据之后,调用onReadyRead函数，发送数据到目标主机上


}

receive::~receive()
{
    delete ui;
}
void receive::onReadyRead(){
    qDebug()<<"It's sending audio!"<<endl;
    video vp;
    memset(&vp,0,sizeof(vp));
    //读取音频
    vp.lens = inputDevice->read(vp.audiodata,1024);//读取音频
    QHostAddress destaddr;
    destaddr.setAddress("192.168.1.106");
    udpSocket->writeDatagram((const char*)&vp,sizeof(vp),destaddr,8080);//将此结构体发送给目标主机，端口是10004，IP是192.168.1.104
}

