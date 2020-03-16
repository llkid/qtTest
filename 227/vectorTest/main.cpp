#include <QCoreApplication>
#include <QTextCodec>
#include <QVector>
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QStringList list;
    list << "one" << "two" << "three";
    qDebug() << QObject::tr("qCopy()算法：");
    QVector<QString> vect(3);
    qCopy(list.begin(), list.end(), vect.begin());
    qDebug() << vect;

    qDebug() << endl << QObject::tr("qEqual()算法：");
    bool ret1 = qEqual(list.begin(), list.end(), vect.begin());
    qDebug() << "qEqual: " << ret1;

    qDebug() << endl << QObject::tr("qFind()算法：");
    QList<QString>::iterator i = qFind(list.begin(), list.end(), "two");
    qDebug() << *i;

    qDebug() << endl << QObject::tr("qFill()算法：");
    qFill(list.begin(), list.end(), "ten");
    qDebug() << list;

    QList<int> list1;
    list1 << 3 << 3 << 6 << 6 << 6 << 8;

    qDebug() << endl << QObject::tr("qCount()算法：");
    int countof6 = 0;
    qCount(list1, 6, countof6);
    //qCount的两个版本
//    qCount(list1.begin(), list1.end(), 6, countof6);
    qDebug() << "countof6: " << countof6;

    qDebug() << endl << QObject::tr("qLowerBound()算法：");
    //返回第一个出现5的位置，如果不存在，则返回5应该在的位置（被查找的范围list必须是升序）
    QList<int>::iterator j = qLowerBound(list1.begin(), list1.end(), 5);
    list1.insert(j, 5);
    qDebug() << list1;

    QList<int> list2;
    list2 << 33 << 12 << 68 << 6 << 12;
    qDebug() << endl << QObject::tr("qSort()快速排序算法：");
    qSort(list2);
//    qSort(list2.begin(), list2.end());
    qDebug() << list2;

    qDebug() << endl << QObject::tr("qStableSort()稳定排序算法：");
    qStableSort(list2);
    qDebug() << list2;

    qDebug() << endl << QObject::tr("qGreater()反向排序算法：");
    qSort(list2.begin(), list2.end(), qGreater<int>());
    qDebug() << list2;

    qDebug() << endl << QObject::tr("qSwap()交换算法：");
    double pi = 3.14;
    double e = 2.71;
    qSwap(pi, e);
    qDebug() << "pi: " << pi << "e: " << e;

    return a.exec();
}
