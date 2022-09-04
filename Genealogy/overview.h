
#ifndef OVERVIEW_H
#define OVERVIEW_H

#include <QMainWindow>
#include<QDebug>
#include"family.h"
#include<iostream>
#include<ostream>
#include <fstream>

namespace Ui {
class Overview;
}

class Overview : public QMainWindow
{
    Q_OBJECT

public:
    explicit Overview(QWidget *parent = 0);
    ~Overview();
    void Output1( MemberNode* p);
    void Output2(MemberNode* ancestor);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Overview *ui;
};

#endif // OVERVIEW_H
