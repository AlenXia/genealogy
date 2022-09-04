#pragma once
#ifndef FAMILY_H
#define FAMILY_H

#include<iostream>
#include<string>
#include<Windows.h>

struct MemberNode;
struct Statistics;
using namespace std;

class Member
{
public:
    Member() { ancestor = BasicCreat(); }
    ~Member();
private:/*xiazhiyuan*/
    MemberNode* BasicCreat();
    void TraversalOutput(MemberNode* p);
    void UpDateStatics(MemberNode* ancestor);
    //--------------------------------------------------//
public:
    MemberNode* ancestor;//储存根结点（最老的老祖宗）
    //用于统计的数据
    int male;//男性数量
    int female;//女性数量
    int total;//总共的族人数量
};



#endif // FAMILY_H

struct MemberNode
{

    string name;                //姓名
    bool sex;                   //男性为1，女性为0
    int Birthday;               //出生日期
    string Career;              //职业
    int Age;                    //年龄
    bool Death;                 //是否去世
    string DayOfDeath;          //去世日期
    bool Married;               //是否已婚
    int Level;                  //辈分
    MemberNode* FirstChild=NULL;//大儿
    MemberNode* Brother=NULL;   //bro
    MemberNode* Spouse=NULL;    //对象
};
