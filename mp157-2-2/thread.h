#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <widget.h>

class Thread : public QObject
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = nullptr);

signals:
public slots:
    void threadStart(int slaveId, int startAddress, int readNum);
private:
    QThread m_thread;
    Widget m_data;
};

#endif // THREAD_H
