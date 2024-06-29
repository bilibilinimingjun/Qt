#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    this->resize(1024, 600);
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_radioButton_toggled(bool checked)
{
    qDebug() << "1" << checked << endl;
}

void Widget::on_radioButton_2_toggled(bool checked)
{
    qDebug() << "2" << checked << endl;
}

void Widget::on_checkBox_stateChanged(int arg1)
{
    switch (arg1) {
    case Qt::Checked:
        qDebug() << "2" << arg1 << endl;
        break;
    case Qt::PartiallyChecked:
        qDebug() << "1" << arg1 << endl;
        break;
    case Qt::Unchecked:
        qDebug() << "0" << arg1 << endl;
        break;
    }
}
