#include "overview.h"
#include "ui_overview.h"

using namespace std;

extern Member FamilyObject;
extern MemberNode* ancestor;//储存根结点（最老的老祖宗）


Overview::Overview(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Overview)
{
    ui->setupUi(this);
    this->setWindowTitle("族谱总览");
}

Overview::~Overview()
{
    delete ui;
}

void Overview::on_pushButton_clicked()
{

    MemberNode *bt = ancestor;
    MemberNode *S[200];       //顺序栈，最多200个结点指针
    int top = -1;                     //顺序栈初始化
    while (bt != nullptr || top != -1)      //两个条件都不成立才退出循环
    {
        while (bt != nullptr)
        {
//            QString qstr = QString::fromStdString(ancestor->name);
            ui->textEdit->insertPlainText("| ");
            for (int i = 1; i < bt->Level; i++)
                    ui->textEdit->insertPlainText("       ");
            ui->textEdit->insertPlainText(QString::fromStdString(bt->name));
            if(bt->sex==0)
                ui->textEdit->insertPlainText("(女)");
            else
                ui->textEdit->insertPlainText("(男)");
            if(bt->Spouse!=NULL)
            {
                ui->textEdit->insertPlainText("----");
                ui->textEdit->insertPlainText(QString::fromStdString(bt->Spouse->name));
                if(bt->sex==1)
                    ui->textEdit->insertPlainText("(女)");
                else
                    ui->textEdit->insertPlainText("(男)");
            }
            ui->textEdit->insertPlainText("                                                                                           ");
            S[++top] = bt;               //将根指针bt入栈
            bt = bt->FirstChild;
        }
        if (top != -1)
        {                //栈非空
            bt = S[top--];
            bt = bt->Brother;
        }
    }
        ui->textEdit->insertPlainText("                                                                                           ");
}
//    if (ancestor == NULL)return;
//    for (int i = 1; i < ancestor->Level; i++)
//        ui->textEdit->insertPlainText("          ");
//    QString qstr = QString::fromStdString(ancestor->name);
//    QString str3;
//    int db3=ancestor->Birthday;
//    str3.setNum(db3);//设置数字
//    ui->textEdit->insertPlainText(str3);

//    ui->textEdit->insertPlainText("                                                                                                          ");
//    ui->textEdit->insertPlainText("|          ");
//    ui->textEdit->insertPlainText(qstr);
//    TraversalOutput(ancestor->FirstChild);
//    TraversalOutput(ancestor->Brother);
/*xiazhiyuan*/


std::ofstream fs;
void Overview::Output1(MemberNode* p)
{
    if (p == NULL)  return;
        else {
            if (p->Married == 0)
            {
                fs << "-----------------------------------------------" << endl;
                fs << "          姓名：" << p->name << endl;
                fs << "          性别：";
                if (p->sex == 1) { fs << "男" << endl; }
                else { fs << "女" << endl;; }
                fs << "          生日：";
                fs << p->Birthday << endl;
                fs << "          年龄：";
                fs << p->Age << endl;
                fs << "          职业：";
                fs << p->Career << endl;;
                if (p->Death == 1) { fs << "          死亡日期：" << p->DayOfDeath << endl; }
                else { fs << "          在世" << endl; }
                fs << "          辈分：" << p->Level << endl;
                fs << "          未婚" << endl;

            }
            if (p->Married == 1)
            {
                fs << "-----------------------------------------------" << endl;
                fs << "          姓名：" << p->name << endl;
                fs << "          性别：";
                if (p->sex == 1) { fs << "男" << endl; }
                else { fs << "女" << endl;; }
                fs << "          生日：";
                fs << p->Birthday << endl;
                fs << "          年龄：";
                fs << p->Age << endl;
                fs << "          职业：";
                fs << p->Career << endl;;
                if (p->Death == 1) { fs << "          死亡日期：" << p->DayOfDeath << endl; }
                else { fs << "          在世" << endl; }
                fs << "          辈分：" << p->Level << endl;
                fs << "          已婚，配偶姓名：" << p->Spouse->name << endl;

                fs << "-----------------------------------------------" << endl;
                fs << "          姓名：" << p->Spouse->name << endl;
                fs << "          性别：";
                if (p->Spouse->sex == 1) { fs << "男" << endl; }
                else { fs << "女" << endl;; }
                fs << "          生日：";
                fs << p->Spouse->Birthday << endl;
                fs << "          年龄：";
                fs << p->Spouse->Age << endl;
                fs << "          职业：";
                fs << p->Spouse->Career << endl;;
                if (p->Spouse->Death == 1) { fs << "          死亡日期：" << p->Spouse->DayOfDeath << endl; }
                else { fs << "          在世" << endl; }
                fs << "          辈分：" << p->Level << endl;
                fs << "          已婚，配偶姓名：" << p->name << endl;


            }

        }
        Output1(p->FirstChild);
        Output1(p->Brother);
}
/*xiazhiyuan*/
void Overview::Output2(MemberNode* ancestor)
{
    if (ancestor == NULL)return;
    else if (ancestor->name != " ")
    {
        {

            for (int i = 1; i < ancestor->Level; i++)
            {
                fs << "       ";
            }

            if (ancestor->Married == 1 && ancestor->Spouse != NULL && ancestor->Spouse->name != " ") {
                if (ancestor->sex == 1)
                {
                    fs << ancestor->name << "(男)" << "--" << ancestor->Spouse->name << "(女)" << endl;
                }
                else
                {
                    fs << ancestor->name << "(女)" << "--" << ancestor->Spouse->name << "(男)" << endl;
                }
            }
            else if (ancestor->Married == 1 && ancestor->Spouse != NULL && ancestor->Spouse->name == " ")
                if (ancestor->sex == 1)
                {
                    fs << ancestor->name << "(男)" << "--" << "被逐出家谱" << endl;
                }
                else
                {
                    fs << ancestor->name << "(女)" << "--" << "被逐出家谱" << endl;
                }
            else
            {
                if (ancestor->sex == 1)
                {
                    fs << ancestor->name << "(男)" << endl;
                }
                else
                {
                    fs << ancestor->name << "(女)" << endl;
                }
            }
        }
    }
    else
    {
        {
            for (int i = 1; i < ancestor->Level; i++)
                fs << "       ";
            if (ancestor->Married == 1 && ancestor->Spouse != NULL) {
                if (ancestor->sex == 1)
                {
                    fs << "被逐出家谱" << "--" << ancestor->Spouse->name << "(女)" << endl;
                }
                else
                {
                    fs << "被逐出家谱" << "--" << ancestor->Spouse->name << "(男)" << endl;
                }
            }
            else
            {
                if (ancestor->sex == 1)
                {
                    fs << "被逐出家谱" << endl;
                }
                else
                {
                    fs << "被逐出家谱" << endl;
                }
            }
        }

    }
    Output2(ancestor->FirstChild);
    Output2(ancestor->Brother);
}

void Overview::on_pushButton_2_clicked()
{
    fs.open("D:\\jiazudata\\1.txt");
    Output1(ancestor);
    fs.close();

    fs.open("D:\\jiazudata\\2.txt");
    Output2(ancestor);
    fs.close();
}
