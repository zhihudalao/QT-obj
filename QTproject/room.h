#ifndef ROOM_H
#define ROOM_H

#include <QWidget>
#include "package.h"
#include "videosurface.h"
#include <QTcpSocket>
#include <QCamera>
#include <QUdpSocket>
#include <QtNetwork/qtnetworkglobal.h>
#include <QtCore/qiodevice.h>
#include <QtCore/qobject.h>
#include <QCameraViewfinder>
#include <QAudio>
#include <QAudioFormat>
#include <QAudioInput>
#include <QAudioOutput>
#include <QAudioDeviceInfo>
#include <QString>

struct AudioPackage
{
    char data[1024];
    int dataLen;
};

namespace Ui {
class room;
}

class room : public QWidget
{
    Q_OBJECT

public:
    explicit room(QWidget *parent = 0);
    room (QTcpSocket* clientSocket,QWidget* parent=0);
    ~room();
    void wordshow(const pack_t &pack);
    void broadshow(const pack_t &pack);

    void copen();
    void cclose();
    QCamera* m_QCamera;
    quint16 getprot();
    void srtprot(const quint16 R_prot);
    void setroomName(QString roomName);
    void setprot(quint16 R_prot);
    void DK();

    void udpAudio();//udp音频协议

    void sound_open();

    void sound_close();

private slots:
    void on_renew_btn_clicked();

    void on_send_btn_clicked();


    void readyreadSlot();
    void on_video_on_btn_clicked();

    void on_video_off_btn_clicked();

    void frameChangedSlot(QVideoFrame);

    void ReadyReadAudio();//音频槽函数
    void on_sound_on_btn_clicked();

    void captureDataFromDevice();

    void on_sound_off_btn_clicked();



    //void sound_close();

signals:
    room_renew();
    void room_send(QString);

    onCamera();//开摄像头

    outCamera();//关摄像头

    soundopen();//开录音

    soundclose();//关录音
private:
    Ui::room *ui;
    QTcpSocket* clientSocket;
    char name[20];
    char message[20];
    QCamera* camera;
    videosurface* vs;
    QString roomName;

    videosurface* m_videoSurface;

    QUdpSocket* m_write;
    QUdpSocket* m_ready;
    quint16 R_prot;//端口

    QAudioInput* input;
    QAudioOutput* output;
    QIODevice *inputdevice;
    QIODevice *outputdevice;

    QUdpSocket* m_writeAudio;
    QUdpSocket* m_readAudio;

    QUdpSocket* socketWrite;
    bool stop;
};

#endif // ROOM_H
