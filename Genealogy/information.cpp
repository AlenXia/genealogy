#include "information.h"
#include "ui_information.h"

extern MemberNode* ancestor;
extern string findname;
extern MemberNode* back;

void Information::PreOrder1(MemberNode* bt)//搜索人名信息
{
    if(bt==NULL) return ;
    else
    {
        if(bt->name==findname)
        {
            if(bt->sex==0)
                ui->lineEdit_2->setText("女");
            else
                ui->lineEdit_2->setText("男");
            if(bt->Death==0)
                ui->lineEdit_8->setText("否");
            else
                ui->lineEdit_8->setText("是");
            if(bt->Married==0)
                ui->lineEdit_9->setText("否");
            else
                ui->lineEdit_9->setText("是");
            ui->lineEdit_5->setText(QString::number(bt->Age,10));
            ui->lineEdit_3->setText(QString::number(bt->Birthday,10));
            ui->lineEdit_7->setText(QString::number(bt->Level,10));
            ui->lineEdit->setText(QString::fromStdString(bt->name));
            ui->lineEdit_6->setText(QString::fromStdString(bt->DayOfDeath));
            ui->lineEdit_4->setText(QString::fromStdString(bt->Career));

        }

        PreOrder1(bt->FirstChild);
        PreOrder1(bt->Brother);
        PreOrder1(bt->Spouse);
    }
}

void D1(MemberNode* p)
{
    if (p == NULL)return;
    else
    {
        if (p->FirstChild !=NULL &&p->FirstChild->name == findname)
        {
            p->FirstChild = p->FirstChild->Brother;
        }
        else
        {
            D1(p->Brother);
            D1(p->FirstChild);
        }
    }
}
void D2(MemberNode* p)
{
    if (p == NULL)return;
    else
    {
        if (p->Brother !=NULL &&p->Brother->name == findname)
        {
            p->Brother = p->Brother->Brother;
        }
        else
        {
            D2(p->Brother);
            D2(p->FirstChild);
        }
    }
}

void D3(MemberNode* p)
{
    if (p == NULL)return;
    else
    {
        if (p->Spouse != NULL && p->name == findname)
        {
            p->Spouse = NULL;
            p->Married = 0;
        }
        else
        {
            D3(p->Brother);
            D3(p->FirstChild);
        }

    }
}



//现在没用
//void Information::PreOrder2(MemberNode* bt)
//{
//    if(bt==NULL) return ;
//    else
//    {
//        if(bt->FirstChild->name==findname)
//            back = bt;
//        else if(bt->Brother->name==findname)
//            back = bt;
//        else if(bt->Spouse->name==findname)
//            back = bt;
//    PreOrder2(bt->FirstChild);
//    PreOrder2(bt->Brother);
//    }
//}
//现在也没用

void Information::PreOrder3(MemberNode* bt)//搜索人名信息
{
    if(bt==NULL) return ;
    else
    {
        if(bt->name==findname)
            bt->name = "/已被驱逐/";
        PreOrder3(bt->FirstChild);
        PreOrder3(bt->Brother);
        PreOrder3(bt->Spouse);
    }
}


Information::Information(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);

    PreOrder1(ancestor);

}

Information::~Information()
{
    delete ui;
}

void change(MemberNode* bt)
{
    if(bt==NULL) return ;
    else
    {
        if(bt->name==findname)
            back = bt;

        change(bt->FirstChild);
        change(bt->Brother);
        change(bt->Spouse);
    }
}

void Information::on_pushButton_clicked()         //修改
{
    change(ancestor);
    QString qstr = ui->lineEdit->text().trimmed();
    back->name = qstr.toStdString();//Qstring 转 string

    qstr = ui->lineEdit_2->text().trimmed();
    if(qstr=="男")
        back->sex = 1 ;
    else
        back->sex = 0 ;

    qstr = ui->lineEdit_3->text().trimmed();
    back->Birthday = qstr.toInt();

    qstr = ui->lineEdit_4->text().trimmed();
    back->Career = qstr.toStdString();

    qstr = ui->lineEdit_5->text().trimmed();
    back->Age = qstr.toInt();

    qstr = ui->lineEdit_8->text().trimmed();
    if(qstr=="是")
        back->Death = 1 ;
    else
        back->Death = 0 ;

    qstr = ui->lineEdit_6->text().trimmed();
    back->DayOfDeath = qstr.toStdString();

    qstr = ui->lineEdit_8->text().trimmed();
    if(qstr=="是")
        back->Married = 1 ;
    else
        back->Married = 0 ;

    qstr = ui->lineEdit_7->text().trimmed();
    back->Level = qstr.toInt();
//    QString info = "123";  Qsting转int
//    int number = info.toInt()

//    int num = "123";   int转Qstring
//    QString info = QString::number(num);


}


void Information::on_pushButton_3_clicked()       //删除(出嫁、出赘、离婚)
{
    D1(ancestor);
    D2(ancestor);
}


void Information::on_pushButton_4_clicked()   //逐出家谱
{
    PreOrder3(ancestor);

}


void Information::on_pushButton_5_clicked()
{
    D3(ancestor);

}
