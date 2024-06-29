#include "widget.h"
#include "ui_widget.h"
#include "QStringList"
#include "QMessageBox"
#include "QDebug"

int target = 0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(1);          //初始化HEX按钮
    ui->radioButton_2->setChecked(0);
    ui->radioButton->setEnabled(0);          //切换初始化
    ui->radioButton_2->setEnabled(1);

    serialPort = new QSerialPort (this);     //初始化串口类
    //扫描串口，添加到下拉菜单
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->comboBox_2->addItem(info.portName());
    }
    connect(serialPort,SIGNAL(readyRead()),
            this,SLOT(readSerial()));
}

Widget::~Widget()
{
    delete ui;
}


/*ASCII发送模式*/
void Widget::on_radioButton_clicked(bool checked)
{
    if(checked)
    {

        ui->radioButton->setEnabled(0);
        ui->radioButton_2->setEnabled(1);

        QByteArray ascii_data;
        QString temp;
        QString text = ui->textEdit->toPlainText();
        QStringList temp_list = text.split(' ', QString::SkipEmptyParts);
        for(int i = 0;i < temp_list.size();i++)
        {
            ascii_data.append(temp_list[i]);
        }
        temp = QByteArray::fromHex(ascii_data);
        ui->textEdit->setText(temp);

    }
}

void Widget::readSerial()
{
    // 读取数据
    QByteArray arry= serialPort->readAll();
    qDebug() << arry;
    QByteArray framedata = arry.toHex(' ').trimmed().toUpper();
    QString str = QString(framedata);
    ui->textEdit_2->append(str);
}

/*打开串口*/
void Widget::on_pushButton_2_clicked()
{
    if(target == 0)
    {
        // 设置要打开串口的名字
        serialPort->setPortName( ui->comboBox_2->currentText());
        qDebug()<< ui->comboBox_2->currentText();
        // 设置波特率
        serialPort->setBaudRate(ui->comboBox->currentText().toInt());
        qDebug() << ui->comboBox->currentText().toInt();
        // 设置停止位
        serialPort->setStopBits(QSerialPort::StopBits(ui->comboBox_3->currentText().toInt()));
        qDebug() << ui->comboBox_3->currentText().toInt();
        //设置数据位
        serialPort->setDataBits(QSerialPort::DataBits(ui->comboBox_4->currentText().toInt()));
        ui->comboBox_4->currentText().toInt();
        //设置校验位
        switch (ui->comboBox_5->currentIndex())
        {
        case 0:
            serialPort->setParity(QSerialPort::NoParity);
            break;
        case 1:
            serialPort->setParity(QSerialPort::EvenParity);
            break;
        case 2:
            serialPort->setParity(QSerialPort::OddParity);
            break;
        case 3:
            serialPort->setParity(QSerialPort::SpaceParity);
            break;
        case 4:
            serialPort->setParity(QSerialPort::MarkParity);
            break;
        default:
            break;
        }

        //设置流控
        serialPort->setFlowControl(QSerialPort::NoFlowControl);

        if(!serialPort->open(QIODevice::ReadWrite)){

            QMessageBox msgBox;
              msgBox.setText("错误，串口打开失败");
              msgBox.exec();
              qDebug() << __FUNCTION__ << "open fail，error info: " << this->serialPort->errorString();
              return;
        }
        else
        {

                QMessageBox msgBox;
                  msgBox.setText("成功打开串口");
                  msgBox.exec();
                ui->comboBox->setEditable(0);
                ui->comboBox_2->setEditable(0);
                ui->comboBox_3->setEditable(0);
                ui->comboBox_4->setEditable(0);
                ui->comboBox_5->setEditable(0);

                ui->pushButton_2->setText("关闭串口");
                target++;

        }
    }
    else if(target == 1)
    {
        serialPort->close();
        ui->comboBox->setEditable(true);
        ui->comboBox_2->setEditable(true);
        ui->comboBox_3->setEditable(true);
        ui->comboBox_4->setEditable(true);
        ui->comboBox_5->setEditable(true);
        ui->pushButton_2->setText("打开串口");
        target = 0;
    }


}

/*HEX发送模式*/
void Widget::on_radioButton_2_clicked(bool checked)
{
    if(checked)
    {
        ui->radioButton->setEnabled(1);
        ui->radioButton_2->setEnabled(0);
        QString str;
        QByteArray charArray;
        str = ui->textEdit->toPlainText();
        QByteArray bytes = str.toUtf8();
        charArray = bytes.toHex(' ').toUpper();
        ui->textEdit->setText(charArray);
    }
}

/*发送信息*/
void Widget::on_pushButton_3_clicked()
{
    if(ui->radioButton_2->isChecked() == 1)
    {
        serialPort->write(ui->textEdit->toPlainText().toUtf8());
    }
    else if(ui->radioButton->isChecked() == 1)
    {
        QByteArray ascii_data;
        QString temp;
        QString text = ui->textEdit->toPlainText();
        QStringList temp_list = text.split(' ', QString::SkipEmptyParts);
        for(int i = 0;i < temp_list.size();i++)
        {
            ascii_data.append(temp_list[i]);
        }
        temp = QByteArray::fromHex(ascii_data);
        serialPort->write(temp.toUtf8());
    }
    ui->textEdit_2->setText(ui->textEdit->toPlainText());
}

