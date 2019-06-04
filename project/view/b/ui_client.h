/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLient
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *name_le;
    QLineEdit *pwd_le;
    QPushButton *login_pb;
    QPushButton *regist_pb;

    void setupUi(QWidget *CLient)
    {
        if (CLient->objectName().isEmpty())
            CLient->setObjectName(QStringLiteral("CLient"));
        CLient->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(CLient);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        name_le = new QLineEdit(CLient);
        name_le->setObjectName(QStringLiteral("name_le"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(20);
        name_le->setFont(font);

        verticalLayout->addWidget(name_le);

        pwd_le = new QLineEdit(CLient);
        pwd_le->setObjectName(QStringLiteral("pwd_le"));
        pwd_le->setFont(font);
        pwd_le->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(pwd_le);

        login_pb = new QPushButton(CLient);
        login_pb->setObjectName(QStringLiteral("login_pb"));
        login_pb->setFont(font);

        verticalLayout->addWidget(login_pb);

        regist_pb = new QPushButton(CLient);
        regist_pb->setObjectName(QStringLiteral("regist_pb"));
        regist_pb->setFont(font);

        verticalLayout->addWidget(regist_pb);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CLient);

        QMetaObject::connectSlotsByName(CLient);
    } // setupUi

    void retranslateUi(QWidget *CLient)
    {
        CLient->setWindowTitle(QApplication::translate("CLient", "CLient", Q_NULLPTR));
        login_pb->setText(QApplication::translate("CLient", "\347\231\273\345\275\225", Q_NULLPTR));
        regist_pb->setText(QApplication::translate("CLient", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CLient: public Ui_CLient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
