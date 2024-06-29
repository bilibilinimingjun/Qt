#include "page.h"
#include "ui_page.h"
#include "widget.h"
Page::Page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page)
{
    ui->setupUi(this);

}

Page::~Page()
{
    delete ui;
}

void Page::on_pushButton_clicked()
{

}
