#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    auto reply = qobject_cast<QModbusReply *>(sender());
    const QModbusDataUnit unit = reply->result();//获取结果
    for (uint i = 0; i < unit.valueCount(); i++) {//获取每个结果
        if(unit.registerType()==QModbusDataUnit::HoldingRegisters && i==0){//判断数据格式

        }

        qDebug()<<tr("Address: %1, Value: %2").arg(unit.startAddress())
                  .arg(QString::number(unit.value(i),
                                       unit.registerType() <=
                                       QModbusDataUnit::Coils ? 10 : 16));
    }
}

Widget::~Widget()
{
    delete ui;
}

