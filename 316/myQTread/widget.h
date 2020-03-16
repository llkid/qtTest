#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDialog>
#include "mythread.h"

namespace Ui {
class Widget;
}

class Widget : public QDialog
{
    Q_OBJECT

public:
    explicit Widget(QDialog *parent = nullptr);
    ~Widget();

private slots:
    void on_startBtn_clicked();

    void on_stopBtn_clicked();

private:
    Ui::Widget *ui;

    MyThread thread;
};

#endif // WIDGET_H
