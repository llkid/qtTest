#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QWidget>
#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QLineEdit *parent = nullptr);
    bool event(QEvent *event);

protected:
    void keyPressEvent(QKeyEvent *event);

signals:

public slots:
};

#endif // MYLINEEDIT_H
