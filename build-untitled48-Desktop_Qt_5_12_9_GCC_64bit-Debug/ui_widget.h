/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *geometryWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QWidget *colorWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QWidget *opacityWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1024, 600);
        geometryWidget = new QWidget(Widget);
        geometryWidget->setObjectName(QString::fromUtf8("geometryWidget"));
        geometryWidget->setGeometry(QRect(210, 10, 211, 171));
        geometryWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	\n"
"	background-color: rgb(186, 189, 182);\n"
"}"));
        horizontalLayout = new QHBoxLayout(geometryWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(geometryWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        colorWidget = new QWidget(Widget);
        colorWidget->setObjectName(QString::fromUtf8("colorWidget"));
        colorWidget->setGeometry(QRect(210, 210, 211, 171));
        colorWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	\n"
"	background-color: rgb(114, 159, 207);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(colorWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(colorWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        opacityWidget = new QWidget(Widget);
        opacityWidget->setObjectName(QString::fromUtf8("opacityWidget"));
        opacityWidget->setGeometry(QRect(210, 410, 211, 171));
        opacityWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	\n"
"	background-color: rgb(138, 226, 52);\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(opacityWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(opacityWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(500, 50, 161, 201));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "geometry", nullptr));
        label_2->setText(QApplication::translate("Widget", "color", nullptr));
        label_3->setText(QApplication::translate("Widget", "666", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\345\207\240\344\275\225\345\212\250\347\224\273", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "\351\242\234\350\211\262\345\212\250\347\224\273", nullptr));
        pushButton_3->setText(QApplication::translate("Widget", "\344\270\215\351\200\217\346\230\216\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
