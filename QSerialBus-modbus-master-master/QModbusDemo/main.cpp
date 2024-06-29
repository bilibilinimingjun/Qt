#include "mainwindow.h"
#include <QApplication>
#include <QLoggingCategory>
#include "savelog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLoggingCategory::setFilterRules(QStringLiteral("qt.modbus* = true"));
    //LOGGER
    SaveLog::Instance()->setPath(qApp->applicationDirPath());
    SaveLog::Instance()->start();//通过qInstallMessageHandler 方式捕捉qt.modbus的内容

    MainWindow w;
    w.show();

    return a.exec();
}
