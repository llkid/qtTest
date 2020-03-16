#ifndef MP4_H
#define MP4_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class Mp4;
}

class Mp4 : public QDialog
{
    Q_OBJECT

public:
    explicit Mp4(QWidget *parent = nullptr);
    ~Mp4();

private slots:
//    void on_buttonBox_accepted();

//    void on_buttonBox_clicked(QAbstractButton *button);

    void handle_entrance();

private:
    Ui::Mp4 *ui;
};

#endif // MP4_H
