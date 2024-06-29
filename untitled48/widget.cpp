#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsColorizeEffect>
#include <QGraphicsOpacityEffect>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //几何属性动画初始化
    propertyAnimation = new QPropertyAnimation(ui->geometryWidget, "geometry");

    //设置动画起始值
    propertyAnimation->setStartValue(QRect(0, 0, 100, 100));
    //在某个时间段
    propertyAnimation->setKeyValueAt(0.5, QRect(1024-200, 0, 100, 100));
    //结束值
    propertyAnimation->setEndValue(QRect(1024-200, 400, 200, 200));
    //设置动画时长
    propertyAnimation->setDuration(1000);
    //设置周期
    propertyAnimation->setLoopCount(1);
    //缓和曲线（动画曲线）
    propertyAnimation->setEasingCurve(QEasingCurve::OutCubic);

    //颜色动画
    QGraphicsColorizeEffect *graphicsColorizeEffect = new QGraphicsColorizeEffect(ui->colorWidget);
    ui->colorWidget->setGraphicsEffect(graphicsColorizeEffect);
    propertyAnimation1 = new QPropertyAnimation(graphicsColorizeEffect, "color");
    propertyAnimation1->setStartValue(QColor(Qt::yellow));
    propertyAnimation1->setEndValue(QColor(Qt::darkGray));
    propertyAnimation1->setDuration(1000);

    //不透明度动画
    QGraphicsOpacityEffect *graphicsOpacityEffect = new QGraphicsOpacityEffect(this);
    ui->opacityWidget->setGraphicsEffect(graphicsOpacityEffect);
    propertyAnimation2 = new QPropertyAnimation(graphicsOpacityEffect, "opacity");
    propertyAnimation2->setStartValue(0.0);
    propertyAnimation2->setEndValue(1.0);
    propertyAnimation2->setDuration(1000);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    propertyAnimation->start();
}

void Widget::on_pushButton_2_clicked()
{
    propertyAnimation1->start();
}

void Widget::on_pushButton_3_clicked()
{
    propertyAnimation2->start();
}
