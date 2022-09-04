#ifndef DELETE_H
#define DELETE_H

#include <QMainWindow>
#include"information.h"

namespace Ui {
class Delete;
}

class Delete : public QMainWindow
{
    Q_OBJECT

public:
    explicit Delete(QWidget *parent = 0);
    ~Delete();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Delete *ui;
};

#endif // DELETE_H
