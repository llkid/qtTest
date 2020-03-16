#include "mylineedit.h"
#include <QKeyEvent>
#include <QDebug>


MyLineEdit::MyLineEdit(QLineEdit *parent) : QLineEdit(parent)
{

}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("MyLineEdit 键盘按下事件");
    QLineEdit::keyPressEvent(event);
    event->ignore();
}

bool MyLineEdit::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        qDebug() << tr("MyLineEdit event() execute here");
    }

    return QLineEdit::event(event);
}
