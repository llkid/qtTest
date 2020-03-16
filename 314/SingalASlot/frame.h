#ifndef FRAME_H
#define FRAME_H

#include <QFrame>

namespace Ui {
class Frame;
}

class Frame : public QFrame
{
    Q_OBJECT

public:
    explicit Frame(QWidget *parent = nullptr);
    ~Frame();

signals:
//    void overflow();

public slots:
//    void dispaly(int num);
//    void display(double num);
//    void display(const QString& str);
//    void setHexMode();
//    void setDecMode();
//    void setOctMode();
//    void setBinMode();
//    void setSmallDecimalPoint(bool point);
    void display(QString);

private:
    Ui::Frame *ui;
};

#endif // FRAME_H
