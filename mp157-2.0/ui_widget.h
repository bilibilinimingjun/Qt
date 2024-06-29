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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QComboBox *comboBox_dataBit;
    QComboBox *comboBox_parity;
    QLineEdit *lineEdit_num;
    QLabel *label_9;
    QComboBox *comboBox_serialName;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QComboBox *comboBox_baudRate;
    QPushButton *pushButton_read;
    QLabel *label;
    QLabel *label_5;
    QComboBox *comboBox_stopBit;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_connect;
    QLabel *label_11;
    QLineEdit *lineEdit_addrRead;
    QLabel *label_2;
    QLabel *label_6;
    QLineEdit *lineEdit_id;
    QSpacerItem *verticalSpacer_3;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_data;
    QLabel *label_10;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_addrWrite;
    QPushButton *pushButton_send;
    QLabel *label_8;
    QPushButton *pushButton_disclean;
    QTextEdit *textEdit_2;
    QWidget *tab_2;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_7;
    QWidget *tab_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1024, 600);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, -7, 1031, 611));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(layoutWidget);
        QFont font;
        font.setPointSize(15);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setFont(font);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setFont(font);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setFont(font);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMaximumSize(QSize(200, 16777215));
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setStyleSheet(QString::fromUtf8("QListView {\n"
"		background-color: rgb(211, 215, 207);\n"
"		border: none;\n"
"}\n"
"\n"
"QListView::item {\n"
"		height: 50px;\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"		background-color: rgb(255, 255, 255);\n"
"		color: black;\n"
"}"));

        horizontalLayout->addWidget(listWidget);

        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget {\n"
"		border: none;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"		width: 0px;\n"
"		height: opx;\n"
"}"));
        tabWidget->setTabsClosable(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setStyleSheet(QString::fromUtf8("QWidget{\n"
"		background-color: rgb(211, 215, 207);\n"
"}"));
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 801, 571));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox_dataBit = new QComboBox(layoutWidget1);
        comboBox_dataBit->addItem(QString());
        comboBox_dataBit->addItem(QString());
        comboBox_dataBit->addItem(QString());
        comboBox_dataBit->addItem(QString());
        comboBox_dataBit->setObjectName(QString::fromUtf8("comboBox_dataBit"));

        gridLayout->addWidget(comboBox_dataBit, 2, 1, 1, 1);

        comboBox_parity = new QComboBox(layoutWidget1);
        comboBox_parity->addItem(QString());
        comboBox_parity->addItem(QString());
        comboBox_parity->addItem(QString());
        comboBox_parity->addItem(QString());
        comboBox_parity->addItem(QString());
        comboBox_parity->setObjectName(QString::fromUtf8("comboBox_parity"));

        gridLayout->addWidget(comboBox_parity, 3, 1, 1, 1);

        lineEdit_num = new QLineEdit(layoutWidget1);
        lineEdit_num->setObjectName(QString::fromUtf8("lineEdit_num"));

        gridLayout->addWidget(lineEdit_num, 9, 1, 1, 1);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 9, 0, 1, 1);

        comboBox_serialName = new QComboBox(layoutWidget1);
        comboBox_serialName->setObjectName(QString::fromUtf8("comboBox_serialName"));

        gridLayout->addWidget(comboBox_serialName, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 11, 1, 1, 1);

        comboBox_baudRate = new QComboBox(layoutWidget1);
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->setObjectName(QString::fromUtf8("comboBox_baudRate"));

        gridLayout->addWidget(comboBox_baudRate, 1, 1, 1, 1);

        pushButton_read = new QPushButton(layoutWidget1);
        pushButton_read->setObjectName(QString::fromUtf8("pushButton_read"));
        pushButton_read->setMinimumSize(QSize(150, 25));

        gridLayout->addWidget(pushButton_read, 10, 1, 1, 1);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        comboBox_stopBit = new QComboBox(layoutWidget1);
        comboBox_stopBit->addItem(QString());
        comboBox_stopBit->addItem(QString());
        comboBox_stopBit->addItem(QString());
        comboBox_stopBit->setObjectName(QString::fromUtf8("comboBox_stopBit"));

        gridLayout->addWidget(comboBox_stopBit, 4, 1, 1, 1);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        gridLayout->addLayout(horizontalLayout_2, 6, 0, 1, 1);

        pushButton_connect = new QPushButton(layoutWidget1);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_connect->sizePolicy().hasHeightForWidth());
        pushButton_connect->setSizePolicy(sizePolicy);
        pushButton_connect->setMinimumSize(QSize(150, 50));

        gridLayout->addWidget(pushButton_connect, 6, 1, 1, 1);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 8, 0, 1, 1);

        lineEdit_addrRead = new QLineEdit(layoutWidget1);
        lineEdit_addrRead->setObjectName(QString::fromUtf8("lineEdit_addrRead"));

        gridLayout->addWidget(lineEdit_addrRead, 8, 1, 1, 1);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        lineEdit_id = new QLineEdit(layoutWidget1);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));

        gridLayout->addWidget(lineEdit_id, 5, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 7, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);
        gridLayout->setRowStretch(4, 1);
        gridLayout->setRowStretch(5, 3);
        gridLayout->setRowStretch(6, 3);
        gridLayout->setRowStretch(7, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnMinimumWidth(0, 1);
        gridLayout->setColumnMinimumWidth(1, 2);
        gridLayout->setRowMinimumHeight(0, 1);
        gridLayout->setRowMinimumHeight(1, 1);
        gridLayout->setRowMinimumHeight(2, 1);
        gridLayout->setRowMinimumHeight(3, 1);
        gridLayout->setRowMinimumHeight(4, 1);
        gridLayout->setRowMinimumHeight(5, 3);
        gridLayout->setRowMinimumHeight(6, 3);
        gridLayout->setRowMinimumHeight(7, 1);

        horizontalLayout_3->addLayout(gridLayout);

        textBrowser = new QTextBrowser(layoutWidget1);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        horizontalLayout_3->addWidget(textBrowser);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit_data = new QLineEdit(layoutWidget1);
        lineEdit_data->setObjectName(QString::fromUtf8("lineEdit_data"));
        lineEdit_data->setMinimumSize(QSize(300, 0));

        gridLayout_2->addWidget(lineEdit_data, 3, 1, 1, 1);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 6, 1, 1, 1);

        lineEdit_addrWrite = new QLineEdit(layoutWidget1);
        lineEdit_addrWrite->setObjectName(QString::fromUtf8("lineEdit_addrWrite"));

        gridLayout_2->addWidget(lineEdit_addrWrite, 1, 1, 1, 1);

        pushButton_send = new QPushButton(layoutWidget1);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        sizePolicy.setHeightForWidth(pushButton_send->sizePolicy().hasHeightForWidth());
        pushButton_send->setSizePolicy(sizePolicy);
        pushButton_send->setMinimumSize(QSize(150, 50));

        gridLayout_2->addWidget(pushButton_send, 4, 1, 2, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);

        pushButton_disclean = new QPushButton(layoutWidget1);
        pushButton_disclean->setObjectName(QString::fromUtf8("pushButton_disclean"));

        gridLayout_2->addWidget(pushButton_disclean, 4, 0, 2, 1);

        gridLayout_2->setColumnStretch(0, 1);

        horizontalLayout_4->addLayout(gridLayout_2);

        textEdit_2 = new QTextEdit(layoutWidget1);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        horizontalLayout_4->addWidget(textEdit_2);

        horizontalLayout_4->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setStyleSheet(QString::fromUtf8("QWidget{\n"
"		background-color: rgb(114, 159, 207);\n"
"}"));
        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 350, 821, 151));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 40, 111, 25));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 80, 121, 25));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 140, 67, 17));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\350\277\236\346\216\245", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Widget", "\345\237\272\347\253\231\350\256\276\347\275\256", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Widget", "\344\272\214\347\273\264\345\256\232\344\275\215\347\225\214\351\235\242", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        comboBox_dataBit->setItemText(0, QApplication::translate("Widget", "5", nullptr));
        comboBox_dataBit->setItemText(1, QApplication::translate("Widget", "6", nullptr));
        comboBox_dataBit->setItemText(2, QApplication::translate("Widget", "7", nullptr));
        comboBox_dataBit->setItemText(3, QApplication::translate("Widget", "8", nullptr));

        comboBox_dataBit->setCurrentText(QApplication::translate("Widget", "5", nullptr));
        comboBox_parity->setItemText(0, QApplication::translate("Widget", "No", nullptr));
        comboBox_parity->setItemText(1, QApplication::translate("Widget", "Even", nullptr));
        comboBox_parity->setItemText(2, QApplication::translate("Widget", "Odd", nullptr));
        comboBox_parity->setItemText(3, QApplication::translate("Widget", "Space", nullptr));
        comboBox_parity->setItemText(4, QApplication::translate("Widget", "Mark", nullptr));

        lineEdit_num->setText(QApplication::translate("Widget", "1", nullptr));
        label_9->setText(QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250\346\225\260\351\207\217", nullptr));
        label_3->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        comboBox_baudRate->setItemText(0, QApplication::translate("Widget", "4800", nullptr));
        comboBox_baudRate->setItemText(1, QApplication::translate("Widget", "9600", nullptr));
        comboBox_baudRate->setItemText(2, QApplication::translate("Widget", "38400", nullptr));
        comboBox_baudRate->setItemText(3, QApplication::translate("Widget", "57600", nullptr));
        comboBox_baudRate->setItemText(4, QApplication::translate("Widget", "115200", nullptr));

        comboBox_baudRate->setCurrentText(QApplication::translate("Widget", "4800", nullptr));
        pushButton_read->setText(QApplication::translate("Widget", "\350\257\273\345\217\226\345\257\204\345\255\230\345\231\250", nullptr));
        label->setText(QApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_5->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        comboBox_stopBit->setItemText(0, QApplication::translate("Widget", "1", nullptr));
        comboBox_stopBit->setItemText(1, QApplication::translate("Widget", "1.5", nullptr));
        comboBox_stopBit->setItemText(2, QApplication::translate("Widget", "2", nullptr));

        label_4->setText(QApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        pushButton_connect->setText(QApplication::translate("Widget", "\345\273\272\347\253\213\350\277\236\346\216\245", nullptr));
        label_11->setText(QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200", nullptr));
        lineEdit_addrRead->setText(QApplication::translate("Widget", "0x0000", nullptr));
        label_2->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        label_6->setText(QApplication::translate("Widget", "\344\273\216\350\256\276\345\244\207ID\345\217\267:", nullptr));
        lineEdit_id->setText(QApplication::translate("Widget", "0x01", nullptr));
        lineEdit_data->setText(QApplication::translate("Widget", "0x0007,0x0001,0x0101", nullptr));
        label_10->setText(QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250\346\225\260\346\215\256", nullptr));
        lineEdit_addrWrite->setText(QApplication::translate("Widget", "0x0000", nullptr));
        pushButton_send->setText(QApplication::translate("Widget", "\345\206\231\345\205\245\345\257\204\345\255\230\345\231\250", nullptr));
        label_8->setText(QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200", nullptr));
        pushButton_disclean->setText(QApplication::translate("Widget", "\346\270\205\351\231\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "Tab 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "TAGID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget", "Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget", "A\345\237\272\347\253\231", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget", "B\345\237\272\347\253\231", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget", "C\345\237\272\347\253\231", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget", "D\345\237\272\347\253\231", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\346\265\213\350\267\235\345\256\232\344\275\215\344\275\277\350\203\275", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "\344\270\273\346\234\272\347\253\231\350\276\223\345\207\272\345\215\217\350\256\256", nullptr));
        label_7->setText(QApplication::translate("Widget", "\345\256\232\344\275\215\346\250\241\345\274\217\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Widget", "Tab 3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
