/********************************************************************************
** Form generated from reading UI file 'usrinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRINFO_H
#define UI_USRINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsrInfo
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QTextEdit *textEdit;

    void setupUi(QWidget *UsrInfo)
    {
        if (UsrInfo->objectName().isEmpty())
            UsrInfo->setObjectName(QStringLiteral("UsrInfo"));
        UsrInfo->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(UsrInfo);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(UsrInfo);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(UsrInfo);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(20);
        lineEdit->setFont(font1);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(UsrInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        textEdit = new QTextEdit(UsrInfo);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setFont(font1);

        verticalLayout->addWidget(textEdit);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(UsrInfo);

        QMetaObject::connectSlotsByName(UsrInfo);
    } // setupUi

    void retranslateUi(QWidget *UsrInfo)
    {
        UsrInfo->setWindowTitle(QApplication::translate("UsrInfo", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("UsrInfo", "\345\220\215\345\255\227\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("UsrInfo", "\350\257\264\346\230\216\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UsrInfo: public Ui_UsrInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRINFO_H
