#include "mythread.h"
#include <QDebug>

MyThread::MyThread()
{
    stopped = false;
}

void MyThread::stop()
{
    stopped = true;
}

void MyThread::run()
{
    qreal i = 0;
    while (!stopped) {
        qDebug() << QString("in mythread: %1").arg(i++);
    }
    stopped = false;
}
