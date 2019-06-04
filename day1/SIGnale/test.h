#ifndef TEST_H
#define TEST_H

#include <QWidget>

namespace Ui {
class Test;
}

class Test : public QWidget
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = 0);
    ~Test();

private slots:
    void on_update_pb_clicked();

private:
    Ui::Test *ui;
};

#endif // TEST_H
