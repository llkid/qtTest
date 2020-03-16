#include <QtCore>
#include <stdio.h>
#include <stdlib.h>
#include <QDebug>


const int dataSize = 10;
const int bufferSize = 5;
char buffer[bufferSize];
QSemaphore freeBytes(bufferSize);
QSemaphore usedBytes;

class Producer : public QThread
{
public:
    void run();
};

void Producer::run()
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    for (int i = 0; i < dataSize; ++i) {
        freeBytes.acquire();
        buffer[i % bufferSize] = "ACGT"[(int)qrand() % 4];
        qDebug() << QString("producre: %1").arg(buffer[i % bufferSize]);
        usedBytes.release();
    }
}

class Consumer : public QThread
{
public:
    void run();
};

void Consumer::run()
{
    for (int i = 0; i < dataSize; ++i) {
        usedBytes.acquire();
        qDebug() << QString("consumer: %1").arg(buffer[i % bufferSize]);
        freeBytes.release();
    }
}

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    Producer prodecer;
    Consumer consumer;
    prodecer.start();
    consumer.start();
    prodecer.wait();
    consumer.wait();

    return app.exec();
}
