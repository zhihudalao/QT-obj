/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCommon;
    QAction *action_d;
    QAction *actionD;
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *btnBack;
    QPushButton *btnClear;
    QPushButton *btn7;
    QPushButton *btnMadd;
    QPushButton *btnMc;
    QPushButton *btn5;
    QPushButton *btn3;
    QPushButton *btn2;
    QPushButton *btnMs;
    QPushButton *btnFu;
    QPushButton *btn6;
    QPushButton *btn9;
    QPushButton *btn8;
    QPushButton *btn0;
    QPushButton *btnDot;
    QPushButton *btnLeft;
    QPushButton *btnRight;
    QPushButton *btn1;
    QPushButton *btnMr;
    QPushButton *btn4;
    QPushButton *btnDivi;
    QPushButton *btnMuti;
    QPushButton *btnSub;
    QPushButton *btnAdd;
    QPushButton *btnPow;
    QPushButton *btnMod;
    QPushButton *btnFac;
    QPushButton *btnEqual;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(360, 333);
        actionCommon = new QAction(MainWindow);
        actionCommon->setObjectName(QStringLiteral("actionCommon"));
        action_d = new QAction(MainWindow);
        action_d->setObjectName(QStringLiteral("action_d"));
        actionD = new QAction(MainWindow);
        actionD->setObjectName(QStringLiteral("actionD"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 341, 51));
        lineEdit->setReadOnly(false);
        btnBack = new QPushButton(centralWidget);
        btnBack->setObjectName(QStringLiteral("btnBack"));
        btnBack->setGeometry(QRect(20, 70, 101, 41));
        QFont font;
        font.setPointSize(10);
        btnBack->setFont(font);
        btnClear = new QPushButton(centralWidget);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setGeometry(QRect(130, 70, 91, 41));
        QFont font1;
        font1.setPointSize(11);
        btnClear->setFont(font1);
        btn7 = new QPushButton(centralWidget);
        btn7->setObjectName(QStringLiteral("btn7"));
        btn7->setGeometry(QRect(80, 120, 41, 31));
        btnMadd = new QPushButton(centralWidget);
        btnMadd->setObjectName(QStringLiteral("btnMadd"));
        btnMadd->setGeometry(QRect(20, 240, 51, 31));
        btnMc = new QPushButton(centralWidget);
        btnMc->setObjectName(QStringLiteral("btnMc"));
        btnMc->setGeometry(QRect(20, 120, 51, 31));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        btnMc->setFont(font2);
        btn5 = new QPushButton(centralWidget);
        btn5->setObjectName(QStringLiteral("btn5"));
        btn5->setGeometry(QRect(130, 160, 41, 31));
        btn3 = new QPushButton(centralWidget);
        btn3->setObjectName(QStringLiteral("btn3"));
        btn3->setGeometry(QRect(180, 200, 41, 31));
        btn2 = new QPushButton(centralWidget);
        btn2->setObjectName(QStringLiteral("btn2"));
        btn2->setGeometry(QRect(130, 200, 41, 31));
        btnMs = new QPushButton(centralWidget);
        btnMs->setObjectName(QStringLiteral("btnMs"));
        btnMs->setGeometry(QRect(20, 200, 51, 31));
        btnFu = new QPushButton(centralWidget);
        btnFu->setObjectName(QStringLiteral("btnFu"));
        btnFu->setGeometry(QRect(180, 240, 41, 31));
        btn6 = new QPushButton(centralWidget);
        btn6->setObjectName(QStringLiteral("btn6"));
        btn6->setGeometry(QRect(180, 160, 41, 31));
        btn9 = new QPushButton(centralWidget);
        btn9->setObjectName(QStringLiteral("btn9"));
        btn9->setGeometry(QRect(180, 120, 41, 31));
        btn8 = new QPushButton(centralWidget);
        btn8->setObjectName(QStringLiteral("btn8"));
        btn8->setGeometry(QRect(130, 120, 41, 31));
        btn0 = new QPushButton(centralWidget);
        btn0->setObjectName(QStringLiteral("btn0"));
        btn0->setGeometry(QRect(80, 240, 41, 31));
        btnDot = new QPushButton(centralWidget);
        btnDot->setObjectName(QStringLiteral("btnDot"));
        btnDot->setGeometry(QRect(130, 240, 41, 31));
        QFont font3;
        font3.setPointSize(14);
        btnDot->setFont(font3);
        btnLeft = new QPushButton(centralWidget);
        btnLeft->setObjectName(QStringLiteral("btnLeft"));
        btnLeft->setGeometry(QRect(230, 70, 51, 41));
        btnLeft->setFont(font);
        btnRight = new QPushButton(centralWidget);
        btnRight->setObjectName(QStringLiteral("btnRight"));
        btnRight->setGeometry(QRect(290, 70, 51, 41));
        btnRight->setFont(font);
        btn1 = new QPushButton(centralWidget);
        btn1->setObjectName(QStringLiteral("btn1"));
        btn1->setGeometry(QRect(80, 200, 41, 31));
        btnMr = new QPushButton(centralWidget);
        btnMr->setObjectName(QStringLiteral("btnMr"));
        btnMr->setGeometry(QRect(20, 160, 51, 31));
        btn4 = new QPushButton(centralWidget);
        btn4->setObjectName(QStringLiteral("btn4"));
        btn4->setGeometry(QRect(80, 160, 41, 31));
        btnDivi = new QPushButton(centralWidget);
        btnDivi->setObjectName(QStringLiteral("btnDivi"));
        btnDivi->setGeometry(QRect(230, 120, 51, 31));
        btnMuti = new QPushButton(centralWidget);
        btnMuti->setObjectName(QStringLiteral("btnMuti"));
        btnMuti->setGeometry(QRect(230, 160, 51, 31));
        btnSub = new QPushButton(centralWidget);
        btnSub->setObjectName(QStringLiteral("btnSub"));
        btnSub->setGeometry(QRect(230, 200, 51, 31));
        btnAdd = new QPushButton(centralWidget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setGeometry(QRect(230, 240, 51, 31));
        btnPow = new QPushButton(centralWidget);
        btnPow->setObjectName(QStringLiteral("btnPow"));
        btnPow->setGeometry(QRect(290, 120, 51, 31));
        btnMod = new QPushButton(centralWidget);
        btnMod->setObjectName(QStringLiteral("btnMod"));
        btnMod->setGeometry(QRect(290, 160, 51, 31));
        btnFac = new QPushButton(centralWidget);
        btnFac->setObjectName(QStringLiteral("btnFac"));
        btnFac->setGeometry(QRect(290, 200, 51, 31));
        btnEqual = new QPushButton(centralWidget);
        btnEqual->setObjectName(QStringLiteral("btnEqual"));
        btnEqual->setGeometry(QRect(290, 240, 51, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 360, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionCommon);
        menu->addAction(action_d);
        menu->addAction(actionD);
        menu->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionCommon->setText(QApplication::translate("MainWindow", "\346\231\256\351\200\232\345\236\213", 0));
        action_d->setText(QApplication::translate("MainWindow", "\347\247\221\345\255\246\345\236\213", 0));
        actionD->setText(QApplication::translate("MainWindow", "\347\250\213\345\272\217\345\221\230\345\236\213", 0));
        btnBack->setText(QApplication::translate("MainWindow", "Backspace", 0));
        btnClear->setText(QApplication::translate("MainWindow", "C", 0));
        btn7->setText(QApplication::translate("MainWindow", "7", 0));
        btnMadd->setText(QApplication::translate("MainWindow", "M+", 0));
        btnMc->setText(QApplication::translate("MainWindow", "MC", 0));
        btn5->setText(QApplication::translate("MainWindow", "5", 0));
        btn3->setText(QApplication::translate("MainWindow", "3", 0));
        btn2->setText(QApplication::translate("MainWindow", "2", 0));
        btnMs->setText(QApplication::translate("MainWindow", "MS", 0));
        btnFu->setText(QApplication::translate("MainWindow", "\302\261", 0));
        btn6->setText(QApplication::translate("MainWindow", "6", 0));
        btn9->setText(QApplication::translate("MainWindow", "9", 0));
        btn8->setText(QApplication::translate("MainWindow", "8", 0));
        btn0->setText(QApplication::translate("MainWindow", "0", 0));
        btnDot->setText(QApplication::translate("MainWindow", ".", 0));
        btnLeft->setText(QApplication::translate("MainWindow", "\357\274\210", 0));
        btnRight->setText(QApplication::translate("MainWindow", "\357\274\211", 0));
        btn1->setText(QApplication::translate("MainWindow", "1", 0));
        btnMr->setText(QApplication::translate("MainWindow", "MR", 0));
        btn4->setText(QApplication::translate("MainWindow", "4", 0));
        btnDivi->setText(QApplication::translate("MainWindow", "/", 0));
        btnMuti->setText(QApplication::translate("MainWindow", "*", 0));
        btnSub->setText(QApplication::translate("MainWindow", "-", 0));
        btnAdd->setText(QApplication::translate("MainWindow", "+", 0));
        btnPow->setText(QApplication::translate("MainWindow", "X^y", 0));
        btnMod->setText(QApplication::translate("MainWindow", "%", 0));
        btnFac->setText(QApplication::translate("MainWindow", "!", 0));
        btnEqual->setText(QApplication::translate("MainWindow", "=", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\237\245\347\234\213", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
