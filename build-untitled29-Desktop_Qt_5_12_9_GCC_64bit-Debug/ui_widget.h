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
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QCheckBox *checkBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        radioButton = new QRadioButton(Widget);
        buttonGroup_2 = new QButtonGroup(Widget);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(radioButton);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(50, 30, 211, 151));
        radioButton_2 = new QRadioButton(Widget);
        buttonGroup_2->addButton(radioButton_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(50, 200, 211, 171));
        radioButton_3 = new QRadioButton(Widget);
        buttonGroup = new QButtonGroup(Widget);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->setExclusive(false);
        buttonGroup->addButton(radioButton_3);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(300, 30, 211, 151));
        radioButton_4 = new QRadioButton(Widget);
        buttonGroup->addButton(radioButton_4);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(300, 200, 211, 171));
        radioButton_5 = new QRadioButton(Widget);
        buttonGroup->addButton(radioButton_5);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(300, 390, 211, 171));
        checkBox = new QCheckBox(Widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(570, 290, 131, 41));
        checkBox->setTristate(true);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(640, 50, 151, 221));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_4 = new QCheckBox(widget);
        buttonGroup_3 = new QButtonGroup(Widget);
        buttonGroup_3->setObjectName(QString::fromUtf8("buttonGroup_3"));
        buttonGroup_3->setExclusive(false);
        buttonGroup_3->addButton(checkBox_4);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setTristate(false);

        verticalLayout->addWidget(checkBox_4);

        checkBox_3 = new QCheckBox(widget);
        buttonGroup_3->addButton(checkBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setTristate(false);

        verticalLayout->addWidget(checkBox_3);

        checkBox_2 = new QCheckBox(widget);
        buttonGroup_3->addButton(checkBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setTristate(false);

        verticalLayout->addWidget(checkBox_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        radioButton->setText(QApplication::translate("Widget", "1", nullptr));
        radioButton_2->setText(QApplication::translate("Widget", "2", nullptr));
        radioButton_3->setText(QApplication::translate("Widget", "3", nullptr));
        radioButton_4->setText(QApplication::translate("Widget", "4", nullptr));
        radioButton_5->setText(QApplication::translate("Widget", "5", nullptr));
        checkBox->setText(QApplication::translate("Widget", "CheckBox", nullptr));
        checkBox_4->setText(QApplication::translate("Widget", "CheckBox", nullptr));
        checkBox_3->setText(QApplication::translate("Widget", "CheckBox", nullptr));
        checkBox_2->setText(QApplication::translate("Widget", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
