#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //进程类  QProcess
    //线程类  QThread
    //myThread = new MyThread (this);
}

Widget::~Widget()
{
    delete ui;
}

MyThread::~MyThread(){
    qDebug() << "delete" << endl;
}

void MyThread::run()
{
    qDebug() << "loading..." << endl;
    sleep(5);
    qDebug() << "ending" << endl;
    deleteLater();    //销毁线程
}

void Widget::on_pushButton_clicked()
{
    //启动线程
    //myThread->start();
    MyThread *testThread = new MyThread(this);
    testThread->start();
}

void Widget::on_pushButton_2_clicked()
{
    //终止线程
    /*if(!myThread->isFinished()){
        myThread->terminate();
    }*/
    //deleteLater();    //销毁线程
}
