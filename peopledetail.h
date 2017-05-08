#ifndef PEOPLEDETAIL_H
#define PEOPLEDETAIL_H

#include <QDialog>

namespace Ui {
class PeopleDetail;
}

class PeopleDetail : public QDialog
{
    Q_OBJECT

public:
    explicit PeopleDetail(QWidget *parent = 0);
    ~PeopleDetail();

private slots:
    void on_editPassword_clicked();

private:
    Ui::PeopleDetail *ui;
};

#endif // PEOPLEDETAIL_H
