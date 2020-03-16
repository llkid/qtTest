/*
这里是对组合键的使用示例,但在按下每两次会再次出发效果
*/

#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    keyUp = false;
    keyLeft = false;
    move = false;

    setFocus();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
//    if (event->key() == Qt::Key_Up)  {
//        if (event->isAutoRepeat())
//            return;
//        keyUp = true;
//    } else if (event->key() == Qt::Key_Left) {
//        if (event->isAutoRepeat())
//            return;
//        keyLeft = true;
//    }
    switch (event->key()) {
        case Qt::Key_Up:
            if (event->isAutoRepeat())
                return;
            keyUp = true;
            break;
        case Qt::Key_Left:
        if (event->isAutoRepeat())
            return;
            keyLeft = true;
            break;
        default:
            break;
    }
}
void Widget::keyReleaseEvent(QKeyEvent *event)
{
//    if (event->key() == Qt::Key_Up)  {
//        if (event->isAutoRepeat())
//            return;
//        keyUp = false;
//        if (move) {
//            move = false;
//            return;
//        }
//        if (keyLeft) {
//            ui->pushButton->move(30, 80);
//            move = true;
//        } else {
//            ui->pushButton->move(120, 80);
//        }
//    } else if (event->key() == Qt::Key_Left) {
//        if (event->isAutoRepeat())
//            return;
//        keyLeft = false;
//        if (move) {
//            move = false;
//            return;
//        }
//        if (keyUp) {
//            ui->pushButton->move(30, 80);
//            move = true;
//        } else {
//            ui->pushButton->move(30, 120);
//        }
//    } else if (event->key() == Qt::Key_Down) {
//        ui->pushButton->move(120, 120);
//    }

    switch (event->key()) {
        case Qt::Key_Up:
            if (event->isAutoRepeat())
                return;
            keyUp = false;
            if (move) {
                move = false;
                return;
            }
            if (keyLeft) {
                ui->pushButton->move(30, 80);
                move = true;
            } else {
                ui->pushButton->move(30, 120);
            }
            break;
        case Qt::Key_Left:
            if (event->isAutoRepeat())
                return;
            keyLeft = false;
            if (move) {
                move = false;
                qDebug() << ++cnt;
                return;
            }
            if (keyUp) {
                ui->pushButton->move(30, 0);
                move = true;
            } else {
                ui->pushButton->move(30, 120);
            }
            break;
        case Qt::Key_Down:
            ui->pushButton->move(120, 120);
            break;
        default:
            break;
    }
}
