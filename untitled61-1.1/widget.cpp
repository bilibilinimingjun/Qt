#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(1024, 600);
    serialPort = new QSerialPort (this);

    //扫描串口，添加到下拉菜单
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->comboBox->addItem(info.portName());
    }

    connect(serialPort, SIGNAL(readyRead()), this, SLOT(readData()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked(bool checked)
{
    if(checked){
        // 设置要打开串口的名字
        serialPort->setPortName(ui->comboBox->currentText());

        // 设置波特率
        serialPort->setBaudRate(ui->comboBox_2->currentText().toInt());

        // 设置停止位
        serialPort->setStopBits(QSerialPort::StopBits(ui->comboBox_3->currentText().toInt()));

        //设置数据位
        serialPort->setDataBits(QSerialPort::DataBits(ui->comboBox_4->currentText().toInt()));

        //设置校验位
        switch (ui->comboBox_5->currentIndex())
        {
        case 0:
            serialPort->setParity(QSerialPort::NoParity);
            break;
        case 1:
            serialPort->setParity(QSerialPort::EvenParity);
            break;
        case 2:
            serialPort->setParity(QSerialPort::OddParity);
            break;
        case 3:
            serialPort->setParity(QSerialPort::SpaceParity);
            break;
        case 4:
            serialPort->setParity(QSerialPort::MarkParity);
            break;
        default:
            break;
        }

        //设置流控
        serialPort->setFlowControl(QSerialPort::NoFlowControl);

        if(!serialPort->open(QIODevice::ReadWrite)){
            QMessageBox::about(this, "错误", "串口打开失败");
            return;
        }

        ui->comboBox->setEditable(false);
        ui->comboBox_2->setEditable(false);
        ui->comboBox_3->setEditable(false);
        ui->comboBox_4->setEditable(false);
        ui->comboBox_5->setEditable(false);

        ui->pushButton->setText("关闭串口");
    } else {
        //关闭串口
        serialPort->close();
        ui->comboBox->setEditable(true);
        ui->comboBox_2->setEditable(true);
        ui->comboBox_3->setEditable(true);
        ui->comboBox_4->setEditable(true);
        ui->comboBox_5->setEditable(true);

        ui->pushButton->setText("打开串口");
    }
}

void Widget::readData()
{
    // 读取数据
    ui->textBrowser->insertPlainText(serialPort->readAll());
}

void Widget::on_pushButton_2_clicked()
{
    // 发送数据
    serialPort->write(ui->textEdit->toPlainText().toUtf8());
}

void Widget::on_pushButton_3_clicked()
{
    ui->textEdit->clear();
}
