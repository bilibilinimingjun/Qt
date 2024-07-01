#include "modbusdata.h"
#include <savelog.h>
ModbusData::ModbusData(QObject *parent):QObject (parent)
{
    //modbusDevice = nullptr;
    //InitModbus();
    //modbusDevice = nullptr;
     connect(SaveLog::Instance(),&SaveLog::sigModbusData,this,&ModbusData::onModbusRawDataSlot);
}

void ModbusData::InitModbus()
{
    modbusDevice = nullptr;
    qDebug() << "InitModbus";
    if (modbusDevice) {
        modbusDevice->disconnectDevice();
        delete modbusDevice;
        modbusDevice = nullptr;
    }

    modbusDevice = new QModbusRtuSerialMaster(this);
    qDebug()<< modbusDevice << endl;
    connect(modbusDevice, &QModbusClient::errorOccurred, [this](QModbusDevice::Error) {
        qDebug() << "modbus Error:" << modbusDevice->errorString();
    });

    // connect(modbusDevice, &QModbusClient::stateChanged, this, &Widget::onStateChanged);

}

void ModbusData::onModbusRawDataSlot(QString data, int type)
{
    qDebug()<< "DATA" <<data<< "TYPE" <<type;
    emit onModbusRawData(data,type);
}

