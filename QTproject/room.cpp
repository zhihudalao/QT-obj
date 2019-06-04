#include "room.h"
#include "ui_room.h"
#include <QDebug>
#include <QCameraInfo>
#include <QBuffer>
#include <QImageReader>
#include "pack.h"


room::room(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::room)
{
    ui->setupUi(this);
}

room::room(QTcpSocket* clientSocket,QWidget* parent)
    :clientSocket(clientSocket),QWidget(parent),ui(new Ui::room)
{
    ui->setupUi(this);
    QCameraInfo info=QCameraInfo::defaultCamera();//返回在系统默认的摄像机
    camera=new QCamera(info,this);
    m_write=new QUdpSocket(this);
    vs=new videosurface(this);

    camera->setViewfinder(vs);//捕获视频流

    connect(vs,SIGNAL(frameChanged(QVideoFrame)),this,SLOT(frameChangedSlot(QVideoFrame)));

    m_ready=new QUdpSocket(this);

    connect(this->m_ready,SIGNAL(readyRead()),this,SLOT(readyreadSlot()));

    socketWrite=new QUdpSocket(this);//音频的udp
    socketWrite->bind(QHostAddress::AnyIPv4,6666,QUdpSocket::ReuseAddressHint
                      |QUdpSocket::ShareAddress);
    socketWrite->joinMulticastGroup(QHostAddress("224.0.1.205"));
    QAudioFormat format;
    format.setSampleRate(8000);//采样频率
    format.setChannelCount(1);//通道数
    format.setSampleSize(16);//样本数据位置
    format.setCodec("audio/pcm");//编码方法
    format.setByteOrder(QAudioFormat::LittleEndian);//字节存储数据
    format.setSampleType(QAudioFormat::SignedInt);//采样类型
    input=new QAudioInput(format);
    output=new QAudioOutput(format);
//    outputdevice=output->start();

}

room::~room()
{
    delete ui;
}

//文字显示
void room::wordshow(const pack_t &pack)
{
    QString name=QString::fromLocal8Bit(pack.name);
    QString message=QString::fromLocal8Bit(pack.message);
    QString data=QString("%1 : %2").arg(name).arg(message);
    ui->show_word->append(data);
}

//列表显示
void room::broadshow(const pack_t &pack)
{
    QString rn=QString::fromLocal8Bit(pack.name);
    ui->listWidget->addItem(rn);
}

void room::copen()
{
    camera->start();
}

void room::cclose()
{
    camera->stop();
    ui->video_la->clear();
}

quint16 room::getprot()
{
    return R_prot;
}

void room::srtprot(const quint16 R_prot)
{
    this->R_prot=R_prot;
}

void room::DK()
{
    m_ready->bind(QHostAddress::AnyIPv4,getprot(),
                  QUdpSocket::ShareAddress
                  |QUdpSocket::ReuseAddressHint);
    m_ready->joinMulticastGroup(QHostAddress("224.0.0.140"));
}
/*
void room::udpAudio()
{
    m_writeAudio=new QUdpSocket(this);
    m_readAudio=new QUdpSocket(this);
    //groupAddress->setAddress("224.0.1.205");

    m_writeAudio->setSocketOption(QAbstractSocket::MulticastTtlOption,1);
    //设置套接字属性
    m_readAudio->bind(QHostAddress::AnyIPv4,6666,QUdpSocket::ReuseAddressHint
                      |QUdpSocket::ShareAddress);//绑定广播地址端口
    m_readAudio->joinMulticastGroup(QHostAddress("224.0.1.205"));//添加到组播

    QObject::connect(m_readAudio,SIGNAL(readyRead()),this,SLOT(ReadyReadAudio()));

    QAudioFormat format;
    format.setSampleRate(8000);//采样频率
    format.setChannelCount(1);//通道数
    format.setSampleSize(16);//样本数据位置
    format.setCodec("audio/pcm");//编码方法
    format.setByteOrder(QAudioFormat::LittleEndian);//字节存储数据
    format.setSampleType(QAudioFormat::SignedInt);//采样类型
    input=new QAudioInput(format);
    output=new QAudioOutput(format);

    outputdevice=output->start();

}
*/
/*
void room::setroomName(QString roomName)
{
    this->roomName=roomName;
}

void room::setprot(quint16 R_prot)
{
    this->R_prot=R_prot;
}
*/

//刷新列表
void room::on_renew_btn_clicked()
{
    ui->listWidget->clear();
    emit room_renew();
}

//发送消息
void room::on_send_btn_clicked()
{
    QString news=ui->write_word->text();
    emit room_send(news);
    ui->write_word->clear();
}

void room::readyreadSlot()
{
    quint64 size=m_ready->pendingDatagramSize();
    QByteArray buff;

    buff.resize(size);

    m_ready->readDatagram(buff.data(),buff.size());

    QBuffer buffer(&buff);

    QImageReader reader(&buffer,"JPEG");

    QImage image=reader.read();

    QPixmap pix=QPixmap::fromImage(image);

    QMatrix matrix;
    matrix.rotate(180);

    pix=pix.transformed(matrix);
    ui->video_la->setPixmap(pix.scaled(ui->video_la->size()));
    /**接收UDP视频数据**/
//    static QByteArray *imageBytes=new QByteArray(2280000,0);
//    static QDataStream* dataStream=new QDataStream(imageBytes,QIODevice::ReadWrite);//读写格式
//    while(m_ready->hasPendingDatagrams())
//    {
//        ImagePackage pack;
//        memset(&pack,0,sizeof(ImagePackage));
//        m_ready->readDatagram((char*)&pack,sizeof(ImagePackage));
//        if(true==pack.isLastPack)
//        {
//            dataStream->writeRawData(pack.data,pack.packTaken);
//            QImage image=QImage((uchar*)imageBytes->data(),
//                    pack.width,
//                    pack.height,
//                    pack.bytesPerline,
//                    QImage::Format_RGB32);

//            QPixmap map=QPixmap::fromImage(image);
//            map=map.scaled(ui->video_la->size());
//            ui->video_la->setPixmap(map);
//        }
//        else
//        {
//            dataStream->writeRawData(pack.data,pack.packTaken);
//        }
//    }
}

void room::on_video_on_btn_clicked()
{
    emit onCamera();
    //camera->start();
}

void room::on_video_off_btn_clicked()
{
    emit outCamera();
    //camera->stop();
}

void room::frameChangedSlot(QVideoFrame frame)
{
//    static int i=0;
//    i++;
//    int unitBytes=4096;
    frame.map(QAbstractVideoBuffer::ReadOnly);
    QImage image(
        frame.bits(),
        frame.width(),
        frame.height(),
        frame.bytesPerLine(),
        QVideoFrame::imageFormatFromPixelFormat(frame.pixelFormat())
    );
    QPixmap pixmap=QPixmap::fromImage(image);

    QMatrix matrix;
    matrix.rotate(180);

    pixmap=pixmap.transformed(matrix);
    ui->video_la->setPixmap(pixmap.scaled(ui->video_la->size()));//通过scaled函数设置自适应大小


//    //发送视频图片信息
//    if(i % 4 !=0)
//        return ;

//        int byteCount=image.byteCount();//图片大小
//        int width=image.width();//图片宽度
//        int height=image.height();//图片高度
//        int bytePerLine=image.bytesPerLine();//每行字节数

//        int writeBytes=0;
//        while(true)
//        {
//            ImagePackage pack;
//            memset(&pack,0,sizeof(ImagePackage));

//            pack.width=width;
//            pack.height=height;
//            pack.bytesPerline=bytePerLine;
//            if(writeBytes<byteCount)
//            {
//                memcpy(pack.data,(char*)image.bits()+writeBytes,unitBytes);
//                pack.packTaken=unitBytes;
//                writeBytes+=unitBytes;
//                if(writeBytes>=byteCount)
//                {
//                    pack.isLastPack=true;
//                    pack.packTaken=unitBytes-writeBytes+byteCount;
//                }
//                else
//                {
//                    pack.isLastPack=false;
//                    pack.packTaken=unitBytes;
//                }
//                m_write->writeDatagram((char*)&pack,sizeof(ImagePackage),
//                                       QHostAddress("224.0.0.140"),getprot());
//            }
//            else
//            {
//                break;
//            }
//        }



    QByteArray byte;
    QBuffer buffer(&byte);
    image.save(&buffer,"JPEG");
    m_write->writeDatagram(byte,QHostAddress("224.0.0.140"),getprot());
    qDebug()<<"set camera ok";
}

//接收音频
void room::ReadyReadAudio()
{
    AudioPackage pack;
    memset(&pack,0,sizeof(AudioPackage));
    m_readAudio->readDatagram((char*)&pack,sizeof(AudioPackage));

    outputdevice->write(pack.data,pack.dataLen);

}

void room::on_sound_on_btn_clicked()
{
    emit soundopen();
}

void room::captureDataFromDevice()
{
    AudioPackage pack;
    memset(&pack,0,sizeof(AudioPackage));
    pack.dataLen=inputdevice->read(pack.data,1024);
    socketWrite->writeDatagram((char*)&pack,sizeof(AudioPackage),QHostAddress("224.0.1.205"),6666);
    outputdevice->write(pack.data,pack.dataLen);
}

void room::on_sound_off_btn_clicked()
{
    emit soundclose();
    qDebug()<<"close sound";
}

void room::sound_open()
{
    inputdevice=input->start();
    outputdevice=output->start();
    connect(inputdevice,SIGNAL(readyRead()),this,SLOT(captureDataFromDevice()));
}

void room::sound_close()
{
    qDebug()<<"enter close sound";
    input->stop();
    output->stop();
}
