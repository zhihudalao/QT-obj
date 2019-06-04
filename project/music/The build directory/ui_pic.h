/********************************************************************************
** Form generated from reading UI file 'pic.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIC_H
#define UI_PIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pic
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QLabel *map_lab;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *pic)
    {
        if (pic->objectName().isEmpty())
            pic->setObjectName(QStringLiteral("pic"));
        pic->resize(500, 630);
        pic->setMinimumSize(QSize(500, 500));
        pic->setMaximumSize(QSize(1000, 1000));
        centralWidget = new QWidget(pic);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        map_lab = new QLabel(centralWidget);
        map_lab->setObjectName(QStringLiteral("map_lab"));
        map_lab->setMinimumSize(QSize(300, 300));
        map_lab->setMaximumSize(QSize(300, 300));
        map_lab->setPixmap(QPixmap(QString::fromUtf8("../../../1.jpg")));
        map_lab->setScaledContents(true);

        verticalLayout->addWidget(map_lab);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font;
        font.setFamily(QStringLiteral("AcadEref"));
        font.setPointSize(20);
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pic->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(pic);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 26));
        pic->setMenuBar(menuBar);
        mainToolBar = new QToolBar(pic);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        pic->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(pic);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        pic->setStatusBar(statusBar);

        retranslateUi(pic);

        QMetaObject::connectSlotsByName(pic);
    } // setupUi

    void retranslateUi(QMainWindow *pic)
    {
        pic->setWindowTitle(QApplication::translate("pic", "pic", Q_NULLPTR));
        map_lab->setText(QString());
        pushButton->setText(QApplication::translate("pic", "\346\233\264\346\226\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pic: public Ui_pic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIC_H
