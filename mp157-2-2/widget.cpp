#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>
#include <QDebug>
#include <QModbusRtuSerialMaster>
#include <savelog.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , id(0x01)
{
    QWidget::update();
    ui->setupUi(this);
    this->setLayout(ui->horizontalLayout);  //设置页面随窗口大小变化
    QWidget::update();
    m_modbus.moveToThread(&m_thread); //加入到子线程
    m_thread.start(); //开启子线程


    m_modbus.modbusDevice = nullptr;
    m_modbus.InitModbus();

    connect(&m_modbus,&ModbusData::onModbusRawData,this,&Widget::onModbusRawData);
    freshSerialPortCombox();        //寻找可用串口


}

Widget::~Widget()
{
    delete ui;
    m_thread.exit();
    m_thread.wait();
}

//寻找可用串口
void Widget::freshSerialPortCombox()
{
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QSerialPort tempSer;
        tempSer.setPort(info);
        if(tempSer.open(QIODevice::ReadWrite))
        {
            ui->comboBox_serialName->addItem(tempSer.portName());
            tempSer.close();
        }
    }
}

//初始modbus
/*
void Widget::InitModbus()
{
    //获取modbus raw 数据帧
    connect(SaveLog::Instance(),&SaveLog::sigModbusData,this,&Widget::onModbusRawData);
    if (modbusDevice) {
        modbusDevice->disconnectDevice();
        delete modbusDevice;
        modbusDevice = nullptr;
    }


    modbusDevice = new QModbusRtuSerialMaster(this);
    connect(modbusDevice, &QModbusClient::errorOccurred, [this](QModbusDevice::Error) {
        qDebug() << "modbus Error:" << modbusDevice->errorString();
    });

    // connect(modbusDevice, &QModbusClient::stateChanged, this, &Widget::onStateChanged);
}*/

//获取modbus数据帧 0发送的数据 1接受的数据
void Widget::onModbusRawData(QString data, int type)
{
    QString color;
    QString text;
    if(type == 0)   //发送
    {
        text = "发送数据帧:";
        color = "#F37257";
    }
    else if(type == 1)  //接受
    {
        text = "接受数据帧:";
        color = "#1777D7";
    }
    // 设置文字（样式+内容）
    QString  str = QString("<font color=\"%1\">" +QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ")+ text + data + "</font>").arg(color);
    ui->textBrowser->append(str);
}

//接受modbus返回数据
void Widget::onReadReady()
{
    auto reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
        return;

    if (reply->error() == QModbusDevice::NoError)
    {
        const QModbusDataUnit unit = reply->result();
        if(unit.valueCount() == num)
                for (uint i = 0; i < unit.valueCount(); i++) {
                const QString entry = tr("Address: %1, Value: %2").arg(unit.startAddress() + i)
                        .arg(QString::number(unit.value(i),
                                             unit.registerType() <= QModbusDataUnit::Coils ? 10 : 16));
                ui->textBrowser->append(entry);
            }
    } else if (reply->error() == QModbusDevice::ProtocolError) {
        qDebug() << QString("Read response error: %1 (Mobus exception: 0x%2)").
                    arg(reply->errorString()).
                    arg(reply->rawResult().exceptionCode(), -1, 16);
    } else {
        qDebug() << QString("Read response error: %1 (code: 0x%2)").
                    arg(reply->errorString()).
                    arg(reply->error(), -1, 16);
    }
    reply->deleteLater();
}

void Widget::on_listWidget_currentRowChanged(int currentRow)
{
    ui->tabWidget->setCurrentIndex(currentRow);
}

//连接串口
void Widget::on_pushButton_connect_clicked()
{

    if (!m_modbus.modbusDevice)
        //qDebug() << m_modbus.modbusDevice;
        //qDebug() << m_modbus.modbusDevice->state();
        //qDebug() << "no modbus devices";
        return;

    switch (ui->comboBox_baudRate->currentIndex()) {
    case 0: m_modbus.baud = QSerialPort::Baud4800; break;
    case 1: m_modbus.baud = QSerialPort::Baud9600; break;
    case 2: m_modbus.baud = QSerialPort::Baud38400; break;
    case 3: m_modbus.baud = QSerialPort::Baud57600; break;
    case 4: m_modbus.baud = QSerialPort::Baud115200; break;
    default: m_modbus.baud = QSerialPort::Baud115200; break;
    }

    switch (ui->comboBox_dataBit->currentIndex()) {
    case 0: m_modbus.dataBit = QSerialPort::Data5; break;
    case 1: m_modbus.dataBit = QSerialPort::Data6; break;
    case 2: m_modbus.dataBit = QSerialPort::Data7; break;
    case 3: m_modbus.dataBit = QSerialPort::Data8; break;
    default: m_modbus.dataBit = QSerialPort::Data8; break;
    }


    switch (ui->comboBox_parity->currentIndex()) {
    case 0: m_modbus.parity = QSerialPort::NoParity; break;
    case 1: m_modbus.parity = QSerialPort::EvenParity; break;
    case 2: m_modbus.parity = QSerialPort::OddParity; break;
    case 3: m_modbus.parity = QSerialPort::SpaceParity; break;
    case 4: m_modbus.parity = QSerialPort::MarkParity; break;
    default: m_modbus.parity = QSerialPort::NoParity; break;
    }

    switch (ui->comboBox_stopBit->currentIndex()) {
    case 0: m_modbus.stopBit = QSerialPort::OneStop; break;
    case 1: m_modbus.stopBit = QSerialPort::OneAndHalfStop; break;
    case 2: m_modbus.stopBit = QSerialPort::TwoStop; break;
    default: m_modbus.stopBit = QSerialPort::OneStop; break;
    }

    //ui->lineEdit_id->setPlaceholderText("You can enter up to 6 characters");
    //ui->lineEdit_id->setMaxLength(4);                                     //最多输入4个字符
    QString addrID = ui->lineEdit_id->text();
    ui->lineEdit_id->setMaxLength(4);
    uint8_t addrid = static_cast<uint8_t>(addrID.toUInt(nullptr, 16));   //获取读取起始地址
    id = addrid;

    m_modbus.modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, QSerialPort::Data8);
     qDebug() << "state:" << m_modbus.modbusDevice->state();
    if (m_modbus.modbusDevice->state() != QModbusDevice::ConnectedState) {
        connectModbus();

        ui->pushButton_connect->setText("断开连接");
        ui->lineEdit_id->setEnabled(false);          //失能起始地址
        qDebug() << "连接成功";
    }else {
        disconnnectModbus();
        ui->pushButton_connect->setText("建立连接");
        ui->lineEdit_id->setEnabled(true);           //使能起始地址
        qDebug() << "连接失败";
    }
}

void Widget::connectModbus()
{
    disconnnectModbus();
    if (!m_modbus.modbusDevice)
        return;
    m_modbus.modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,ui->comboBox_serialName->currentText());
    m_modbus.modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,m_modbus.parity);
    m_modbus.modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,m_modbus.baud);
    m_modbus.modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,m_modbus.dataBit);
    m_modbus.modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,m_modbus.stopBit);
    qDebug() << "set: " <<m_modbus.parity << " "  << m_modbus.baud << " " << m_modbus.dataBit << " " <<  m_modbus.stopBit;
    m_modbus.modbusDevice->setTimeout(1000);
    m_modbus.modbusDevice->setNumberOfRetries(0);
    //连接失败
    if(m_modbus.modbusDevice->connectDevice())
    {
        ui->pushButton_connect->setText("断开连接");
        qDebug() << "连接成功";
    }
    else
    {
        ui->pushButton_connect->setText("建立连接");
        qDebug() << "连接失败";
        QMessageBox::information(NULL,  "Title",  "串口打开失败");
    }
}

void Widget::disconnnectModbus()
{
    qDebug() << m_modbus.modbusDevice;
    if (!m_modbus.modbusDevice)
        return;
    m_modbus.modbusDevice->disconnectDevice();
    qDebug() << "断开连接";
}

//读取寄存器
void Widget::on_pushButton_read_clicked()
{
    QString addrRead = ui->lineEdit_addrRead->text();
    uint16_t addr = static_cast<uint16_t>(addrRead.toUInt(nullptr, 16));   //获取读取起始地址
    num = ui->lineEdit_num->text().toUInt();                               //获取读取寄存器数量
    readUnit(id, addr, num);

    //qDebug() << addrRead << endl;
}

//写入寄存器
void Widget::on_pushButton_send_clicked()
{
    QString addrWrite = ui->lineEdit_addrWrite->text();
    uint16_t addr = static_cast<uint16_t>(addrWrite.toUInt(nullptr, 16));   //获取读取起始地址

    QList<quint16> values;                         //寄存器内容列表
    QString dataAll = ui->lineEdit_data->text();
    QStringList datalist = dataAll.split(",");
    for (int i = 0; i < datalist.size(); i++) {
        QString dataEven = datalist.at(i);
        uint16_t data = static_cast<uint16_t>(dataEven.toUInt(nullptr, 16));
        values.append(data);
    }
    //qDebug() << datalist << endl;
    //qDebug() << values << endl;

    writeUnit(id, addr, values);
}


void Widget::writeUnit(int slaveId, int startAddress, QList<quint16> values)
{
    if (!m_modbus.modbusDevice)
    {
        QMessageBox::information(NULL,  "Title",  "请先连接设备");
        return;
    }
    connectModbus();
    QModbusDataUnit writeUnit = QModbusDataUnit(QModbusDataUnit::HoldingRegisters,startAddress, values.size());
    for(int i=0; i<values.size(); i++)
    {
        writeUnit.setValue(i, values.at(i));
    }

    //serverEdit 发生给slave的ID
    if (auto *reply = m_modbus.modbusDevice->sendWriteRequest(writeUnit,slaveId)) {
        if (!reply->isFinished()) {
            connect(reply, &QModbusReply::finished, this, [this, reply]() {
                if (reply->error() == QModbusDevice::ProtocolError) {
                    qDebug() << QString("Write response error: %1 (Mobus exception: 0x%2)")
                                .arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16);
                } else if (reply->error() != QModbusDevice::NoError) {
                    qDebug() << QString("Write response error: %1 (code: 0x%2)").
                                arg(reply->errorString()).arg(reply->error(), -1, 16);
                }
                reply->deleteLater();
            });
        } else {
            reply->deleteLater();
        }
    } else {
        qDebug() << QString(("Write error: ") + m_modbus.modbusDevice->errorString());
    }
}
//读取寄存器 slaveId 读取的从机ID  startAddress读取的起始地址 readNum读取的数量
void Widget::readUnit(int slaveId, int startAddress, int readNum)
{
    if (!m_modbus.modbusDevice)
    {
        QMessageBox::information(NULL,  "Title",  "请先连接设备");
        return;
    }
    connectModbus();
    QMutexLocker lock(&m_modbus.m_modbusMutex);
    if (auto *reply = m_modbus.modbusDevice->sendReadRequest(QModbusDataUnit(QModbusDataUnit::HoldingRegisters, startAddress, readNum), slaveId)) {
        if (!reply->isFinished())
            connect(reply, &QModbusReply::finished, this, &Widget::onReadReady);
        else
            delete reply;
    } else {
        qDebug() << "Read error: " << m_modbus.modbusDevice->errorString();
    }
}


void Widget::on_pushButton_disclean_clicked()
{
    ui->textBrowser->clear();
}
