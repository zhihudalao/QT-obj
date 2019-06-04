#ifndef RECEIVE_H
#define RECEIVE_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QAudio>//一下这五个是QT处理音频的库
#include <QAudioFormat>
#include <QAudioInput>
#include <QAudioOutput>
#include <QIODevice>

using namespace std;

namespace Ui {
class receive;
}

class receive : public QMainWindow
{
    Q_OBJECT

public:
    explicit receive(QWidget *parent = 0);
    ~receive();

private:
    Ui::receive *ui;
    QUdpSocket *udpSocket;//用于音频信号的发送

    QAudioInput *input;
    QIODevice *inputDevice;

    struct video{
        char audiodata[1024];
        int lens;
    };

private slots:

    void onReadyRead();//

};

#endif // RECEIVE_H
