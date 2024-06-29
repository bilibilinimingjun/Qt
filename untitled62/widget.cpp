#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 1. 初始化列表
    // 1.1 添加4列
    ui->twStudent->setColumnCount(4);

    QStringList horizontalList;
    horizontalList << "姓名";
    horizontalList << "姓别";
    horizontalList << "年龄";
    horizontalList << "籍贯";

    ui->twStudent->setHorizontalHeaderLabels(horizontalList);  //设置表头内容

    // 1.2 设置列宽度
    ui->twStudent->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //填充满表格

    // 1.3 添加几行初始化数据
    appendOneRow("王瑞民", "男", 24, "召唤师峡谷");
    appendOneRow("李博", "男", 23, "召唤师峡谷");
    appendOneRow(" ", "女", 22, "山西");

    // 2. 设置行表头是否显示
    if(ui->twStudent->horizontalHeader()->isHidden()){
        ui->cboHHeader->setChecked(false);
    } else {
        ui->cboHHeader->setChecked(true);
    }
    //信号槽，设置表头不可见
    connect(ui->cboHHeader, &QCheckBox::stateChanged, this, [=](int state) {
        if(state == Qt::Checked) {
            ui->twStudent->horizontalHeader()->show();
        } else {
            ui->twStudent->horizontalHeader()->hide();
        }
    });
    // 3. 设置列表头是否显示
    if(ui->twStudent->verticalHeader()->isHidden()){
        ui->cboVHeader->setChecked(false);
    } else {
        ui->cboVHeader->setChecked(true);
    }
    //信号槽，设置表头不可见
    connect(ui->cboVHeader, &QCheckBox::stateChanged, this, [=](int state) {
        if(state == Qt::Checked) {
            ui->twStudent->verticalHeader()->show();
        } else {
            ui->twStudent->verticalHeader()->hide();
        }
    });

    // 4. 设置交替显示背景色
    if(ui->twStudent->alternatingRowColors()){
        ui->cboAltemate->setChecked(true);
    } else {
        ui->cboAltemate->setChecked(false);
    }
    connect(ui->cboAltemate, &QCheckBox::stateChanged, this, [=](int state) {
        if(state == Qt::Checked) {
            ui->twStudent->setAlternatingRowColors(true);
        } else {
            ui->twStudent->setAlternatingRowColors(false);
        }
    });

    // 5. 单元格是否可编辑
    int trigger = ui->twStudent->editTriggers();
    if (trigger == QAbstractItemView::NoEditTriggers) {
        ui->cboEditCell->setChecked(false);
    } else {
        ui->cboEditCell->setChecked(true);
    }
    connect(ui->cboEditCell, &QCheckBox::stateChanged, this, [=](int state) {
        if(state == Qt::Checked) {
            ui->twStudent->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
        } else {
            ui->twStudent->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }
    });

    // 6. 设置单元格选择还是行选择
    int selectionBehavior = ui->twStudent->selectionBehavior();
    if (selectionBehavior == QAbstractItemView::SelectItems) {
        ui->rbCell->setChecked(true);
    } else if (selectionBehavior == QAbstractItemView::SelectItems) {
        ui->rbRow->setChecked(true);
    }

    mButtonGroupSelect = new QButtonGroup(this);
    mButtonGroupSelect->addButton(ui->rbRow, 1);
    mButtonGroupSelect->addButton(ui->rbCell, 0);
    connect(ui->rbCell, &QRadioButton::clicked, this, &Widget::onSelectionRadioButtonClicked);
    connect(ui->rbRow, &QRadioButton::clicked, this, &Widget::onSelectionRadioButtonClicked);

    // 7. 点击单元格时，将数据显示到文本框
    connect(ui->twStudent, &QTableWidget::itemClicked, this, &Widget::onItemClicked);
}

Widget::~Widget()
{
    delete ui;
}

// 1.3 添加几行初始化数据
void Widget::appendOneRow(QString name, QString gender, int age, QString province)
{
    int count = ui->twStudent->rowCount();  //获取行数

    ui->twStudent->setRowCount(count + 1);  //添加一行
    //初始化行成员数据
    QTableWidgetItem *nameItem = new QTableWidgetItem(name);
    QTableWidgetItem *genderItem = new QTableWidgetItem(gender);
    QTableWidgetItem *ageItem = new QTableWidgetItem(QString::number(age));
    QTableWidgetItem *provinceItem = new QTableWidgetItem(province);

    nameItem->setTextAlignment(Qt::AlignCenter);
    genderItem->setTextAlignment(Qt::AlignCenter);
    ageItem->setTextAlignment(Qt::AlignCenter);
    provinceItem->setTextAlignment(Qt::AlignCenter);

    //传入行成员
    ui->twStudent->setItem(count, 0, nameItem);
    ui->twStudent->setItem(count, 1, genderItem);
    ui->twStudent->setItem(count, 2, ageItem);
    ui->twStudent->setItem(count, 3, provinceItem);

}

//插入一行
void Widget::insertOneRow(int currentRow, QString name, QString gender, int age, QString province)
{
    ui->twStudent->insertRow(currentRow);  //插入的是一个空行

    QTableWidgetItem *nameItem = new QTableWidgetItem(name);
    QTableWidgetItem *genderItem = new QTableWidgetItem(gender);
    QTableWidgetItem *ageItem = new QTableWidgetItem(QString::number(age));
    QTableWidgetItem *provinceItem = new QTableWidgetItem(province);

    nameItem->setTextAlignment(Qt::AlignCenter);
    genderItem->setTextAlignment(Qt::AlignCenter);
    ageItem->setTextAlignment(Qt::AlignCenter);
    provinceItem->setTextAlignment(Qt::AlignCenter);

    //传入行成员
    ui->twStudent->setItem(currentRow, 0, nameItem);
    ui->twStudent->setItem(currentRow, 1, genderItem);
    ui->twStudent->setItem(currentRow, 2, ageItem);
    ui->twStudent->setItem(currentRow, 3, provinceItem);
}

//选择功能
void Widget::onSelectionRadioButtonClicked()
{
    int checkedId = mButtonGroupSelect->checkedId();
    if (checkedId == 0){
        ui->twStudent->setSelectionMode(QAbstractItemView::SingleSelection);   //单行选择
        ui->twStudent->setSelectionBehavior(QAbstractItemView::SelectItems);   //选中单元格
    } else {
        ui->twStudent->setSelectionMode(QAbstractItemView::SingleSelection);   //单行选择
        ui->twStudent->setSelectionBehavior(QAbstractItemView::SelectRows);    //选中行
    }
}

//输出到lineEide
void Widget::onItemClicked(QTableWidgetItem *item)
{
    int row = item->row();  //获取到选择的行数

    QString name = ui->twStudent->item(row, 0)->text();   //获取表格文本
    QString gender = ui->twStudent->item(row, 1)->text();   //获取表格文本
    QString age = ui->twStudent->item(row, 2)->text();   //获取表格文本
    QString province = ui->twStudent->item(row, 3)->text();   //获取表格文本

    ui->leName->setText(name);          //将文本输出到lineEidt
    ui->leGender->setText(gender);
    ui->leAge->setText(age);
    ui->leProvince->setText(province);
}

//添加一行
void Widget::on_btnAppend_clicked()
{
    QString name = ui->leName->text();
    QString gender = ui->leGender->text();
    int age = ui->leAge->text().toInt();
    QString province = ui->leProvince->text();

    appendOneRow(name, gender, age, province);
}

void Widget::on_btnInsert_clicked()
{
    QString name = ui->leName->text();
    QString gender = ui->leGender->text();
    int age = ui->leAge->text().toInt();
    QString province = ui->leProvince->text();

    int currentRow = ui->twStudent->currentRow();  //当前选中哪一行

    insertOneRow(currentRow, name, gender, age, province);  //插入一行
}

//删除当前行
void Widget::on_btnDelete_clicked()
{
    int currentRow = ui->twStudent->currentRow();
    ui->twStudent->removeRow(currentRow);
}

void Widget::on_btnModify_clicked()
{
    QString name = ui->leName->text();
    QString gender = ui->leGender->text();
    int age = ui->leAge->text().toInt();
    QString province = ui->leProvince->text();

    int currentRow = ui->twStudent->currentRow();

    QTableWidgetItem *nameItem = new QTableWidgetItem(name);
    QTableWidgetItem *genderItem = new QTableWidgetItem(gender);
    QTableWidgetItem *ageItem = new QTableWidgetItem(QString::number(age));
    QTableWidgetItem *provinceItem = new QTableWidgetItem(province);

    nameItem->setTextAlignment(Qt::AlignCenter);
    genderItem->setTextAlignment(Qt::AlignCenter);
    ageItem->setTextAlignment(Qt::AlignCenter);
    provinceItem->setTextAlignment(Qt::AlignCenter);

    //传入行成员
    ui->twStudent->setItem(currentRow, 0, nameItem);
    ui->twStudent->setItem(currentRow, 1, genderItem);
    ui->twStudent->setItem(currentRow, 2, ageItem);
    ui->twStudent->setItem(currentRow, 3, provinceItem);
}

void Widget::on_btnStyleSheet_clicked()
{

}
