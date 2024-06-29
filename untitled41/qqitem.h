#ifndef QQITEM_H
#define QQITEM_H

#include <QWidget>

namespace Ui {
class QQitem;
}

class QQitem : public QWidget
{
    Q_OBJECT

public:
    explicit QQitem(QString icon, bool flag, QString name, QWidget *parent = nullptr);
    ~QQitem();

private:
    Ui::QQitem *ui;
};

#endif // QQITEM_H
