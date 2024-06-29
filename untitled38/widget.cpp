#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //this->resize(1024, 600);
    ui->setupUi(this);
    dialog = new QDialog(this);
    dialog->setModal(true);      //设置打开主窗口后状态不能选中

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    dialog->show();
}
