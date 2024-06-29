#include "qqitem.h"
#include "ui_qqitem.h"

QQitem::QQitem(QString icon, bool flag, QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QQitem)
{
    ui->setupUi(this);
    QImage image(icon);
    ui->icon->setPixmap(QPixmap::fromImage(image.scaled(ui->icon->width(), ui->icon->height())));     //设置头像图片

    QImage image2(":/icons/xiala.png");
    ui->phone->setPixmap(QPixmap::fromImage(image2.scaled(ui->phone->width(), ui->phone->height())));  //设置手机图片
    ui->phone->setVisible(flag);   //控制小图标

    ui->name->setText(name);
}

QQitem::~QQitem()
{
    delete ui;
}
