#ifndef MYINFORMATION_H
#define MYINFORMATION_H

#include <QDialog>

namespace Ui {
class MyInformation;
}

class MyInformation : public QDialog
{
    Q_OBJECT

public:
    explicit MyInformation(QWidget *parent = 0);
    ~MyInformation();

private slots:
    void on_editPassword_clicked();

private:
    Ui::MyInformation *ui;
};

#endif // MYINFORMATION_H
