#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void showValue(int);

    void on_pushButton_clicked();

signals:
    void sendValueToFrame(QString);


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
