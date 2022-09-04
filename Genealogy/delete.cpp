#include "delete.h"
#include "ui_delete.h"

extern string findname;

Delete::Delete(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
}

Delete::~Delete()
{
    delete ui;
}

void Delete::on_pushButton_3_clicked()
{
    QString qstr = ui->lineEdit->text().trimmed();
    findname = qstr.toStdString();
    Information *d = new Information;
    d->show();
}
