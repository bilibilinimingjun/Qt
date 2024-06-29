#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public:
    void appendOneRow(QString name, QString gender, int age, QString province);
    void insertOneRow(int currentRow, QString name, QString gender, int age, QString province);

public slots:
    void onSelectionRadioButtonClicked();
    void onItemClicked(QTableWidgetItem *item);

private slots:
    void on_btnAppend_clicked();

    void on_btnInsert_clicked();

    void on_btnDelete_clicked();

    void on_btnModify_clicked();

    void on_btnStyleSheet_clicked();

private:
    Ui::Widget *ui;

    QButtonGroup *mButtonGroupSelect;
};
#endif // WIDGET_H
