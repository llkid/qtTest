#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QThread *parent = nullptr);

    void stop();

protected:
    void run();

private:
    volatile bool stopped;

signals:

public slots:
};

#endif // MYTHREAD_H
