#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
#include <QSerialPort>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("ModbusRTU Demo");   //属性设置
    IniModbus();                                 //实例化Modbus
}

Widget::~Widget()
{
    delete ui;
}

void Widget::IniModbus()
{
     modbusMaster = new QModbusRtuSerialMaster(this);

     modbusMaster->setConnectionParameter(QModbusDevice::SerialPortNameParameter, "ttyUSB0");
     modbusMaster->setConnectionParameter(QModbusDevice::SerialParityParameter, QSerialPort::EvenParity);
     modbusMaster->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, QSerialPort::Baud115200);
     modbusMaster->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, QSerialPort::Data8);
     modbusMaster->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, QSerialPort::OneStop);

     if(modbusMaster->connectDevice())
         qDebug()<<"连接成功";
     else
         qDebug()<<"连接失败";
}

void Widget::on_pushButton_clicked()
{

     QModbusDataUnit readUnit(QModbusDataUnit::HoldingRegisters, 0, 1);  //读寄存器地址，从零开始读一位
     //读取等待回复
     if (auto *reply = modbusMaster->sendReadRequest(readUnit, 1)) {

         while (!reply->isFinished()) {
             QCoreApplication::processEvents();
         }

         //是否报错
         if (reply->error() == QModbusDevice::NoError) {

             const QModbusDataUnit resultUnit = reply->result();  //获取结果
             QString result = "";
             for (int i = 0; i < resultUnit.valueCount(); ++i) {
                 result += QString::number(resultUnit.value(i)) + " ";
             }
             ui->label->setText(result);
         } else {
           qDebug()<<reply->errorString();
         }

         reply->deleteLater();
     } else {
         qDebug()<<modbusMaster->errorString();
     }
}

void Widget::on_pushButton_2_clicked()
{

    QModbusDataUnit writeUnit(QModbusDataUnit::HoldingRegisters, 0, 1);  //写入数据
    qint32 value = ui->lineEdit->text().toInt();
    writeUnit.setValue(0, value);

    if (auto *reply = modbusMaster->sendWriteRequest(writeUnit, 1)) {
        while (!reply->isFinished()) {
            QCoreApplication::processEvents();
        }

        if (reply->error() == QModbusDevice::NoError) {
            qDebug()<< "写入成功";
        } else {
            qDebug()<< "写入失败" + reply->errorString();
        }

        reply->deleteLater();
    } else {
       qDebug()<< "写入失败" + modbusMaster->errorString();
    }
}
