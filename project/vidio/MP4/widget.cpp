#include "widget.h"
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("QCamera");
    m_pCamera = new QCamera(this);
    m_pViewfinder = new QCameraViewfinder(this);
    m_pImageCapture = new QCameraImageCapture(m_pCamera);
    QPushButton* button1 = new QPushButton("Capture");
    QPushButton* button2 = new QPushButton("Exit");
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(m_pViewfinder);
    mainLayout->addWidget(button1);
    mainLayout->addWidget(button2);
    connect(button1, SIGNAL(clicked()), m_pImageCapture, SLOT(capture()));
    connect(button2, SIGNAL(clicked()), this, SLOT(exitBtnResponded()));
    connect(m_pImageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(cameraImageCaptured(int,QImage)));
    m_pImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    m_pCamera->setCaptureMode(QCamera::CaptureStillImage);
    m_pCamera->setViewfinder(m_pViewfinder);
    m_pCamera->start();

}

Widget::~Widget()
{
    delete       m_pCamera;
    delete   m_pViewfinder;
    delete m_pImageCapture;
}

void Widget::exitBtnResponded()
{
    m_pCamera->stop();
    close();
}

void Widget::cameraImageCaptured(int, QImage image)
{
    QString savepath = QFileDialog::getSaveFileName(this,"Save Capture","Capture","Image png(*.png);;Image jpg(*.jpg);;Image bmp(*.bmp)");
    if(!savepath.isEmpty()){
        image.save(savepath);
    }
}
