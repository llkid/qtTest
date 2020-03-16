    #include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTimer>
#include <QTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    id1 = startTimer(1000);
    id2 = startTimer(2000);
    id3 = startTimer(3000);
    const char* msg = "日本";
    qDebug(msg);
//    timer_test(QTimerEvent *e, this);
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::timerUpdate);
    timer->start(1000);
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    QTimer::singleShot(10000, this, SLOT(close()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *e)
{
//    switch (e->timerId()) {
//        case id1:
//            qDebug() << "timer1";
//            break;
//        case id2:
//            qDebug() << "timer2";
//            break;
//        case id3:
//            qDebug() << "timer3";
//            break;
//        default:
//            break;
//    }
    if (e->timerId() == id1) {
        qDebug() << "timer1" << id1;
    } else if (e->timerId() == id2){
        qDebug() << "timer2" << id2;
    } else {
         qDebug() << "timer3" << id3;
    }
}

void Widget::timer(QTimerEvent *e)
{
    switch (e->timerId()) {
        case 1:
            qDebug() << "timer1";
            break;
        case 2:
            qDebug() << "timer2";
            break;
        case 3:
            qDebug() << "timer3";
            break;
        default:
            break;
    }
}

void timer_test(QTimerEvent* e, void* userData)
{
    Widget* app = static_cast<Widget*>(userData);
    if (app)
        app->timer(e);
}

void Widget::timerUpdate()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    if (time.second() % 2 == 0)
        text[2] = ' ';
    ui->lcdNumber->display(text);

    int rand = qrand() % 3;
    ui->lcdNumber->move(rand, rand);
}
