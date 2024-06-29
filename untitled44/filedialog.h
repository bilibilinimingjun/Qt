#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QDialog>

namespace Ui {
class FileDialog;
}

class FileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileDialog(QWidget *parent = nullptr);
    ~FileDialog();
    QString getTextEditContent();

private slots:

    void on_pushButton_released();

    void on_pushButton_pressed();

    void on_pushButton_clicked();

private:
    Ui::FileDialog *ui;
};

#endif // FILEDIALOG_H
