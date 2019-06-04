#include "chatroom.h"
#include "ui_chatroom.h"
#include<QDateTime>
#include<QMessageBox>
#include"roommanager.h"
#include "videosurface.h"
#include <QDebug>
#include<QPoint>
#include<QMovie>
#include<QBuffer>
#include <QImage>
#include <QThread>
#include <QtCore/qobject.h>
ChatRoom::ChatRoom(ClientSocket *cs, QTcpSocket *socket, QString curRoom,
                   user_t user, QWidget *parent) :
    QDialog(parent),cs(cs),socket(socket),curRoom(curRoom),user(user),
    ui(new Ui::ChatRoom)
{
    ui->setupUi(this);

    ui->textEdit->installEventFilter(this); //安装监听

    showChatList();//聊天用户列表


    QObject::connect (cs, SIGNAL(sigChatName(user_t)),
                      this, SLOT(onsigChatName(user_t)));//添加用户名到列表
    QObject::connect (cs, SIGNAL(sigChatList(user_t)),
                      this, SLOT(onsigChatList(user_t)));//刷新列表
    QObject::connect (cs, SIGNAL(sigChatText(user_t)),
                      this, SLOT(onsigChatText(user_t)));//文字聊天信息处理
    QObject::connect(cs, SIGNAL(sigMasterExit(user_t)),
                     this, SLOT(onsigMasterExit(user_t)));//房主退出
    QObject::connect (cs, SIGNAL(sigVideo(user_t)),
                      this, SLOT(onsigVideo(user_t)));//视频处理
    QObject::connect(cs,SIGNAL(sigAudio(user_t)),
                     this,SLOT(onsigAudio(user_t)));//语音处理
    QObject::connect (cs, SIGNAL(sigunVideo(user_t)),
                      this, SLOT(onsigunVideo(user_t)));//关闭视频
    QObject::connect (cs, SIGNAL(sigunAudio(user_t)),
                      this, SLOT(onsigunAudio(user_t)));//关闭语音
    QObject::connect (cs, SIGNAL(sigBs(user_t)),
                      this, SLOT(onsigBs(user_t)));//弹幕处理


    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),
                     this,SLOT(onTimeOut()));//定时器



    udpVideo();
    udpAudio();
}




/*
函数功能：udp视频传输协议
参数：无
返回值：无
*/
void ChatRoom::udpVideo()
{
    //打开摄像头
    QCameraInfo info = QCameraInfo::defaultCamera ();
    camera = new QCamera(info, this);
    VideoSurface *vf = new VideoSurface(this);
    camera->setViewfinder (vf);

    QObject::connect (vf, SIGNAL(videoChanged(QVideoFrame)),
                      this, SLOT(onvideoChanged(QVideoFrame)));

    //建立udp网络连接
    socketWrite = new QUdpSocket(this);
    socketRead = new QUdpSocket(this);
    //组播地址
    groupAddress.setAddress ("224.0.1.205");

    //    groupAddress.setAddress ("239.88.88.88");
    socketWrite->setSocketOption (QAbstractSocket::MulticastTtlOption,1);//设置套接字属性
    socketRead->bind (QHostAddress::AnyIPv4, 10001, QUdpSocket::ReuseAddressHint|QUdpSocket::ShareAddress);//绑定广播地址端口
    socketRead->joinMulticastGroup (groupAddress);  //添加到组播，绑定到读套接字上

    //udp读写
    QObject::connect (socketRead, SIGNAL(readyRead()),
                      this, SLOT(UdpReadRead()));

}

/*
函数功能：udp接收图片
参数：无
返回值：无
*/

void ChatRoom::UdpReadRead ()
{
    qDebug()<<"***";

    static QByteArray byteArray(2280000,0);   //字符数组；
    //数据流
    static QDataStream dataStream(&byteArray,QIODevice::ReadWrite);
    static int readed = 0;
    while(socketRead->hasPendingDatagrams()){

        char buffer[1024] = {0};
        readed += socketRead->readDatagram(buffer,1024);
        dataStream.writeRawData(buffer,1024);
    }

    if(readed>=102400){
        QImage image = QImage((uchar*)byteArray.data(),
                              160,
                              96,
                              640,
                              QImage::Format_RGB32);
        QPixmap map =QPixmap::fromImage(image);
        map = map.scaled (ui->videosurface->size ());
        ui->videosurface->setPixmap(map);
        readed = 0;
        dataStream.device ()->seek (0);
    }
}


/*
函数功能：获取视频采集的图片并通过udp发送出去
参数：QVideoFrame curFrame
返回值：无
*/

void ChatRoom::onvideoChanged(QVideoFrame curFrame)
{
    static int i = 0;
    i++;
    int unitBytes=4096;
    QVideoFrame frame(curFrame);
    frame.map(QAbstractVideoBuffer::ReadOnly);
    //通过QVideoFrame对象构建QImage对象
    QImage image(frame.bits(),
                 frame.width(),
                 frame.height(),
                 QVideoFrame::imageFormatFromPixelFormat(frame.pixelFormat()));

    //将图像旋转180
    QMatrix matrix;
    matrix.rotate(180);
    image = image.transformed(matrix);
    //将QImage格式转化成QPixmap格式显示图片
    QPixmap pixmap = QPixmap::fromImage(image);
    pixmap = pixmap.scaled(ui->videosurface->size());
    ui->videosurface->setPixmap(pixmap);
    qDebug()<<"111";
    if(i % 2 == 0){
        qDebug()<<"111";
        int byteCount = image.byteCount();

        int width = image.width();
        int height = image.height();
        int bytePerLine = image.bytesPerLine();

        int writeBytes = 0;
        while(true){
            ImagePackage pack;
            memset(&pack,0,sizeof(ImagePackage));
            pack.width=width;
            pack.height=height;
            pack.bytesPerline=bytePerLine;
            if(writeBytes<byteCount){
                memcpy(pack.data,(char*)image.bits()+writeBytes,unitBytes);
                pack.packTaken=unitBytes;
                writeBytes += unitBytes;
                if(writeBytes>=byteCount){
                    pack.isLastPack=true;
                    pack.packTaken=unitBytes-writeBytes+byteCount;
                }else{
                    pack.isLastPack=true;
                    pack.packTaken=unitBytes;

                }
                socketWrite->writeDatagram((char*)&pack + sizeof(ImagePackage),
                                           1024, QHostAddress::Broadcast,10001);

            }else{
                break;
            }
        }
    }
}

/*
函数功能：直播按钮
参数：无
返回值：无
*/
void ChatRoom::on_video_clicked()
{
    if(user.flag != MASTER){
        QMessageBox::warning (this, "警告", "只有房主可以开启直播");
        return;
    }
    static int fv = -1;
    if(fv == -1){
        user.type = VIDEO;      //开启视频
        socket->write((char*)&user, sizeof(user));

        fv *= -1;
    }
    else if(fv == 1){        //关闭视频
        user.type = UNVIDEO;
        socket->write((char*)&user, sizeof(user));

        fv *= -1;
    }
}

/*
函数功能：开启直播
参数：user_t user
返回值：无
*/
void ChatRoom::onsigVideo (user_t user)
{

    if(user.flag != MASTER){
        QMessageBox::information (this, "提示", "房主正在发起直播！");
    }
    //开启摄像头
    ui->videosurface->show ();
    camera->start ();

}


/*
函数功能：关闭直播
参数：user_t user
返回值：无
*/
void ChatRoom::onsigunVideo (user_t user)
{
    if(user.flag != MASTER){
        QMessageBox::information (this, "提示", "房主已经关闭直播！");
    }else{
        camera->stop ();
        ui->videosurface->hide ();
    }
}

/*
函数功能：udp音频传输协议
参数：无
返回值：无
*/
void ChatRoom::udpAudio()
{
    socketWdaudio = new QUdpSocket(this);
    socketRdaudio = new QUdpSocket(this);
    groupAddress1.setAddress ("224.0.1.205");
    socketWdaudio->setSocketOption (QAbstractSocket::MulticastTtlOption,1);//设置套接字属性
    socketRdaudio->bind (QHostAddress::AnyIPv4, 6666,
                         QUdpSocket::ReuseAddressHint|QUdpSocket::ShareAddress);//绑定广播地址端口
    socketRdaudio->joinMulticastGroup (groupAddress1);  //添加到组播，绑定到读套接字上

    QObject::connect(socketRdaudio, SIGNAL(readyRead()),
                     this, SLOT(ReadyReadAudio()));
    // 设置音频文件格式;
    QAudioFormat format;
    // 设置采样频率;
    format.setSampleRate(8000);
    // 设置通道数;
    format.setChannelCount(1);
    // 设置每次采样得到的样本数据位值;
    format.setSampleSize(16);
    // 设置编码方法;
    format.setCodec("audio/pcm");
    // 设置采样字节存储顺序;
    format.setByteOrder(QAudioFormat::LittleEndian);
    // 设置采样类型;
    format.setSampleType(QAudioFormat::SignedInt);
    input = new QAudioInput(format);
    output = new QAudioOutput(format);

    audioOutputIODevice = output->start();

}

/*
函数功能：udp接收音频
参数：无
返回值：无
*/
void ChatRoom::ReadyReadAudio()
{
    AudioPackage pack;
    memset(&pack,0,sizeof(AudioPackage));
    socketRdaudio->readDatagram((char*)&pack,sizeof(AudioPackage));
    if(stop==false){
        audioOutputIODevice->write(pack.data,pack.datalen);
    }
}

/*
函数功能：音频按钮信号槽
参数：无
返回值：无
*/
void ChatRoom::captureDataFromDevice()
{
    AudioPackage pack;
    memset(&pack,0,sizeof(AudioPackage));
    pack.datalen = audioInputIODevice->read(pack.data,1024);
    socketWrite->writeDatagram((char*)&pack,
                               sizeof(AudioPackage),
                               groupAddress1,
                               6666);
    audioOutputIODevice->write(pack.data,pack.datalen);
}
/*
函数功能：音频按钮
参数：无
返回值：无
*/
void ChatRoom::on_audio_clicked()
{
    if(user.flag != MASTER){
        QMessageBox::warning (this, "警告", "只有房主可以开启语音");
        return;
    }
    static int fv = -1;
    if(fv == -1){
        user.type = AUDIO;      //开启音频

        socket->write((char*)&user, sizeof(user));
        audioInputIODevice = input->start();
        connect(audioInputIODevice,SIGNAL(readyRead()),
                this,SLOT(captureDataFromDevice()));

        fv *= -1;
    }
    else if(fv == 1){        //关闭音频
        user.type = UNAUDIO;
        input->stop();
        socket->write((char*)&user, sizeof(user));

        fv *= -1;
    }
}

void ChatRoom::onsigAudio(user_t user)
{
    ui->audioinput->show();
}

void ChatRoom::onsigunAudio(user_t user)
{
    ui->audioinput->hide();
}


/*
函数功能：刚进入聊天室时告诉服务器
参数：无
返回值：无
*/
void ChatRoom::showChatList()
{
    user.type = CHATNAME;
    socket->write ((char*)&user, sizeof(user_t));
}


/*
函数功能：刚进入聊天室时加入用户列表
参数：user_t user
返回值：无
*/
void ChatRoom::onsigChatName (user_t user)
{
    QString chatName = QString::fromLocal8Bit (user.username);
    if(chatName == curRoom){
        chatName += "(房主)";
    }
    QListWidgetItem *item = new QListWidgetItem(chatName, ui->listWidget);
    ui->listWidget->addItem (item);
    QString sysInfo = "\n[系统消息：]";
    sysInfo += chatName;
    sysInfo += "已加入聊天室\n";
    ui->textBrowser_2->setTextColor (QColor::fromRgb (255,0,0));
    ui->textBrowser_2->append (sysInfo);
    ui->textBrowser_2->setTextColor (QColor::fromRgb (0,0,0));
}


/*
函数功能：刷新按钮
参数：无
返回值：无
*/
void ChatRoom::on_chatlist_btn_clicked()
{
    ui->listWidget->clear ();
    user.type = CHATLIST;
    socket->write((char*)&user, sizeof(user));
}


/*
函数功能：显示聊天列表
参数：user_t user
返回值：无
*/
void ChatRoom::onsigChatList (user_t user)
{
    QString chatName = QString::fromLocal8Bit (user.chatname);
    if(chatName == curRoom){
        chatName += "(房主)";
    }
    QListWidgetItem *item = new QListWidgetItem( chatName, ui->listWidget);
    ui->listWidget->addItem (item);
}

/*
函数功能：发送消息按钮
参数：无
返回值：无
*/
void ChatRoom::on_send_clicked()    //文字聊天
{
    QString text = ui->textEdit->toPlainText ();
    if(text.isEmpty ()){
        QMessageBox::warning (this, "提示","内容不可为空");
        return;
    }
    QByteArray ba_text = text.toLocal8Bit ();
    char* c_text = ba_text.data ();
    strncpy(user.data, c_text, sizeof(user.data));
    if(ui->textscroll->isHidden()){ //如果弹幕屏是隐藏的为真，说明发过去的是文本信息
        user.type = TEXT;
    }
    else{   //否则发过去的就是弹幕
        user.type = BS;
    }
    ui->textEdit->clear ();
    socket->write((char*)&user, sizeof(user));
}


/*
函数功能：返回文字消息处理
参数：user_t user
返回值：无
*/
void ChatRoom::onsigChatText(user_t user)
{
    QString room = QString::fromLocal8Bit (user.roomName);

    QDateTime dt = QDateTime::currentDateTime ();
    QString str_head = QString::fromLocal8Bit (user.username);
    str_head += " ";
    str_head += dt.toString ("yyyy/MM/dd hh:mm:ss");
    QString str_body = "  ";
    str_body += QString::fromLocal8Bit (user.data);
    static int flag = -1;
    if(flag == -1){
        ui->textBrowser_2->setTextColor (QColor::fromRgb (50,205,50));
        flag *= -1;
    }
    else if(flag == 1){
        ui->textBrowser_2->setTextColor (QColor::fromRgb (0,0,255));
        flag *= -1;
    }
    ui->textBrowser_2->append (str_head);
    ui->textBrowser_2->setTextColor (QColor::fromRgb (0,0,0));
    ui->textBrowser_2->append (str_body);
}


/*
函数功能：关闭聊天室
参数：QCloseEvent *
返回值：无
*/
void ChatRoom::closeEvent (QCloseEvent *)
{
    RoomManager *rm = RoomManager::getInstance ();
    QString room = QString::fromLocal8Bit (user.roomName);
    rm->eraseRoom (room);

    user.type = QUIT;
    socket->write((char*)&user, sizeof(user));
}


/*
函数功能：房主退出客户端通知其他人退出房间
参数：user_t user
返回值：无
*/
void ChatRoom::onsigMasterExit(user_t user)
{
    QMessageBox::warning(this, "警告", "房主已经下线，房间将暂时关闭，谢谢配合");
    this->close();
}


/*
函数功能：弹幕按钮
参数：无
返回值：无
*/
void ChatRoom::on_bs_clicked()
{
    static int bs = -1;
    if(bs == -1){

        ui->textscroll->show ();
        bs *= -1;
    }
    else if(bs == 1){
        ui->textscroll->hide ();
        bs *= -1;
    }
}

/*
函数功能：弹幕处理
参数：user_t user
返回值：无
*/
void ChatRoom::onsigBs (user_t user)
{
    QString bs_text = QString::fromLocal8Bit(user.data);

    label = new QLabel(bs_text, ui->textscroll);
    label->setStyleSheet("color:red");
    label->setFont(QFont("Timers", 28 , QFont::Bold));
    int len = qrand()% ui->textBrowser->height() + 0;//纵坐标为随机值
    label->move(0, len);
    label->adjustSize(); //设置label大小自适应字体长度
    timer->start(10);
}


/*
函数功能：定时器事件
参数：无
返回值：无
*/
void ChatRoom::onTimeOut()
{
    const QPoint& p = label->pos();
    if(p.x() < (ui->textBrowser->width())){
        label->move(p.x() + 1, p.y());
        label->show();
        label->update();
    }
    else{
        label->hide();
    }
}

/*
函数功能：送礼按钮
参数：无
返回值：无
*/
void ChatRoom::on_gift_clicked()
{
    QMessageBox::information(this, "提示","请联系超哥充值人民币");
}


ChatRoom::~ChatRoom()
{
    delete ui;
}
/*
函数功能：按enter发送信息
参数：QObject *obj, QEvent *ev
返回值：bool
*/
bool ChatRoom::eventFilter(QObject *obj, QEvent *ev)
{
    if(obj == ui->textEdit){
        //是否是键盘事件
        if(ev->type() == QEvent::KeyPress){
            //将QEvent*类型转化为QKeyEvent*
            QKeyEvent *keyEvent = dynamic_cast<QKeyEvent*>(ev);
            //判定是否是大键盘上的enter
            if(keyEvent->key() == Qt::Key_Return){
                ChatRoom::on_send_clicked();    //执行发送按钮事件
            }else{
                //继续转发
                return false;
            }
        }else{
            return false;
        }
    }else{
        return ChatRoom::eventFilter(obj, ev);
    }
}

