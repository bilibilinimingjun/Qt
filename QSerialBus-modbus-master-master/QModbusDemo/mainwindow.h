#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModbusClient>
#include <QModbusReply>
#include <QMutex>
#include <QSerialPort>
#include <QSerialPortInfo>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    void on_pushButton_connect_clicked();

    void on_pushButton_read_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::MainWindow *ui;

    QModbusReply *lastRequest;
    QModbusClient *modbusDevice;

    QSerialPort  SerialPort;
    QSerialPort::BaudRate baud;
    QSerialPort::DataBits dataBit;
    QSerialPort::Parity parity;
    QSerialPort::StopBits stopBit;
    QMutex       m_modbusMutex;
};

#endif // MAINWINDOW_H
