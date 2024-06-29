#include "widget.h"
#include "ui_widget.h"
#include "filedialog.h"
#include <QFile>
#include <QDateTime>

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


void Widget::on_pushButton_clicked()
{
    QFile file;
    file.setFileName(QDateTime::currentDateTime().toString("MM-dd-hh-mm-ss") + ".txt");   //文件命名（时间）

    file.open(QIODevice::ReadWrite);

    FileDialog *fileDialog = new FileDialog(this);   //打开编辑窗口
    fileDialog->resize(this->size());
    fileDialog->show();
    fileDialog->setModal(true);  //窗口设置
    fileDialog->exec();          //使窗口无法选中


    QString tmp = fileDialog->getTextEditContent();
    file.write(tmp.toUtf8());
    file.close();

    if(tmp.length() == 0)      //无内容则删除创建的文件
        file.remove();

    delete fileDialog;
}
