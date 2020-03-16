#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QList>
#include <QDebug>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;

    QList<int> close_location;
    QList<int> close_rank;
    QList<double> close_ethor;
    QList<double> long_ethor;
    QList<int> close_distance;
};

#endif // MAINWINDOW_H
