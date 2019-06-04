/********************************************************************************
** Form generated from reading UI file 'homework.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWORK_H
#define UI_HOMEWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_homework
{
public:
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *homework)
    {
        if (homework->objectName().isEmpty())
            homework->setObjectName(QStringLiteral("homework"));
        homework->resize(400, 300);
        horizontalLayout = new QHBoxLayout(homework);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        retranslateUi(homework);

        QMetaObject::connectSlotsByName(homework);
    } // setupUi

    void retranslateUi(QWidget *homework)
    {
        homework->setWindowTitle(QApplication::translate("homework", "homework", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class homework: public Ui_homework {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWORK_H
