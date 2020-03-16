#include <QCoreApplication>
#include <QDebug>

constexpr auto WINDOW_NAME = "法国";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << WINDOW_NAME;

    return a.exec();
}
