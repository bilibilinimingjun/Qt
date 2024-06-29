#ifndef PAGE_H
#define PAGE_H

#include <QDialog>

namespace Ui {
class Page;
}

class Page : public QDialog
{
    Q_OBJECT

public:
    explicit Page(QWidget *parent = nullptr);
    ~Page();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Page *ui;
};

#endif // PAGE_H
