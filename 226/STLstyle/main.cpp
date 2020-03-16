#include <QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString> list;
    list << "A" << "B" << "C" << "D";
    //读写迭代器
    QList<QString>::iterator i;
    qDebug() <<"the forward is: ";
    for (i = list.begin(); i != list.end(); ++i) {
        *i = (*i).toLower();
        qDebug() << *i;
    }
    qDebug() << "the backwrad is: ";
    while (i != list.begin()) {
        --i;
        qDebug() << *i;
    }
    //只读迭代器
    QList<QString>::const_iterator j;
    qDebug() << "the forward is : ";
    for (j = list.constBegin(); j != list.constEnd(); ++j) {
        qDebug() << *j;
    }

    qDebug() << "------------------";
    QMap<QString, int> map;
    map.insert("one", 1);
    map.insert("two", 2);
    map.insert("three", 3);
    QMap<QString, int>::const_iterator p;
    for (p = map.constBegin(); p != map.constEnd(); ++p) {
        qDebug() << p.key() << ":" << p.value();
    }
//    QMap<QString, int>::iterator pi;
//    while (pi != map.begin()) {
//        --pi;
//        qDebug() << pi.key().toUpper() << ":" << pi.value();
//    }

    return a.exec();
}
