#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QModbusDataUnit>
#include <QModbusRtuSerialMaster>
#include <QSerialPort>
#include <QUrl>
#include <QDebug>
#include <QTimer>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_openLed_clicked();

    void on_pushButton_closeLed_clicked();

    //数据接受槽
    void readReady();
    //定时器槽
    void timeOut();

private:
    Ui::Widget *ui;
    QModbusClient *modbusDevice;//modbus对象
    QTimer *time;//定时查询灯的状态
    void setupLedState(bool);//修改灯空间背景颜色
};

#endif // WIDGET_H
