#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    rich = new Rich(this);

    //rich->setMoney(100);
    rich->setProperty("money", 200);  //这个属性会调用WRITE的方法
    qDebug() << rich->money() << endl;
}

Widget::~Widget()
{
    delete ui;
}

