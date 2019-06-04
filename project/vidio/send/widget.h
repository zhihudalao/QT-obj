#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>
#include <QCameraViewfinderSettings>
#include <QVideoWidget>
#include <QTimer>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QUdpSocket>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void sendMap(int id, QImage img);
    void changeSendStatus();

private:
    QVideoWidget *m_pVideoWidget;
    QCamera *m_camera;
    QCameraViewfinder *m_viewfinder;
    QCameraImageCapture *m_capture;
    QTimer *m_pTimer;
    QPushButton *m_pSendPB;
    bool m_bSend;
    QLabel *m_pShowMapLab;
    QUdpSocket *m_pUdpSocket;
};

#endif // WIDGET_H
