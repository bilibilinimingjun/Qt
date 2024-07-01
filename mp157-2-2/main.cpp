#include "widget.h"
#include "thread.h"
#include <QApplication>
#include <QLoggingCategory>
#include "savelog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLoggingCategory::setFilterRules(QStringLiteral("qt.modbus* = true"));  //
    //LOGGER
    SaveLog::Instance()->setPath(qApp->applicationDirPath());
    SaveLog::Instance()->start();//通过qInstallMessageHandler 方式捕捉qt.modbus的内容

    Widget w;
    //Thread t;
    w.show();
    //QObject::connect(&w,&Widget::readUnitSIGNAL,&t,&Thread::threadStart);


    return a.exec();
}
