#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include"add.h"
#include"add2.h"
#include"family.h"//不知道怎么描述这个头文件
#include"subwidget.h"//登录子窗口头文件
#include"overview.h"//总览子窗口头文件
#include"delete.h"//删除子窗口头文件
#include"find.h"//查找子窗口头文件

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();
private:
    Ui::MyMainWindow *ui;

private slots:
    void on_log_in_triggered();
    void on_overview_triggered();
    void on_action1_triggered();
    void on_action11_4_triggered();
    void on_pushButton_clicked();
    void on_action11_triggered();
    void on_action11_3_triggered();
};

#endif // MYMAINWINDOW_H
