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
    void on_pushButton_send_clicked();
    void writeUnit(int slaveId, int startAddress, QList<quint16> values);
private:
    Ui::Widget *ui;
    QModbusClient *modbusDevice;
};
#endif // WIDGET_H
