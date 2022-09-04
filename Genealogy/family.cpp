#include<iostream>
#include"family.h"

Member FamilyObject;
MemberNode* ancestor;
MemberNode* back;
string findname;
int male;//男性数量
int female;//女性数量
int total;//总共的族人数量

MemberNode* Member::BasicCreat()//构造函数 初始化家谱树
{
    //创建新结点

//    MemberNode* a = new MemberNode;
//    MemberNode* b = new MemberNode;
//    MemberNode* c = new MemberNode;
//    MemberNode* d = new MemberNode;
//    MemberNode* e = new MemberNode;
//    MemberNode* f = new MemberNode;
//    MemberNode* g = new MemberNode;
//    MemberNode* h = new MemberNode;
//    MemberNode* i = new MemberNode;
//    MemberNode* j = new MemberNode;
//    MemberNode* k = new MemberNode;
//    MemberNode* l = new MemberNode;
//    MemberNode* m = new MemberNode;
//    MemberNode* n = new MemberNode;
//    MemberNode* o = new MemberNode;
//    MemberNode* A = new MemberNode;
//    MemberNode* B = new MemberNode;
//    MemberNode* C = new MemberNode;
//    MemberNode* D = new MemberNode;
//    MemberNode* E = new MemberNode;
//    MemberNode* F = new MemberNode;
//    MemberNode* G = new MemberNode;
//    A->name = "天龙a";
//    B->name = "天龙b";
//    C->name = "天龙c";
//    D->name = "天龙d";
//    E->name = "天龙e";
//    F->name = "天龙f";
//    G->name = "天龙g";
//    a->name = "天龙一";
//    b->name = "天龙二";
//    c->name = "天龙三";
//    d->name = "天龙四";
//    e->name = "天龙五";
//    f->name = "天龙六";
//    g->name = "天龙七";
//    h->name = "天龙八";
//    i->name = "天龙九";
//    j->name = "天龙十";
//    k->name = "天龙十一";
//    l->name = "天龙十二";
//    m->name = "天龙十三";
//    n->name = "天龙十四";
//    o->name = "天龙十五";
//    a->Brother = NULL;
//    d->Brother = NULL;
//    e->FirstChild = NULL;
//    g->Brother = NULL;
//    g->FirstChild = NULL;
//    k->FirstChild = NULL;
//    l->Brother = NULL;
//    l->FirstChild = NULL;
//    h->Brother = NULL;
//    m->Brother = NULL;
//    m->FirstChild = NULL;
//    i->FirstChild = NULL;
//    j->Brother = NULL;
//    n->FirstChild = NULL;
//    o->Brother = NULL;
//    o->FirstChild = NULL;
//    a->FirstChild = b;
//    b->FirstChild = e;
//    f->FirstChild = k;
//    c->FirstChild = h;
//    h->FirstChild = m;
//    d->FirstChild = i;
//    j->FirstChild = n;
//    b->Brother = c;
//    c->Brother = d;
//    e->Brother = f;
//    f->Brother = g;
//    k->Brother = l;
//    i->Brother = j;
//    n->Brother = o;
//    a->Level = 1;
//    b->Level = 2;
//    c->Level = 2;
//    d->Level = 2;
//    e->Level = 3;
//    f->Level = 3;
//    g->Level = 3;
//    h->Level = 3;
//    i->Level = 3;
//    j->Level = 3;
//    k->Level = 4;
//    l->Level = 4;
//    m->Level = 4;
//    n->Level = 4;
//    o->Level = 4;
//    a->sex = 1;
//    b->sex = 1;
//    c->sex = 0;
//    d->sex = 1;
//    e->sex = 0;
//    f->sex = 0;
//    g->sex = 1;;
//    h->sex = 1;
//    i->sex = 1;
//    j->sex = 0;
//    k->sex = 1;
//    l->sex = 0;
//    m->sex = 0;
//    n->sex = 1;
//    o->sex = 0;
//    a->Married = 1;
//    b->Married = 1;
//    c->Married = 1;
//    d->Married = 1;
//    e->Married = 0;
//    f->Married = 1;
//    g->Married = 0;
//    h->Married = 1;
//    i->Married = 0;
//    j->Married = 1;
//    k->Married = 0;
//    l->Married = 0;
//    m->Married = 0;
//    n->Married = 0;
//    o->Married = 0;
//    a->Spouse = A;
//    b->Spouse = B;
//    c->Spouse = C;
//    d->Spouse = D;
//    f->Spouse = E;
//    h->Spouse = F;
//    j->Spouse = G;
//    A->FirstChild = b;
//    B->FirstChild = e;
//    C->FirstChild = h;
//    D->FirstChild = i;
//    E->FirstChild = k;
//    F->FirstChild = m;
//    G->FirstChild = n;
//    A->sex = 0;
//    B->sex = 0;
//    C->sex = 1;
//    D->sex = 0;
//    E->sex = 1;
//    F->sex = 0;
//    G->sex = 1;
//    a->Birthday = 19001010;
//    a->Career = "无";
//    a->Age = 121;
//    a->Death = 1;
//    a->DayOfDeath = "19651112";
//    b->Birthday = 19231010;
//    b->Career = "无";
//    b->Age = 98;
//    b->Death = 1;
//    b->DayOfDeath = "19990921";
//    c->Birthday = 19231010;
//    c->Career = "无";
//    c->Age = 98;
//    c->Death = 1;
//    c->DayOfDeath = "19651112";
//    d->Birthday = 19231010;
//    d->Career = "无";
//    d->Age = 98;
//    d->Death = 1;
//    d->DayOfDeath = "19651112";
//    e->Birthday = 19401010;
//    e->Career = "无";
//    e->Age = 81;
//    e->Death = 1;
//    e->DayOfDeath = "20111112";
//    f->Birthday = 19401010;
//    f->Career = "无";
//    f->Age = 81;
//    f->Death = 1;
//    f->DayOfDeath = "20111112";
//    g->Birthday = 19401010;
//    g->Career = "无";
//    g->Age = 81;
//    g->Death = 1;
//    g->DayOfDeath = "20111112";
//    h->Birthday = 19401010;
//    h->Career = "无";
//    h->Age = 81;
//    h->Death = 1;
//    h->DayOfDeath = "20111112";
//    i->Birthday = 19401010;
//    i->Career = "无";
//    i->Age = 81;
//    i->Death = 1;
//    i->DayOfDeath = "20111112";
//    j->Birthday = 19401010;
//    j->Career = "无";
//    j->Age = 81;
//    j->Death = 1;
//    j->DayOfDeath = "20111112";
//    k->Birthday = 19640123;
//    k->Career = "无";
//    k->Age = 57;
//    k->Death = 0;
//    k->DayOfDeath = "在世";
//    l->Birthday = 19640123;
//    l->Career = "无";
//    l->Age = 57;
//    l->Death = 0;
//    l->DayOfDeath = "在世";
//    m->Birthday = 19640123;
//    m->Career = "无";
//    m->Age = 57;
//    m->Death = 0;
//    m->DayOfDeath = "在世";
//    n->Birthday = 19640123;
//    n->Career = "无";
//    n->Age = 57;
//    n->Death = 0;
//    n->DayOfDeath = "在世";
//    o->Birthday = 19640123;
//    o->Career = "无";
//    o->Age = 57;
//    o->Death = 0;
//    o->DayOfDeath = "在世";
//    /*夏志远编写*/
//    return a;
}


Member::~Member()//析构函数
{
}

void Member::TraversalOutput(MemberNode* ancestor)
{
    if (ancestor == NULL)return;
    for (int i = 1; i < ancestor->Level; i++)
        cout << "       ";
    cout << ancestor->name << "(男)" ;
    TraversalOutput(ancestor->FirstChild);
    TraversalOutput(ancestor->Brother);
}

