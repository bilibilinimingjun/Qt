#include "widget.h"
#include "ui_widget.h"
#include <QPropertyAnimation>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    rich = new Rich(this);
    QPropertyAnimation *propertyAnimation = new QPropertyAnimation(rich, "money", this);
    propertyAnimation->setStartValue(100);
    propertyAnimation->setEndValue(600);
    propertyAnimation->setDuration(10000);
    propertyAnimation->setEasingCurve(QEasingCurve::Linear);
    propertyAnimation->start();
}

Widget::~Widget()
{
    delete ui;
}

