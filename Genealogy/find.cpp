#include "find.h"
#include "information.h"
#include "ui_find.h"

extern string findname;

Find::Find(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Find)
{
    ui->setupUi(this);
}
/*xiazhiyuan*/
Find::~Find()
{
    delete ui;
}

void Find::on_pushButton_3_clicked()
{
    QString qstr = ui->lineEdit->text().trimmed();
    findname = qstr.toStdString();
    Information *d = new Information;
    d->show();
}
