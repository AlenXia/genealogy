#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include"subwidget.h"
#include<QApplication>
#include"subwindow.h"

extern Member FamilyObject;
extern MemberNode* ancestor;//储存根结点（最老的老祖宗）
extern int male;//男性数量
extern int female;//女性数量
extern int total;//总共的族人数量


MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);

    //设置标题字体和颜色
    QPalette label_pe;
    QFont ft;/*xiazhiyuan*/
    ft.setPointSize(20);
    label_pe.setColor(QPalette::WindowText, Qt::red);
    ui->label_2->setPalette(label_pe);
    ui->label_2->setFont(ft);

    //设置标题位置、大小
    ui->label_2->setGeometry(650,-420,2500,900);

}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::on_log_in_triggered()
{
    SubWidget *d = new SubWidget();
    d->show();
}

void MyMainWindow::on_overview_triggered()
{
    Overview *d = new Overview;
    d->show();
}

void MyMainWindow::on_action1_triggered()
{
    Delete *d = new Delete;
    d->show();
}

void MyMainWindow::on_action11_4_triggered()
{
    Find *d = new Find;
    d->show();
}

void MyMainWindow::on_pushButton_clicked()
{
    male=0;//男性数量
    female=0;//女性数量
    total=0;//总共的族人数量
    int n;
    MemberNode* bt = ancestor;
    MemberNode* S[200];       //顺序栈，最多100个结点指针
    int top = -1;                     //顺序栈初始化
    while (bt != nullptr || top != -1)      //两个条件都不成立才退出循环
    {
        while (bt != nullptr)
        {
            if(bt->name!="/已被驱逐/")
            {
                if(bt->sex==1)
                    male++;
                else
                    female++;
                total++;
                n=bt->Level;
            }
                S[++top] = bt;               //将根指针bt入栈
                bt = bt->FirstChild;
        }
        if (top != -1) {                //栈非空
            bt = S[top--];
            bt = bt->Brother;
        }
    }

    ui->lineEdit_4->/*夏志远编写*/setText(QString::number(total,10));
    ui->lineEdit_5->setText(QString::number(male,10));
    ui->lineEdit_6->setText(QString::number(female,10));
    ui->lineEdit_7->setText(QString::number(n,10));
//    QString s = QString::number(a,10)

}

void MyMainWindow::on_action11_triggered()
{
    Add *d = new Add;
    d->show();
}

void MyMainWindow::on_action11_3_triggered()
{
    Add2 *d = new Add2;
    d->show();
}
