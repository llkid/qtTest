#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile *tempFile = new QFile;
    tempFile->setFileName("E:\\qt\\QtProgram\\LaserTest\\txt\\a.txt");
    if (!tempFile->open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "open file failed!";
    } else {
        qDebug() << "open file success!";
    }

    QTextStream in(tempFile);
    QString readLine = in.readAll();
    QStringList tempRead = readLine.split("\n", QString::SkipEmptyParts);

    for (int j = 0; j < tempRead.size(); ++j) {
        QStringListIterator iter(tempRead[j].split("\t", QString::SkipEmptyParts));
        for (int i = 0; iter.hasNext(); ++i) {
            switch (i) {
            case 0:
                close_location.append(iter.next().toInt());
                break;
            case 1:
                close_rank.append(iter.next().toInt());
                break;
            case 2:
                close_ethor.append(iter.next().toDouble());
                break;
            case 3:
                long_ethor.append(iter.next().toDouble());
                break;
            case 4:
                close_distance.append(iter.next().toInt());
                break;
            default:
                break;
            }
        }

    }

    qDebug() << "location : " << close_location;
    qDebug() << "close_rank : " << close_rank;
    qDebug() << "close_ethor : " << close_ethor;
    qDebug() << "long_ethor : " << long_ethor;
    qDebug() << "close_ethor : " << close_distance;

    tempFile->close();

}

MainWindow::~MainWindow()
{
    delete ui;
}
