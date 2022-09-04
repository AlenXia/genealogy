#ifndef ADD2_H
#define ADD2_H

#include <QMainWindow>
#include"family.h"
#include<string>
#include<QString>

namespace Ui {
class Add2;
}

class Add2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add2(QWidget *parent = 0);
    ~Add2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Add2 *ui;
};

#endif // ADD2_H
