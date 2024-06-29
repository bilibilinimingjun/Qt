#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QModbusRtuSerialMaster>
#include <savelog.h>
#define READNUM 4
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    modbusDevice = nullptr;
    freshSerialPortCombox();        //寻找可用串口
    InitModbus();                   //初始化modbus
}

MainWindow::~MainWindow()
{
    delete ui;
}
//寻找可用串口
void MainWindow::freshSerialPortCombox()
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
void MainWindow::MainWindow::InitModbus()
{
    //获取modbus raw 数据帧
    connect(SaveLog::Instance(),&SaveLog::sigModbusData,this,&MainWindow::onModbusRawData);
    if (modbusDevice) {
        modbusDevice->disconnectDevice();
        delete modbusDevice;
        modbusDevice = nullptr;
    }


    modbusDevice = new QModbusRtuSerialMaster(this);
    connect(modbusDevice, &QModbusClient::errorOccurred, [this](QModbusDevice::Error) {
        qDebug() << "modbus Error:" << modbusDevice->errorString();
    });

    // connect(modbusDevice, &QModbusClient::stateChanged, this, &MainWindow::onStateChanged);
}
//获取modbus数据帧 0发送的数据 1接受的数据
void MainWindow::onModbusRawData(QString data, int type)
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
//连接串口
void MainWindow::on_pushButton_connect_clicked()
{
    if (!modbusDevice)
        return;

    switch (ui->comboBox_baudRate->currentIndex()) {
    case 0: baud = QSerialPort::Baud1200; break;
    case 1: baud = QSerialPort::Baud2400; break;
    case 2: baud = QSerialPort::Baud4800; break;
    case 3: baud = QSerialPort::Baud9600; break;
    case 4: baud = QSerialPort::Baud19200; break;
    case 5: baud = QSerialPort::Baud38400; break;
    case 6: baud = QSerialPort::Baud57600; break;
    case 7: baud = QSerialPort::Baud115200; break;
    default: baud = QSerialPort::Baud9600; break;
    }

    switch (ui->comboBox_dataBit->currentIndex()) {
    case 0: dataBit = QSerialPort::Data5; break;
    case 1: dataBit = QSerialPort::Data6; break;
    case 2: dataBit = QSerialPort::Data7; break;
    case 3: dataBit = QSerialPort::Data8; break;
    default: dataBit = QSerialPort::Data8; break;
    }


    switch (ui->comboBox_parity->currentIndex()) {
    case 0: parity = QSerialPort::NoParity; break;
    case 1: parity = QSerialPort::EvenParity; break;
    case 2: parity = QSerialPort::OddParity; break;
    case 3: parity = QSerialPort::SpaceParity; break;
    case 4: parity = QSerialPort::MarkParity; break;
    default: parity = QSerialPort::NoParity; break;
    }

    switch (ui->comboBox_stopBit->currentIndex()) {
    case 0: stopBit = QSerialPort::OneStop; break;
    case 1: stopBit = QSerialPort::OneAndHalfStop; break;
    case 2: stopBit = QSerialPort::TwoStop; break;
    default: stopBit = QSerialPort::OneStop; break;
    }

    modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, QSerialPort::Data8);
    if (modbusDevice->state() != QModbusDevice::ConnectedState) {
        connectModbus();
        ui->pushButton_connect->setText("断开连接");
        qDebug() << "连接成功";
    }else {
        disconnnectModbus();
        ui->pushButton_connect->setText("建立连接");
        qDebug() << "连接失败";
    }
}
void MainWindow::connectModbus()
{
    disconnnectModbus();
    if (!modbusDevice)
        return;
    modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,ui->comboBox_serialName->currentText());
    modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,parity);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,baud);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,dataBit);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,stopBit);

    modbusDevice->setTimeout(1000);
    modbusDevice->setNumberOfRetries(0);
    //连接失败
    if(modbusDevice->connectDevice())
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

void MainWindow::disconnnectModbus()
{
    if (!modbusDevice)
        return;
    modbusDevice->disconnectDevice();
    qDebug() << "断开连接";
}
//读取寄存器
void MainWindow::on_pushButton_read_clicked()
{
    readUnit(0x01,0x00,READNUM);
}
//写入寄存器
void MainWindow::on_pushButton_send_clicked()
{
    QList<quint16> values;
    for(quint16 i=0; i<3; i++)
    {
        values.append(i);
    }
    writeUnit(0x01,0,values);
}
//写入寄存器 slaveId 写入的从机ID  startAddress写入的起始地址 values写入的值
void MainWindow::writeUnit(int slaveId, int startAddress, QList<quint16> values)
{
    if (!modbusDevice)
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
    if (auto *reply = modbusDevice->sendWriteRequest(writeUnit,slaveId)) {
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
        qDebug() << QString(("Write error: ") + modbusDevice->errorString());
    }
}
//读取寄存器 slaveId 读取的从机ID  startAddress读取的起始地址 readNum读取的数量
void MainWindow::readUnit(int slaveId, int startAddress, int readNum)
{
    if (!modbusDevice)
    {
        QMessageBox::information(NULL,  "Title",  "请先连接设备");
        return;
    }
    connectModbus();
    QMutexLocker lock(&m_modbusMutex);
    if (auto *reply = modbusDevice->sendReadRequest(QModbusDataUnit(QModbusDataUnit::HoldingRegisters, startAddress, readNum), slaveId)) {
        if (!reply->isFinished())
            connect(reply, &QModbusReply::finished, this, &MainWindow::onReadReady);
        else
            delete reply;
    } else {
        qDebug() << "Read error: " << modbusDevice->errorString();
    }
}
//接受modbus返回数据
void MainWindow::onReadReady()
{
    auto reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
        return;

    if (reply->error() == QModbusDevice::NoError) {
        const QModbusDataUnit unit = reply->result();
        if(unit.valueCount() == READNUM)
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
