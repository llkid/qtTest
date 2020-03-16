#include <QCoreApplication>
#include <QMap>
#include <QMultiMap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMap <QString, int> map;
    map["one"] = 1;
    map["three"] = 3;
    map.insert("six", 6);

    int value = map["five"];
    qDebug() << "value: " << value;
    qDebug() << "contains five? " << map.contains("five");

    int value2 = map.value("seven", 7);
    qDebug() << "value2: " << value2;

    map.insert("ten", 100);
    map.insert("ten", 10);
    qDebug() << "map['ten'] = : " << map.value("ten");

    map.insertMulti("two", 2);
    map.insertMulti("four", 4);

    QList<int> values = map.values("two");
    qDebug() << "two: " << values;

    //使用QMultiMap实现一键多值
    QMultiMap<QString, int> map1, map2, map3;
    map1.insert("values", 1);
    map2.insert("values", 2);
    map3.insert("values", 3);

    map3 = map1 + map2;
    QList<int> myval = map3.values("values");
    qDebug() << "These values are : ";
    for (int i = 0; i < myval.size(); ++i) {
        qDebug() << myval.at(i);
    }

    return a.exec();
}
