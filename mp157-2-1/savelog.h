#ifndef SAVELOG_H
#define SAVELOG_H

#include <QObject>
#include <QDateTime>
class QFile;
class QTcpSocket;
class QTcpServer;
#define QDATE qPrintable(QDate::currentDate().toString("yyyy-MM-dd"))
#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT SaveLog : public QObject
        #else
class SaveLog : public QObject
        #endif
{
    Q_OBJECT
public:
    static SaveLog *Instance();
    explicit SaveLog(QObject *parent = 0);
    ~SaveLog();

    void SendLogMsgD(QString str);
private:
    static QScopedPointer<SaveLog> self;
    //存储程序信息的文件对象
    QFile *file;
    //日志文件路径
    QString path;
    //日志文件名称
    QString name;
    //存储程序信息的日志文件完整名称
    QString fileName;

signals:
    void send(const QString &content);
    void sigModbusData(QString,int);
public slots:
    //启动日志服务
    void start();
    //暂停日志服务
    void stop();
    //保存日志
    void save(const QString &content);
    //设置日志文件存放路径
    void setPath(const QString &path);
};


#endif // SAVELOG_H
