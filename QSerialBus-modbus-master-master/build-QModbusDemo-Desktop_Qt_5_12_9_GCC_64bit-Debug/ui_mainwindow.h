/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QComboBox *comboBox_serialName;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QComboBox *comboBox_parity;
    QComboBox *comboBox_baudRate;
    QPushButton *pushButton_connect;
    QComboBox *comboBox_stopBit;
    QComboBox *comboBox_dataBit;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_read;
    QPushButton *pushButton_send;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(757, 427);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        comboBox_serialName = new QComboBox(centralWidget);
        comboBox_serialName->setObjectName(QString::fromUtf8("comboBox_serialName"));

        gridLayout->addWidget(comboBox_serialName, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        comboBox_parity = new QComboBox(centralWidget);
        comboBox_parity->addItem(QString());
        comboBox_parity->addItem(QString());
        comboBox_parity->addItem(QString());
        comboBox_parity->addItem(QString());
        comboBox_parity->addItem(QString());
        comboBox_parity->setObjectName(QString::fromUtf8("comboBox_parity"));

        gridLayout->addWidget(comboBox_parity, 4, 1, 1, 1);

        comboBox_baudRate = new QComboBox(centralWidget);
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->setObjectName(QString::fromUtf8("comboBox_baudRate"));

        gridLayout->addWidget(comboBox_baudRate, 2, 1, 1, 1);

        pushButton_connect = new QPushButton(centralWidget);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        pushButton_connect->setMinimumSize(QSize(150, 50));

        gridLayout->addWidget(pushButton_connect, 6, 1, 1, 1);

        comboBox_stopBit = new QComboBox(centralWidget);
        comboBox_stopBit->addItem(QString());
        comboBox_stopBit->addItem(QString());
        comboBox_stopBit->addItem(QString());
        comboBox_stopBit->setObjectName(QString::fromUtf8("comboBox_stopBit"));

        gridLayout->addWidget(comboBox_stopBit, 5, 1, 1, 1);

        comboBox_dataBit = new QComboBox(centralWidget);
        comboBox_dataBit->addItem(QString());
        comboBox_dataBit->addItem(QString());
        comboBox_dataBit->addItem(QString());
        comboBox_dataBit->addItem(QString());
        comboBox_dataBit->setObjectName(QString::fromUtf8("comboBox_dataBit"));

        gridLayout->addWidget(comboBox_dataBit, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 1, 1, 1);

        pushButton_read = new QPushButton(centralWidget);
        pushButton_read->setObjectName(QString::fromUtf8("pushButton_read"));

        gridLayout->addWidget(pushButton_read, 7, 1, 1, 1);

        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));

        gridLayout->addWidget(pushButton_send, 8, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 757, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        comboBox_baudRate->setCurrentIndex(7);
        comboBox_dataBit->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        label->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        comboBox_parity->setItemText(0, QApplication::translate("MainWindow", "No", nullptr));
        comboBox_parity->setItemText(1, QApplication::translate("MainWindow", "Even", nullptr));
        comboBox_parity->setItemText(2, QApplication::translate("MainWindow", "Odd", nullptr));
        comboBox_parity->setItemText(3, QApplication::translate("MainWindow", "Space", nullptr));
        comboBox_parity->setItemText(4, QApplication::translate("MainWindow", "Mark", nullptr));

        comboBox_baudRate->setItemText(0, QApplication::translate("MainWindow", "1200", nullptr));
        comboBox_baudRate->setItemText(1, QApplication::translate("MainWindow", "2400", nullptr));
        comboBox_baudRate->setItemText(2, QApplication::translate("MainWindow", "4800", nullptr));
        comboBox_baudRate->setItemText(3, QApplication::translate("MainWindow", "9600", nullptr));
        comboBox_baudRate->setItemText(4, QApplication::translate("MainWindow", "19200", nullptr));
        comboBox_baudRate->setItemText(5, QApplication::translate("MainWindow", "38400", nullptr));
        comboBox_baudRate->setItemText(6, QApplication::translate("MainWindow", "57600", nullptr));
        comboBox_baudRate->setItemText(7, QApplication::translate("MainWindow", "115200", nullptr));

        comboBox_baudRate->setCurrentText(QApplication::translate("MainWindow", "115200", nullptr));
        pushButton_connect->setText(QApplication::translate("MainWindow", "\345\273\272\347\253\213\350\277\236\346\216\245", nullptr));
        comboBox_stopBit->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        comboBox_stopBit->setItemText(1, QApplication::translate("MainWindow", "1.5", nullptr));
        comboBox_stopBit->setItemText(2, QApplication::translate("MainWindow", "2", nullptr));

        comboBox_dataBit->setItemText(0, QApplication::translate("MainWindow", "5", nullptr));
        comboBox_dataBit->setItemText(1, QApplication::translate("MainWindow", "6", nullptr));
        comboBox_dataBit->setItemText(2, QApplication::translate("MainWindow", "7", nullptr));
        comboBox_dataBit->setItemText(3, QApplication::translate("MainWindow", "8", nullptr));

        pushButton_read->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\345\257\204\345\255\230\345\231\250", nullptr));
        pushButton_send->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245\345\257\204\345\255\230\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
