#ifndef SECOND_H
#define SECOND_H

#include <QWidget>
#include <QPushButton>

class Second : public QWidget
{
    Q_OBJECT
public:
    explicit Second(QWidget *first
                    , QWidget *parent = nullptr);

signals:

public slots:
    void showFirst();

private:
    QPushButton *m_pFirst;
    QWidget *m_pFirstInterface;
};

#endif // SECOND_H
