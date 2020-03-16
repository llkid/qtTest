#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QCursor cursor;
    cursor.setShape(Qt::OpenHandCursor);
    setCursor(cursor);
    setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        offet = event->globalPos() - pos();
    } else if (event->button() == Qt::RightButton) {
        QCursor cursor(QPixmap(":/images/1.jpg"));
        QApplication::setOverrideCursor(cursor);
    }
}
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QApplication::restoreOverrideCursor();
}
void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (windowState() != Qt::WindowFullScreen)
            setWindowState(Qt::WindowFullScreen);
        else
            setWindowState(Qt::WindowNoState);
    }
}
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint temp;
    temp = event->globalPos() - pos();
    move(temp);
}
void Widget::mouseWheelEvent(QWheelEvent *event)
{
    if (event->delta() > 0)
        ui->textEdit->zoomIn();
    else
        ui->textEdit->zoomOut();
}
