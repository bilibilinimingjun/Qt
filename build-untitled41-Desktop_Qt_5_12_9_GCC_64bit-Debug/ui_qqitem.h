/********************************************************************************
** Form generated from reading UI file 'qqitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QQITEM_H
#define UI_QQITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QQitem
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QLabel *icon;
    QLabel *phone;
    QLabel *name;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *QQitem)
    {
        if (QQitem->objectName().isEmpty())
            QQitem->setObjectName(QString::fromUtf8("QQitem"));
        QQitem->resize(350, 60);
        layoutWidget = new QWidget(QQitem);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 351, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(layoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(48, 48));
        widget->setMaximumSize(QSize(48, 48));
        icon = new QLabel(widget);
        icon->setObjectName(QString::fromUtf8("icon"));
        icon->setGeometry(QRect(0, 0, 48, 48));
        icon->setMinimumSize(QSize(48, 48));
        icon->setMaximumSize(QSize(48, 48));
        icon->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: rgb(238, 238, 236);\n"
"}"));
        phone = new QLabel(widget);
        phone->setObjectName(QString::fromUtf8("phone"));
        phone->setGeometry(QRect(20, 20, 25, 25));
        phone->setMinimumSize(QSize(25, 25));
        phone->setMaximumSize(QSize(25, 25));
        phone->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	\n"
"}"));

        horizontalLayout->addWidget(widget);

        name = new QLabel(layoutWidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color: rgb(136, 138, 133);\n"
"	font-size: 20px;\n"
"}"));

        horizontalLayout->addWidget(name);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(QQitem);

        QMetaObject::connectSlotsByName(QQitem);
    } // setupUi

    void retranslateUi(QWidget *QQitem)
    {
        QQitem->setWindowTitle(QApplication::translate("QQitem", "Form", nullptr));
        icon->setText(QString());
        phone->setText(QString());
        name->setText(QApplication::translate("QQitem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QQitem: public Ui_QQitem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QQITEM_H
