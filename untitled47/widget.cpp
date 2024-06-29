#include "widget.h"
#include "ui_widget.h"
#include <QValueAxis>     //坐标轴类
#include <QSplineSeries>   //曲线
#include <QLineSeries>     //折线

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 1.创建一个图表视图
    // QChartView *chartView = new QChartView();

    // 2.创建一个图表
    QChart *chart = new QChart();

    // 3.创建坐标轴
    QValueAxis *valueAxisX = new QValueAxis();
    QValueAxis *valueAxisY = new QValueAxis();

    //4. 设置坐标轴范围
    valueAxisX->setRange(0, 5000);
    valueAxisY->setRange(0, 100);

    //5. 设置坐标轴的标题和显示格式
    valueAxisX->setTitleText("时间/ms");
    valueAxisY->setTitleText("温度/°C");
    valueAxisX->setLabelFormat("%d");
    valueAxisY->setLabelFormat("%d");

    valueAxisX->setTickCount(10);   //分界数量

    //6. 图表添加坐标轴
    chart->createDefaultAxes();
    chart->addAxis(valueAxisX, Qt::AlignBottom);
    chart->addAxis(valueAxisY, Qt::AlignLeft);

    //7. 设置图表的标题以及图例显示选择
    chart->setTitle("温度与时间曲线");
    chart->legend()->setVisible(false);

    //8. 创建曲线对象添加它的点，设置曲线的颜色
    QSplineSeries *splineSeries = new QSplineSeries();
    splineSeries->append(0, 50);
    splineSeries->append(1000, 55);
    splineSeries->append(2000, 80);

    QPen pen(QColor(0xFF5566));
    splineSeries->setPen(pen);

    //9. 图表添加曲线
    chart->addSeries(splineSeries);

    //10. ！！！将曲线的数据与坐标轴相连！！！注意，这个要在图表添加曲线之后
    //附属到坐标轴上
    splineSeries->attachAxis(valueAxisX);
    splineSeries->attachAxis(valueAxisY);

    //11. 将图表放置与图表视图中
    ui->chartView->setChart(chart);

}

Widget::~Widget()
{
    delete ui;
}

