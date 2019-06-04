#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void exitBtnResponded();
    void cameraImageCaptured(int,QImage);
private:
    QCamera*             m_pCamera;       //读取摄像头
    QCameraViewfinder*   m_pViewfinder;   //渲染摄像头
    QCameraImageCapture* m_pImageCapture; //获取摄像头当前帧

};

#endif // WIDGET_H
