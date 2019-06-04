#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QUdpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void recvMsg();

private:
    Ui::Widget *ui;
    QUdpSocket *m_pUdpSocket;
};

#endif // WIDGET_H
