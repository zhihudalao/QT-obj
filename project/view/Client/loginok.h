#ifndef LOGINOK_H
#define LOGINOK_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class LoginOk : public QWidget
{
    Q_OBJECT
public:
    explicit LoginOk(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel *m_pMapLab;
};

#endif // LOGINOK_H
