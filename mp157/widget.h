#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>      //串口类
#include <QSerialPortInfo>  //串口扫描
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
    void on_radioButton_clicked(bool checked);
    void readSerial();
    void on_pushButton_2_clicked();

    void on_radioButton_2_clicked(bool checked);

    void on_pushButton_3_clicked();


private:
    Ui::Widget *ui;
    QSerialPort *serialPort;
};

#endif // WIDGET_H
