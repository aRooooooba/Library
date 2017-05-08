#ifndef LOADLOGIN_H
#define LOADLOGIN_H

#include <QDialog>

namespace Ui {
class Loadlogin;
}

class Loadlogin : public QDialog
{
    Q_OBJECT

public:
    explicit Loadlogin(QWidget *parent = 0);
    ~Loadlogin();

private slots:
    void on_enter_clicked();

private:
    Ui::Loadlogin *ui;
};

#endif // LOADLOGIN_H
