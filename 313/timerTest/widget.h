#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void timerEvent(QTimerEvent *e);

private:
    Ui::Widget *ui;

    int id1, id2, id3;
    static constexpr auto tvar = "qwe";

private:
    void timer(QTimerEvent *e);
    friend void timer_test(QTimerEvent* e, void* userData);

private slots:
    void timerUpdate();
};

void timer_test(QTimerEvent* e, void* userData);

#endif // WIDGET_H
