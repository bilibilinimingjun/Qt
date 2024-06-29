#include "widget.h"
#include "ui_widget.h"
#include <QModbusRtuSerialMaster>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    modbusDevice = nullptr;
    on_pushButton_send_clicked();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_send_clicked()
{
    QList<quint16> values;
    for(quint16 i=0; i<3; i++)
    {
        values.append(i);
    }
    writeUnit(0x01,0,values);
}
//写入寄存器 slaveId 写入的从机ID  startAddress写入的起始地址 values写入的值
void Widget::writeUnit(int slaveId, int startAddress, QList<quint16> values)
{

    QModbusDataUnit writeUnit = QModbusDataUnit(QModbusDataUnit::HoldingRegisters,startAddress, values.size());
    for(int i=0; i<values.size(); i++)
    {
        writeUnit.setValue(i, values.at(i));
    }
    for(int i = 0;i < values.size();i++)
    {
        qDebug() << writeUnit.value(i);
        }
}

