#include "mainwindow.h"
#include <QApplication>
#include "mp4.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Mp4 mp4;
    if (mp4.exec() == QDialog::Accepted) {
        w.show();

        return a.exec();
    } else {
        return 0;
    }


}
