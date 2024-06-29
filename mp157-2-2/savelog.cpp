#include "savelog.h"
#include "iostream"
#include "qmutex.h"
#include "qfile.h"
#include "qdatetime.h"
#include "qapplication.h"
#include "qtimer.h"
#include "qstringlist.h"
#include <QtNetwork/qtcpserver.h>
#include <QtNetwork/qtcpsocket.h>

#include <QDebug>
#include <QDir>
#define QDATE qPrintable(QDate::currentDate().toString("yyyy-MM-dd"))
#define QDATETIME qPrintable(QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss"))
#define QDATETIME_zzz qPrintable(QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss zzz"))
//#pragma execution_character_set("utf-8")
//日志重定向
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
void Log(QtMsgType type, const char *msg)
#else
void Log(QtMsgType type, const QMessageLogContext &, const QString &msg)
#endif
{
    //加锁,防止多线程中qdebug太频繁导致崩溃
    static QMutex mutex;
    QMutexLocker locker(&mutex);
    QString content;

    //这里可以根据不同的类型加上不同的头部用于区分
    switch (type) {
    case QtDebugMsg:
        content = QString("%1").arg(msg);
        break;

    case QtWarningMsg:
        content = QString("QtWarningMsg: %1").arg(msg);
        break;

    case QtCriticalMsg:
        content = QString("QtCriticalMsg: %1").arg(msg);
        break;

    case QtFatalMsg:
        content = QString("QtFatalMsg: %1").arg(msg);
        break;
    default: break;
    }

    SaveLog::Instance()->save(content);
}

QScopedPointer<SaveLog> SaveLog::self;
SaveLog *SaveLog::Instance()
{
    if (self.isNull()) {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if (self.isNull()) {
            self.reset(new SaveLog);
        }
    }
    return self.data();
}
//新建文件夹
void newDir(const QString &dirName)
{
    QString strDir = dirName;

    //如果路径中包含斜杠字符则说明是绝对路径
    //linux系统路径字符带有 /  windows系统 路径字符带有 :/
    if (!strDir.startsWith("/") && !strDir.contains(":/")) {
        strDir = QString("%1/%2").arg(qApp->applicationDirPath()).arg(strDir);
    }

    QDir dir(strDir);
    if (!dir.exists()) {
        dir.mkpath(strDir);
    }
}
SaveLog::SaveLog(QObject *parent) : QObject(parent)
{
    qDebug() << "SaveLog";
    file = new QFile(this);
    //默认取应用程序根目录
    path = qApp->applicationDirPath();
    //默认取应用程序可执行文件名称
    QString str = qApp->applicationFilePath();
    QStringList list = str.split("/");
    name = list.at(list.count() - 1).split(".").at(0);
    fileName = "";
    newDir("Log");
}

SaveLog::~SaveLog()
{
    qDebug() << "~SaveLog";
    file->close();
}

//安装日志钩子,输出调试信息到文件,便于调试
void SaveLog::start()
{
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    qInstallMsgHandler(Log);
#else
    qInstallMessageHandler(Log);
#endif
}

//卸载日志钩子
void SaveLog::stop()
{
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    qInstallMsgHandler(0);
#else
    qInstallMessageHandler(0);
#endif
}

void SaveLog::save(const QString &content)
{
    if(1)
    {
        QString msg = static_cast<QString>(content);
        std::cout << msg.toLocal8Bit().data() << std::endl;
        //方法改进:之前每次输出日志都打开文件,改成只有当日期改变时才新建和打开文件
        if(content.contains("(RTU client) Sent Serial ADU:"))
        {
            //(RTU client) Sent Serial ADU: 0xfe0300000029901b
            //std::cout << "SendMsg" << msg.toUtf8().data() << std::endl;
            msg = msg.remove(msg.indexOf("(RTU client) Sent Serial ADU:"),32);

            msg = msg.left(msg.size());
            msg = msg.toUpper();
            int n = msg.length();
            while(n-2 > 0)
            {
                n = n - 2;
                msg.insert(n," ");
            }
            emit sigModbusData(msg,0);
            //std::cout << "SendMsg:  " << msg.toLocal8Bit().data() << std::endl;
        }
        else if(content.contains("(RTU client) Received ADU:"))
        {
            //std::cout << "RecvMsg" << msg.toLocal8Bit().data() << std::endl;
            msg = msg.remove(msg.indexOf("(RTU client) Received ADU:"),28);
            msg = msg.left(msg.size()-1);
            msg = msg.toUpper();
            int n = msg.length();
            while(n-2 > 0)
            {
                n = n - 2;
                msg.insert(n," ");
            }
            emit sigModbusData(msg,1);
            //std::cout << "Received:  " << msg.toLocal8Bit().data() << std::endl;
        }
        else if(!content.contains("(RTU client)"))
        {
            if(this->fileName.isEmpty())
            {
                QString fileName = QString("%1/Log/%2_log_%3.txt").arg(path).arg(name).arg(QDATETIME);
                if (this->fileName != fileName) {
                    this->fileName = fileName;
                    if (file->isOpen()) {
                        file->close();
                    }

                    file->setFileName(fileName);
                    file->open(QIODevice::WriteOnly | QIODevice::Append | QFile::Text);
                }
            }

            QTextStream logStream(file);
            logStream << QString("%1--Debug     %2").arg(QDATETIME_zzz).arg(msg) << "\n";
        }
    }
}

void SaveLog::setPath(const QString &path)
{
    this->path = path;
}



