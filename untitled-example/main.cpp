#include "widget.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/style.qss");
    /*判断文件是否存在*/
    if (file.exists()) {
        file.open(QFile::ReadOnly);                           //以只读的方式打开
        QString styleSheet = QLatin1String(file.readAll());   //以字符串的方式保存读出结果
        qApp->setStyleSheet(styleSheet);                      //设置全局样式
        file.close();                                         //关闭文件
    }

    Widget w;
    w.show();
    return a.exec();
}
