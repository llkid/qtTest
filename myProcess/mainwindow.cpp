#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

//进程加载
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&myProcess, SIGNAL(readyRead()), this, SLOT(showResult()));

    connect(&myProcess, SIGNAL(stateChanged(QProcess::ProcessState)), this, SLOT(showState(QProcess::ProcessState)));

    connect(&myProcess, SIGNAL(errorOccurred(QProcess::ProcessError)), this, SLOT(showError()));

    connect(&myProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(showFinished(int, QProcess::ExitStatus)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString program("cmd.exe");
    QStringList arguments;
    arguments << "/c dir&pause";
    myProcess.start(program, arguments);
}

void MainWindow::showResult()
{
    qDebug() << "Results: " << endl
             << QString(myProcess.readAll());
}

void MainWindow::showState(QProcess::ProcessState state)
{
    qDebug() << "showStates: ";
    if (state == QProcess::NotRunning) {
        qDebug() << "not running";
    } else if (state == QProcess::Starting) {
        qDebug() << "Staring";
    } else {
        qDebug() <<"Running";
    }
}

void MainWindow::showError()
{
    qDebug() << "Errors: " << endl << myProcess.errorString();
}

void MainWindow::showFinished(int exitCode, QProcess::ExitStatus exitState)
{
    qDebug() << "showFinished: " << exitCode << exitState;
}
