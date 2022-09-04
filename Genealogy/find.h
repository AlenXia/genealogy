#ifndef FIND_H
#define FIND_H

#include <QMainWindow>
#include<string>
#include"family.h"

namespace Ui {
class Find;
}

class Find : public QMainWindow
{
    Q_OBJECT

public:
    explicit Find(QWidget *parent = 0);
    ~Find();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Find *ui;
};

#endif // FIND_H
