#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    //this指定给绘图对象
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);  //抗锯齿

    //画矩形
    painter.drawRect(200, 100, 100, 100);

    QPen pen;
    pen.setWidth(5);
    pen.setColor(QColor("#888888"));
}

