#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QModbusRtuSerialMaster>
#include <QModbusDataUnit>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QModbusRtuSerialMaster *modbusMaster;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    void IniModbus();
};

#endif // WIDGET_H
