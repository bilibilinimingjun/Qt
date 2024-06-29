#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

#include <QDebug>
#include <QFontMetrics>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , offset(0)
    , textContent("我的第一块Linux开发板")
{
    ui->setupUi(this);

    timer = new QTimer (this);
    timer->start(5);  //定时5ms

    font.setPixelSize(50);  //设置字号

    //显示文字宽度计算
    QFontMetrics fontMetrics(font);
    textContentWidth = fontMetrics.width(textContent);

    Widget::connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTimeOut()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);

    QPen pen;
    pen.setColor(QColor(Qt::blue));

    painter.setPen(pen);

    painter.setFont(font);

    QRectF rectF = this->rect();

    //偏移
    rectF.setLeft(this->rect().width() - offset);
    //qDebug() << rectF.width() << endl;

    painter.drawText(rectF, Qt::AlignVCenter, textContent);
}

void Widget::onTimerTimeOut()
{
    //qDebug() << "hi" << endl;
    if(offset < this->width() + textContentWidth)
        offset += 1;
    else
        offset = 0;
    //更新界面
    this->update();
}

