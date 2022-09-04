#ifndef ADD_H
#define ADD_H

#include <QMainWindow>
#include"family.h"
#include<string>
#include<QString>

namespace Ui {
class Add;
}

class Add : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = 0);
    ~Add();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Add *ui;
};

#endif // ADD_H
