#include "frame.h"
#include "ui_frame.h"
#include <QTime>
#include <QTimer>

Frame::Frame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);
}

Frame::~Frame()
{
    delete ui;
}

 void Frame::display(QString date)
 {
     ui->lcdNumber->display(date);
     QTimer* timer = new QTimer(this);
     timer->start(1000);
     QTimer::singleShot(10000, this, SLOT(close()));
 }
