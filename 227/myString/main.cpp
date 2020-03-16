#include <QCoreApplication>
#include <QTextCodec>
#include <QDebug>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    qDebug() << QObject::tr("以下是编辑字符串操作：") << endl;

    QString str = "hello";
    qDebug() << QObject::tr("字符串大小：") << str.size();
    str[0] = QChar('H');
    qDebug() << str;
    str.append(" Qt");
    str.replace(1, 4, 'i');
    str.insert(2, " my");
    qDebug() << QObject::tr("此时字符串str为：") << str;

    str = "hi\r\n Qt! \n ";
    qDebug() << str;
    QString str1 = str.trimmed();
    qDebug() << QObject::tr("str1: ") << str1;
    QString str2 = str.simplified();
    qDebug() << QObject::tr("str2: ") << str2;

    str = "hi,my,,Qt!";
    QStringList list = str.split(",", QString::SkipEmptyParts);
    qDebug() << QObject::tr("str拆分后：") << list;
    str = list.join(" ");
    qDebug() << QObject::tr("list组合后：") << str;

    qDebug() << QString().isNull();
    qDebug() << QString().isEmpty();
    qDebug() << QString("").isNull();
    qDebug() << QString("").isEmpty();

    return a.exec();
}
