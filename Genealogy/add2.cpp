#include "add2.h"
#include "ui_add2.h"

extern MemberNode* ancestor;
extern string findname;
extern MemberNode* back;


Add2::Add2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Add2)
{
    ui->setupUi(this);
}

Add2::~Add2()
{
    delete ui;
}

void change2(MemberNode* bt)
{
    if(bt==NULL) return ;
    else
    {
        if(bt->name==findname)
            back = bt;

        change2(bt->FirstChild);
        change2(bt->Brother);
    }
}


void Add2::on_pushButton_clicked()
{
    QString qstr;
    qstr = ui->lineEdit_10->text().trimmed();
    findname = qstr.toStdString();//Qstring 转 string

    change2(ancestor);
    back->Married = 0;
    if(back->FirstChild==NULL)
        back = back->FirstChild = new MemberNode;
    else
    {
        back = back->FirstChild;
        while(back->Brother==NULL)
            back = back->Brother;
        back = back->Brother = new MemberNode;
    }
    qstr = ui->lineEdit->text().trimmed();
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

    qstr = ui->lineEdit_7->text().trimmed();
    back->Level = qstr.toInt();
}
