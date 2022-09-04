#ifndef INFORMATION_H
#define INFORMATION_H

#include <QMainWindow>
#include"family.h"
#include<string>
#include<QString>

namespace Ui {
class Information;
}

class Information : public QMainWindow
{
    Q_OBJECT

public:
    explicit Information(QWidget *parent = 0);
    ~Information();

    void PreOrder1(MemberNode* bt);//搜索人名信息

    void PreOrder2(MemberNode* bt);

    void PreOrder3(MemberNode* bt);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


    void on_pushButton_5_clicked();

private:
    Ui::Information *ui;
};

#endif // INFORMATION_H
