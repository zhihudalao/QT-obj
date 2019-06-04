#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Detail : public QWidget
{
    Q_OBJECT
public:
    explicit Detail(QWidget *parent = nullptr);

signals:

public slots:
private:
    QLabel *m_pAddrLab;
    QLineEdit *m_pAddrLE;

    QLabel *m_pAgeLab;
    QLineEdit *m_pAgeLE;
};

#endif // DETAIL_H
