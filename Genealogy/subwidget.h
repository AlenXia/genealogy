#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include<QApplication>
#include"family.h"
namespace Ui {
class SubWidget;
}

class SubWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SubWidget(QWidget *parent = 0);
    ~SubWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SubWidget *ui;

};

#endif // SUBWIDGET_H
