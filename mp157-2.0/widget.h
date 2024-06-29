#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QModbusClient>
#include <QModbusReply>
#include <QMutex>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();    

    void freshSerialPortCombox();           //寻找可用串口
    void InitModbus();                      //初始化modbus
    void connectModbus();                   //连接modbus
    void disconnnectModbus();               //断开modbus

    //写入寄存器 slaveId 写入的从机ID  startAddress写入的起始地址 values写入的值
    void writeUnit(int slaveId, int startAddress, QList<quint16> values);
    //读取寄存器 slaveId 读取的从机ID  startAddress读取的起始地址 readNum读取的数量
    void readUnit(int slaveId, int startAddress, int readNum);

public slots:
    void onModbusRawData(QString data, int type);   //显示modbus数据
    void onReadReady();                             //读取modbus寄存器值
private slots:
    void on_listWidget_currentRowChanged(int currentRow);  //设置界面样式

    void on_pushButton_connect_clicked();

    void on_pushButton_read_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::Widget *ui;

    QModbusReply *lastRequest;
    QModbusClient *modbusDevice;

    QSerialPort  SerialPort;
    QSerialPort::BaudRate baud;
    QSerialPort::DataBits dataBit;
    QSerialPort::Parity parity;
    QSerialPort::StopBits stopBit;
    QMutex       m_modbusMutex;

    uint num;
    int id;
};
#endif // WIDGET_H
