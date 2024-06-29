#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Widget *ui;
    QFont font;
    int offset;
    QTimer *timer;
    QString textContent;
    int textContentWidth;

private slots:
    void onTimerTimeOut();
};
#endif // WIDGET_H
