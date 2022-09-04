#ifndef OK_H
#define OK_H

#include <QMainWindow>

namespace Ui {
class Ok;
}

class Ok : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ok(QWidget *parent = 0);
    ~Ok();

private:
    Ui::Ok *ui;
};

#endif // OK_H
