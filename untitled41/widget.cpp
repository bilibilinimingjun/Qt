#include "widget.h"
#include "ui_widget.h"
#include "qqitem.h"

#include <QListWidgetItem>

#include <QDebug>

class QQitem;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setLayout(ui->verticalLayout);     //随窗口变化
    QQitem *qqitem = new QQitem(":/icons/jiantou.png", true, "666");
    QQitem *qqitem1 = new QQitem(":/icons/20240618114157.png", false, "放大器");

    QListWidgetItem *item0 = new QListWidgetItem;
    QListWidgetItem *item1 = new QListWidgetItem;

    ui->listWidget->addItem(item0);                //添加列表
    ui->listWidget->setItemWidget(item0, qqitem);  //将qqitem类添加到列表中
    ui->listWidget->addItem(item1);                //添加列表
    ui->listWidget->setItemWidget(item1, qqitem1);  //将qqitem类添加到列表中
    /*ui->listWidget->addItem("0");  //添加列表项
    ui->listWidget->addItem("1");
    ui->listWidget->addItem("2");

    ui->listWidget->takeItem(0);   //移除列表项

    ui->listWidget->insertItem(0, "0");  //插入项*/
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_listWidget_currentRowChanged(int currentRow)
{
    qDebug() << currentRow << endl;
}
