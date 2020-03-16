#include <QtCore>
#include <stdio.h>
#include <stdlib.h>
#include <QDebug>

const int DataSize = 10;
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
    for (int i = 0; i < DataSize; ++i) {
        freeBytes.acquire();
        buffer[i % bufferSize] = "ACGT"[static_cast<int>(qrand()) % 4];
        qDebug() << QString("producer: %1").arg(buffer[i % bufferSize]);
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
    for (int i = 0; i < DataSize; ++i) {
        usedBytes.acquire();
        qDebug() << QString("consumer: %1").arg(buffer[i % bufferSize]);
        freeBytes.release();
    }
}

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    Producer producer;
    Consumer consumer;
    producer.start();
    consumer.start();
    producer.wait();
    consumer.wait();
    return app.exec();
}
