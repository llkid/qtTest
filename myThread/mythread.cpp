#include "mythread.h"

#include <QDebug>

MyThread::MyThread(QThread *parent) : QThread(parent)
{
    stopped = false;
}

void MyThread::run()
{
    qreal i = 0;
    while (!stopped) {
        qDebug() << QString("in MyThread: %1").arg(i++);
    }
    stopped = false;
}

void MyThread::stop()
{
    stopped = true;
}
