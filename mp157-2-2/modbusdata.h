#ifndef MODBUSDATA_H
#define MODBUSDATA_H

#include <QObject>
#include <QModbusRtuSerialMaster>
#include <QDebug>
#include <QSerialPort>
#include <QMutex>
//#include <widget.h>
class ModbusData : public QObject
{
    Q_OBJECT
public:
    explicit ModbusData(QObject *parent = nullptr);
    void InitModbus();
signals:
    void onModbusRawData(QString data, int type);
public:
    void onModbusRawDataSlot(QString data, int type);

public:
    QModbusReply *lastRequest;
    QModbusClient *modbusDevice;
    QSerialPort  SerialPort;
    QSerialPort::BaudRate baud;
    QSerialPort::DataBits dataBit;
    QSerialPort::Parity parity;
    QSerialPort::StopBits stopBit;
    QMutex       m_modbusMutex;
};

#endif // MODBUSDATA_H
