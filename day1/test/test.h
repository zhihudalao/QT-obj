#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Test : public QWidget
{
    Q_OBJECT

public:
    Test(QWidget *parent = 0);
    ~Test();

public slots:
    void handleUpdate();

private:
    QLabel *m_pMapLab;
    QPushButton *m_pUpdatePB;
};

#endif // TEST_H
