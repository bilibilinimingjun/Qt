#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("Master");

    //实例化对象
    modbusDevice = new QModbusRtuSerialMaster(this);

    //创建连接
    modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,//设置串口号
        QString("ttyUSB0"));
    modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,//设置奇偶校验
        QSerialPort::NoParity);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,//设置波特率
        QSerialPort::Baud115200);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,//设置数据位
       QSerialPort::Data8);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,//设置停止位
       QSerialPort::OneStop);
    modbusDevice->setTimeout(1000);//超时时间
    modbusDevice->setNumberOfRetries(3);//重试次数
    if (!modbusDevice->connectDevice()) {//连接slaveServer
        qDebug() <<tr("connectfail:")+modbusDevice->errorString();
    }else{
        qDebug() <<tr("connectOk:");
    }

    //定时器用来定时访问LED状态
    time=new QTimer(this);
    connect(time,&QTimer::timeout,this,&Widget::timeOut);
    time->start(100);
}


//接收到数据
void  Widget::readReady()
{
    auto reply = qobject_cast<QModbusReply *>(sender());//通过sender()获取发送信号对象的QObject指针，并且转化成QModbusReplyd对象类型的指针
    if (!reply)
        return;

    if (reply->error() == QModbusDevice::NoError) {//接收数据正常
        const QModbusDataUnit unit = reply->result();//获取结果
        for (uint i = 0; i < unit.valueCount(); i++) {//获取每个结果
            if(unit.registerType()==QModbusDataUnit::HoldingRegisters && i==0){//判断数据格式
                if(unit.value(i)==0xff)//开灯
                    ui->label_ledState->setStyleSheet ("background-color: rgb(255, 255, 0);");
                else if(unit.value(i)==0)//关灯
                    ui->label_ledState->setStyleSheet ("background-color: rgb(0, 0, 0);");
            }
            qDebug()<<tr("Address: %1, Value: %2").arg(unit.startAddress())
                      .arg(QString::number(unit.value(i),
                                           unit.registerType() <=
                                           QModbusDataUnit::Coils ? 10 : 16));
        }
    } else if (reply->error() == QModbusDevice::ProtocolError) {
        qDebug()<<tr("Read response error: %1 (Mobus exception: 0x%2)").
                  arg(reply->errorString()).
                  arg(reply->rawResult().exceptionCode(), -1, 16);
    } else {
        qDebug()<<tr("Read response error: %1 (code: 0x%2)").
                  arg(reply->errorString()).
                  arg(reply->error(), -1, 16);
    }

    reply->deleteLater();
}

//定时向从机发送LED数据读取请求
void Widget::timeOut()
{
    if (!modbusDevice)
        return;

    int startAddress=0;//开始地址
    int numberOfEntries=1;//条目数
    QModbusDataUnit ReadRequest(QModbusDataUnit::HoldingRegisters, startAddress, numberOfEntries);
    if (auto *reply = modbusDevice->sendReadRequest(ReadRequest,1)) {//发送读取数据请求
        if (!reply->isFinished())
            connect(reply, &QModbusReply::finished, this, &Widget::readReady);//绑定数据接受槽
        else
            delete reply; // broadcast replies return immediately
    } else {
        //返回指针为空，则错误
        qDebug()<<tr("Read error: ")<<modbusDevice->errorString();
    }
}



Widget::~Widget()
{
    delete ui;
}
//开灯
void Widget::on_pushButton_openLed_clicked()
{
    qDebug()<<"openLED";
    setupLedState(true);
}
//关灯
void Widget::on_pushButton_closeLed_clicked()
{
    qDebug()<<"closeLed";
    setupLedState(false);
}


//设置从站的modbus寄存器中的LED值
void Widget::setupLedState(bool ledState)
{
    if (!modbusDevice)
        return;
    int startAddress=0;//开始地址
    int numberOfEntries=1;//条目数
    QModbusDataUnit writeUnit = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, startAddress, numberOfEntries);//设置写入数据格式
    for (uint i = 0; i < writeUnit.valueCount(); i++) {//填写发送数据
        if (writeUnit.registerType() == QModbusDataUnit::HoldingRegisters)
            writeUnit.setValue(i, (ledState)?0xFF:0);
    }

    if (auto *reply = modbusDevice->sendWriteRequest(writeUnit,1)) {//发送数据写入请求 和 被操作从站地址
        if (!reply->isFinished()) {//答复完成或中止时返回true。
            connect(reply, &QModbusReply::finished, this, [this, reply]() {//发送完毕触发槽
                if (reply->error() == QModbusDevice::ProtocolError) {
                    qDebug()<<tr("Write response error: %1 (Mobus exception: 0x%2)")
                              .arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16);
                } else if (reply->error() != QModbusDevice::NoError) {
                    qDebug()<<tr("Write response error: %1 (code: 0x%2)").
                              arg(reply->errorString()).arg(reply->error(), -1, 16);
                }
                reply->deleteLater();//删除对象
            });
        } else {
            // broadcast replies return immediately
            reply->deleteLater();
        }
    } else {
        qDebug()<<tr("Write error: ") + modbusDevice->errorString();
    }
}

