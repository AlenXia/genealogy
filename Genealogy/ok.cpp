#include "ok.h"
#include "ui_ok.h"

Ok::Ok(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ok)
{
    ui->setupUi(this);
}

Ok::~Ok()
{
    delete ui;
}
