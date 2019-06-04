#ifndef SECOND_H
#define SECOND_H

#include <QWidget>
#include <QTextEdit>
#include <QHBoxLayout>

class Second : public QWidget
{
    Q_OBJECT
public:
    explicit Second(QWidget *parent = nullptr);

signals:

public slots:
    void recvMsg(QString msg);

private:
    QTextEdit *m_pDataTE;
};

#endif // SECOND_H
