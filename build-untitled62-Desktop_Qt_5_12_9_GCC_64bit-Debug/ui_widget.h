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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *twStudent;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *cboHHeader;
    QCheckBox *cboVHeader;
    QCheckBox *cboAltemate;
    QCheckBox *cboEditCell;
    QPushButton *btnStyleSheet;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *rbCell;
    QRadioButton *rbRow;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *leName;
    QLabel *label_4;
    QLineEdit *leAge;
    QLabel *label;
    QLineEdit *leGender;
    QLineEdit *leProvince;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btnAppend;
    QPushButton *btnInsert;
    QPushButton *btnDelete;
    QPushButton *btnModify;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1024, 600);
        horizontalLayout_4 = new QHBoxLayout(Widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        twStudent = new QTableWidget(Widget);
        twStudent->setObjectName(QString::fromUtf8("twStudent"));
        twStudent->setAlternatingRowColors(true);

        horizontalLayout_4->addWidget(twStudent);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cboHHeader = new QCheckBox(Widget);
        cboHHeader->setObjectName(QString::fromUtf8("cboHHeader"));

        verticalLayout_2->addWidget(cboHHeader);

        cboVHeader = new QCheckBox(Widget);
        cboVHeader->setObjectName(QString::fromUtf8("cboVHeader"));

        verticalLayout_2->addWidget(cboVHeader);

        cboAltemate = new QCheckBox(Widget);
        cboAltemate->setObjectName(QString::fromUtf8("cboAltemate"));

        verticalLayout_2->addWidget(cboAltemate);

        cboEditCell = new QCheckBox(Widget);
        cboEditCell->setObjectName(QString::fromUtf8("cboEditCell"));

        verticalLayout_2->addWidget(cboEditCell);


        horizontalLayout_2->addLayout(verticalLayout_2);

        btnStyleSheet = new QPushButton(Widget);
        btnStyleSheet->setObjectName(QString::fromUtf8("btnStyleSheet"));

        horizontalLayout_2->addWidget(btnStyleSheet);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        rbCell = new QRadioButton(Widget);
        rbCell->setObjectName(QString::fromUtf8("rbCell"));

        verticalLayout_3->addWidget(rbCell);

        rbRow = new QRadioButton(Widget);
        rbRow->setObjectName(QString::fromUtf8("rbRow"));

        verticalLayout_3->addWidget(rbRow);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        leName = new QLineEdit(Widget);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 0, 1, 1, 1);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leAge = new QLineEdit(Widget);
        leAge->setObjectName(QString::fromUtf8("leAge"));

        gridLayout->addWidget(leAge, 2, 1, 1, 1);

        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        leGender = new QLineEdit(Widget);
        leGender->setObjectName(QString::fromUtf8("leGender"));

        gridLayout->addWidget(leGender, 1, 1, 1, 1);

        leProvince = new QLineEdit(Widget);
        leProvince->setObjectName(QString::fromUtf8("leProvince"));

        gridLayout->addWidget(leProvince, 3, 1, 1, 1);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnAppend = new QPushButton(Widget);
        btnAppend->setObjectName(QString::fromUtf8("btnAppend"));

        verticalLayout->addWidget(btnAppend);

        btnInsert = new QPushButton(Widget);
        btnInsert->setObjectName(QString::fromUtf8("btnInsert"));

        verticalLayout->addWidget(btnInsert);

        btnDelete = new QPushButton(Widget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));

        verticalLayout->addWidget(btnDelete);

        btnModify = new QPushButton(Widget);
        btnModify->setObjectName(QString::fromUtf8("btnModify"));

        verticalLayout->addWidget(btnModify);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout_4);

        horizontalLayout_4->setStretch(0, 2);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        cboHHeader->setText(QApplication::translate("Widget", "\350\241\214\350\241\250\345\244\264", nullptr));
        cboVHeader->setText(QApplication::translate("Widget", "\345\210\227\350\241\250\345\244\264", nullptr));
        cboAltemate->setText(QApplication::translate("Widget", "\344\272\244\346\233\277\350\203\214\346\231\257\350\211\262", nullptr));
        cboEditCell->setText(QApplication::translate("Widget", "\345\215\225\345\205\203\346\240\274\345\217\257\347\274\226\350\276\221", nullptr));
        btnStyleSheet->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\346\240\267\345\274\217\350\241\250", nullptr));
        rbCell->setText(QApplication::translate("Widget", "\351\200\211\346\213\251\345\215\225\345\205\203\346\240\274", nullptr));
        rbRow->setText(QApplication::translate("Widget", "\351\200\211\346\213\251\350\241\214", nullptr));
        label_3->setText(QApplication::translate("Widget", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_4->setText(QApplication::translate("Widget", "\347\261\215\350\264\257\357\274\232", nullptr));
        label->setText(QApplication::translate("Widget", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_2->setText(QApplication::translate("Widget", "\345\271\264\351\276\204\357\274\232", nullptr));
        btnAppend->setText(QApplication::translate("Widget", "\346\267\273\345\212\240\344\270\200\350\241\214", nullptr));
        btnInsert->setText(QApplication::translate("Widget", "\346\217\222\345\205\245\344\270\200\350\241\214", nullptr));
        btnDelete->setText(QApplication::translate("Widget", "\345\210\240\351\231\244\345\275\223\345\211\215\350\241\214", nullptr));
        btnModify->setText(QApplication::translate("Widget", "\344\277\256\346\224\271\345\275\223\345\211\215\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
