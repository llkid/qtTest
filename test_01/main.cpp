#include <QApplication>
#include "hellodialog.h"
#include "test.h"
#include <QDebug>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloDialog w;
    w.show();

    return a.exec();
}
