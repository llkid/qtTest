#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDateTime>
#include <QDebug>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void task();

    void showChildWidget();

    void on_btn2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
