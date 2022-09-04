#include "add.h"
#include "ui_add.h"


extern MemberNode* ancestor;
extern string findname;
extern MemberNode* back;

Add::Add(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
}

Add::~Add()
{
    delete ui;
}

void change1(MemberNode* bt)
{
    if(bt==NULL) return ;
    else
    {
        if(bt->name==findname)
            back = bt;

        change1(bt->FirstChild);
        change1(bt->Brother);
    }
}

void Add::on_pushButton_clicked()
{
    QString qstr;
    qstr = ui->lineEdit_10->text().trimmed();
    findname = qstr.toStdString();//Qstring 转 string

    change1(ancestor);
    back->Married = 1;
    back->Spouse = new MemberNode;

    qstr = ui->lineEdit->text().trimmed();
    back->Spouse->name = qstr.toStdString();//Qstring 转 string

    qstr = ui->lineEdit_2->text().trimmed();
    if(qstr=="男")
        back->Spouse->sex = 1 ;
    else
        back->Spouse->sex = 0 ;

    qstr = ui->lineEdit_3->text().trimmed();
    back->Spouse->Birthday = qstr.toInt();

    qstr = ui->lineEdit_4->text().trimmed();
    back->Spouse->Career = qstr.toStdString();

    qstr = ui->lineEdit_5->text().trimmed();
    back->Spouse->Age = qstr.toInt();

    qstr = ui->lineEdit_8->text().trimmed();
    if(qstr=="是")
        back->Spouse->Death = 1 ;
    else
        back->Spouse->Death = 0 ;

    qstr = ui->lineEdit_6->text().trimmed();
    back->Spouse->DayOfDeath = qstr.toStdString();

    qstr = ui->lineEdit_7->text().trimmed();
    back->Spouse->Level = qstr.toInt();
}
