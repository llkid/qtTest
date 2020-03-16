#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"
#include "frame.h"
#include <QDateTime>
#include <QDebug>
#include <QTimer>
#include <QTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->calendarWidget->showToday();
    ui->calendarWidget->hide();

    Dialog* dialog = new Dialog(this);
    connect(dialog, &Dialog::dlgReturn, this, &Widget::showValue);
    dialog->show();

    Frame* frame = new Frame(this);
    frame->move(100,0);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::showValue(int value)
{
    ui->label->setText(tr("获取的值是：%1").arg(value));
}

void Widget::on_pushButton_clicked()
{
    qDebug() << "send success";
    QString date_str;
    date_str = QTime::currentTime().toString("hh:mm:ss");
    emit sendValueToFrame(date_str);
}
