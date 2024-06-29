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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton_openLed;
    QLabel *label_ledState;
    QPushButton *pushButton_closeLed;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 300);
        pushButton_openLed = new QPushButton(Widget);
        pushButton_openLed->setObjectName(QString::fromUtf8("pushButton_openLed"));
        pushButton_openLed->setGeometry(QRect(80, 150, 93, 28));
        label_ledState = new QLabel(Widget);
        label_ledState->setObjectName(QString::fromUtf8("label_ledState"));
        label_ledState->setGeometry(QRect(180, 70, 81, 31));
        label_ledState->setAlignment(Qt::AlignCenter);
        pushButton_closeLed = new QPushButton(Widget);
        pushButton_closeLed->setObjectName(QString::fromUtf8("pushButton_closeLed"));
        pushButton_closeLed->setGeometry(QRect(240, 150, 93, 28));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        pushButton_openLed->setText(QApplication::translate("Widget", "\344\272\256\347\201\257", nullptr));
        label_ledState->setText(QApplication::translate("Widget", "\347\201\257\347\212\266\346\200\201", nullptr));
        pushButton_closeLed->setText(QApplication::translate("Widget", "\345\205\263\347\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
