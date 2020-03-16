#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mp4.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btn1, SIGNAL(clicked()), this, SLOT(showChildWidget()));
    connect(ui->btn1, SIGNAL(clicked()), this, SLOT(task()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::task()
{
    qDebug() << "Qt-->";
}

void MainWindow::showChildWidget()
{
    QWidget* widget = new QWidget(this);
    widget->show();
}

void MainWindow::on_btn2_clicked()
{
    close();
    Mp4 mp4;
    if (mp4.exec() == QDialog::Accepted)
        show();
}
