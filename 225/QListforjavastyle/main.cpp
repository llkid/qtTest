#include <QCoreApplication>
#include <QList>
#include <QListIterator>
#include <QMutableListIterator>
#include <QDebug>

/*
测试 QListIterator and QMutableListIterator
*/
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString> list;
    list << "A" << "B" << "C" << "D";
    //QListIterator 这里的操作是只读操作，不能修改
    QListIterator<QString> i(list);
    qDebug() << "the forward is: ";
    while (i.hasNext()) {
        qDebug() << i.next();
    }
    qDebug() << "the backward is: ";
    while (i.hasPrevious()) {
        qDebug() << i.previous();
    }

    //QMutableListIterator 可以修改list的成员
    QMutableListIterator<QString> j(list);
    j.toBack();
    while (j.hasPrevious()) {
        QString str = j.previous();
        if (str == "B")
            j.remove();
    }
    j.insert("Q");
    j.toBack();
    if (j.hasPrevious())
        j.previous() = "N";
    j.setValue("M");
    j.toFront();
    qDebug() << "the MutableListiterator forward is : ";
    while (j.hasNext()) {
        qDebug() << j.next();
    }

    return a.exec();
}
