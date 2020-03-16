#include "widget.h"
#include <QApplication>
#include <QDebug>
#include "mydialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    myDialog dialog;
    if(dialog.exec() == QDialog::Accepted){
        w.show();
        return  a.exec();
    } else {
        return  0;
    }
//    QWidget widget;
//    w.resize(600, 400);
//    widget.setWindowTitle(QString("title"));
//    qDebug() << widget.windowTitle();
//    widget.setParent(&w);
//    widget.resize(400, 300);
//    w.move(200, 100);
//    widget.show();
//    int x = widget.x();
//    qDebug("x: %d", x);
//    int y = widget.y();
//    qDebug("y: %d", y);
//    QRect geometry = w.geometry();
//    QRect fram = w.frameGeometry();
//    qDebug() << "geometry: " << geometry << "framgeometry: " << fram;
//    widget.show();
//    w.show();


//    return a.exec();
}
