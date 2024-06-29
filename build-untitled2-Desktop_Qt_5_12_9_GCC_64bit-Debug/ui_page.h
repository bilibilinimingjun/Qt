/********************************************************************************
** Form generated from reading UI file 'page.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_H
#define UI_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Page
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Page)
    {
        if (Page->objectName().isEmpty())
            Page->setObjectName(QString::fromUtf8("Page"));
        Page->resize(400, 300);
        gridLayout = new QGridLayout(Page);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(Page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(Page);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(Page);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);


        retranslateUi(Page);

        QMetaObject::connectSlotsByName(Page);
    } // setupUi

    void retranslateUi(QDialog *Page)
    {
        Page->setWindowTitle(QApplication::translate("Page", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("Page", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("Page", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("Page", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Page: public Ui_Page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_H
