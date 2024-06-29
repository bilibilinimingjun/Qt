#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //this->resize(1024, 600);
    ui->setupUi(this);
    //this->resize(1024, 600);
    this->setLayout(ui->verticalLayout_4);
}

Widget::~Widget()
{
    delete ui;
}

