#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QUdpSocket>
#include <QAudio>
#include <QAudioInput>
#include <QAudioOutput>
#include <QAudioFormat>
#include <QIODevice>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QUdpSocket *udpsocket;

    struct video{
        char data[1024];
        int lens;
    };
    QAudioOutput *output;
    QIODevice *outputDevice;

private slots:
    void readyReadSlot();

};


#endif // MAINWINDOW_H
