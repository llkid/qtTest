#ifndef HELLODIALOG_H
#define HELLODIALOG_H

#include <QObject>
#include <QDialog>

namespace Ui {
class HelloDialog;
}

class HelloDialog : public QDialog
{
    Q_OBJECT
public:
    explicit HelloDialog(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::HelloDialog *ui;
};

#endif // HELLODIALOG_H
