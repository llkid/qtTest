#include "widget.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    w.show();

    return a.exec();
}
