#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , i(0)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);        //chuan di MainWindow lei
    qDebug() << "starting..." << endl;
    this->resize(800, 480);
    //QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
    school = new School(this);
    student = new Student(this);
    QObject::connect(school, SIGNAL(sendMessages()), student, SLOT(comeBackToClass()));
    emit school->sendMessages();
}

MainWindow::~MainWindow()
{
    qDebug() << "ending..." << endl;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    i++;
    qDebug() << "click" << i << endl;
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "ok" << endl;
}
