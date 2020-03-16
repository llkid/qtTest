#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startBtn_clicked()
{
    thread.start();
    ui->startBtn->setEnabled(false);
    ui->stopBtn->setEnabled(true);
}

void Widget::on_stopBtn_clicked()
{
    if (thread.isRunning()) {

        thread.stop();
        ui->startBtn->setEnabled(true);
        ui->stopBtn->setEnabled(false);
//        close();
    }
}
