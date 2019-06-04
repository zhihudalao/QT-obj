#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include "tubeandtrain.h"
#include <QTextEdit>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void out(QString msg);

private:
    QTextEdit *m_pOutTE;
};

#endif // WIDGET_H
