#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_exit_clicked();

    void on_register_2_clicked();

    void on_enter_clicked();

private:
    Ui::login *ui;

protected:
    void timerEvent(QTimerEvent *);
    int begin;
};

#endif // LOGIN_H
