#ifndef CHATROOM_H
#define CHATROOM_H


#include"clientsocket.h"
#include"user.h"
#include"chatroom.h"

#include <QDialog>
#include<QTcpSocket>
#include<QCloseEvent>
#include<QListWidgetItem>
#include<QUdpSocket>
#include<QTcpSocket>
#include<QCamera>
#include<QCameraInfo>
#include<QHostAddress>
#include<QTimer>
#include<QLabel>
#include<QKeyEvent>
#include <QMultimedia>
#include <QFile>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioInput>
#include <QAudioOutput>
#include <QString>
#include <QCameraViewfinder>
#include <QCameraViewfinderSettings>
#include <QCameraImageCapture>

// 微秒转秒;
const qint64 TIME_TRANSFORM = 1000 * 1000;
struct AudioPackage{
    char data[1024];
    int datalen;
};

typedef struct imagePacke
{
    int width;//图片宽度
    int height;//图片高度
    int bytesPerline;//每行字节数
    bool isLastPack;
    int packTaken;
    char data[4096];

}ImagePackage;

namespace Ui {
class ChatRoom;
}

class ChatRoom : public QDialog
{
    Q_OBJECT

public:
    explicit ChatRoom(ClientSocket *cs, QTcpSocket *socket, QString curRoom,
                      user_t user, QWidget *parent = 0);
    ~ChatRoom();
    void udpVideo();    //udp视频协议
    void udpAudio();    //udp音频协议
    void showChatList();        //刚进聊天室自动添加到用户列表
    virtual bool eventFilter(QObject *obj, QEvent *ev); //按enter发送消息

protected:
    virtual void closeEvent (QCloseEvent *);//关闭事件
private slots:
    void onsigChatName(user_t user);//添加用户名到列表
    void onsigChatList(user_t user);//刷新列表
    void on_chatlist_btn_clicked();//刷新按钮
    void onsigMasterExit(user_t user);//房主退出
    void on_send_clicked();//发送信息
    void onsigChatText(user_t user);//文字聊天信息处理

    void on_video_clicked();//视频
    void onsigVideo(user_t user);//视频处理
    void onsigunVideo(user_t user);//关闭视频
    void UdpReadRead();//udp处理槽函数
    void onvideoChanged(QVideoFrame);//视频采集成图片

    void on_audio_clicked();//音频按钮
    void onsigAudio(user_t user);//音频处理
    void onsigunAudio(user_t user);//关闭音频
    void ReadyReadAudio();//音频udp处理槽函数
    void captureDataFromDevice();//音频采集

    void onTimeOut();//定时器槽函数
    void onsigBs(user_t user);//弹幕处理
    void on_bs_clicked();//弹幕按钮
    void on_gift_clicked();//送礼按钮

private:
    Ui::ChatRoom *ui;
    user_t user;
    QString curRoom;//保存当前房间名
    QTcpSocket *socket;
    ClientSocket *cs;

    QUdpSocket *socketWrite;//udp视频传输协议
    QUdpSocket *socketRead;
    QUdpSocket *socketWdaudio;//udp音频传输协议
    QUdpSocket *socketRdaudio;

    QHostAddress groupAddress;//udp视频组播
    QHostAddress groupAddress1;//upd音频组播

    QTimer    *m_time;



    QCamera *camera;
    QTimer *timer;
    QLabel *label;

    QAudioInput * input;
    QAudioOutput* output;
    QIODevice *audioInputIODevice;
    QIODevice *audioOutputIODevice;

    bool stop;
};

#endif // CHATROOM_H
