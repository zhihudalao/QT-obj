/********************************************************************************
** Form generated from reading UI file 'receive.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVE_H
#define UI_RECEIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_receive
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *receive)
    {
        if (receive->objectName().isEmpty())
            receive->setObjectName(QStringLiteral("receive"));
        receive->resize(400, 300);
        menuBar = new QMenuBar(receive);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        receive->setMenuBar(menuBar);
        mainToolBar = new QToolBar(receive);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        receive->addToolBar(mainToolBar);
        centralWidget = new QWidget(receive);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        receive->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(receive);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        receive->setStatusBar(statusBar);

        retranslateUi(receive);

        QMetaObject::connectSlotsByName(receive);
    } // setupUi

    void retranslateUi(QMainWindow *receive)
    {
        receive->setWindowTitle(QApplication::translate("receive", "receive", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class receive: public Ui_receive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVE_H
