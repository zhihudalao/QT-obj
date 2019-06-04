#include "widget.h"
#include <QBuffer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(1000, 900);

    m_bSend = false;
    m_pTimer = new QTimer;
    /******************************/
    m_pVideoWidget = new QVideoWidget;
    m_camera = new QCamera;
    m_viewfinder = new QCameraViewfinder(m_pVideoWidget);
    m_capture = new QCameraImageCapture(m_camera);

//    QCameraViewfinderSettings viewFinderSettings;
//    viewFinderSettings.setResolution(800, 600);  //设置分辨率
//    m_camera->setViewfinderSettings(viewFinderSettings);


    m_camera->setViewfinder(m_viewfinder);//设置取景器
    m_camera->setCaptureMode(QCamera::CaptureStillImage);
    m_camera->start();
    connect(m_pTimer, SIGNAL(timeout())
            ,m_capture , SLOT(capture()));
    connect(m_capture, SIGNAL(imageCaptured(int, QImage))
            , this, SLOT(sendMap(int,QImage)));
    /******************************/

    m_pSendPB = new QPushButton;
    m_pSendPB->setText("开始");
    connect(m_pSendPB, SIGNAL(clicked(bool))
            , this, SLOT(changeSendStatus()));

    m_pShowMapLab = new QLabel;
    QHBoxLayout *pMain = new QHBoxLayout(this);
    pMain->addWidget(m_pVideoWidget);
    pMain->addWidget(m_pShowMapLab);
    pMain->addWidget(m_pSendPB);

    m_pUdpSocket = new QUdpSocket(this);

}

Widget::~Widget()
{

}

void Widget::sendMap(int id, QImage img)
{
//    QPixmap pixmap = QPixmap::fromImage(img);
//    //放缩图片
//    QPixmap fitPixmap= pixmap.scaled(320,240,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
//    m_pShowMapLab->setPixmap(fitPixmap);

#if 1
    QPixmap pixmap = QPixmap::fromImage(img);
    QByteArray bytes;
    QBuffer buff(&bytes);
    buff.open(QIODevice::ReadWrite);
    pixmap.save(&buff, "JPG");

    m_pUdpSocket->writeDatagram(bytes, QHostAddress("127.0.0.1"), 8080);
#endif
}

void Widget::changeSendStatus()
{
    if (!m_bSend)
    {
        m_pTimer->start(200);
        m_bSend = true;
        m_pSendPB->setText("停止");
    }
    else
    {
        m_pTimer->stop();
        m_bSend = false;
        m_pSendPB->setText("开始");
    }
}
