#include "filedialog.h"
#include "ui_filedialog.h"

FileDialog::FileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileDialog)
{
    ui->setupUi(this);
}

FileDialog::~FileDialog()
{
    delete ui;
}

QString FileDialog::getTextEditContent()   //读取文本
{
    return  ui->textEdit->toPlainText();
}

void FileDialog::on_pushButton_released()   //设置松开图像
{
    ui->pushButton->setIcon(QIcon(":/icons/back1.png"));
}

void FileDialog::on_pushButton_pressed()
{
    ui->pushButton->setIcon(QIcon(":/icons/back_un1.png"));
}

void FileDialog::on_pushButton_clicked()   //点击关闭
{
    this->close();
}
