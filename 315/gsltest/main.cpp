/*
配置gsl数学库
*/
#include <QCoreApplication>
#include <QDebug>
#include <cmath>
#include <gsl/gsl_sf_bessel.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    double x = 10.0;
    double y = gsl_sf_bessel_J0(x);
    qDebug() << "y value is " << y;

    return a.exec();
}
