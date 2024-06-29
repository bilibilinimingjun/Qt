#include "rich.h"
#include "ui_rich.h"

Rich::Rich(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rich),
    richMoney(500)
{
    ui->setupUi(this);
}

Rich::~Rich()
{
    delete ui;
}

qreal Rich::money() const
{
    return richMoney;
}

void Rich::setMoney(qreal m)
{
    richMoney += m;
    ui->moneyLabel->setText(QString::number(richMoney) + "万");
}
