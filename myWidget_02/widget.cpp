#include "widget.h"
#include "ui_widget.h"
#include <QDialog>
#include "mydialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QDialog *dialog = new QDialog(this);
//    dialog->show();
//    dialog->exec();
//    QDialog dialog(this);
//    dialog.resize(400, 100);
//    dialog.exec();
//    QDialog *dialog = new QDialog(this);
//    dialog->setModal(true);
//    dialog->setWindowTitle("dialog");
//    dialog->show();
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(showChildDialog()));
}

void Widget::showChildDialog()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_3_clicked()
{
    close();
    myDialog dlg;
    if(dlg.exec() == QDialog::Accepted) show();
}
