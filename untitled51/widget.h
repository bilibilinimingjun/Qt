#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>

class MyThread;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    MyThread *myThread;
};


class MyThread : public QThread
{
    Q_OBJECT

public:
    MyThread(QWidget *parent = nullptr) {
        Q_UNUSED(parent)
    }
    ~MyThread();
    //run()方法在新的线程里面
    void run() override;
};
#endif // WIDGET_H
