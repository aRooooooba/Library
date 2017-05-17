#ifndef ADDPEOPLE_H
#define ADDPEOPLE_H

#include <QDialog>

namespace Ui {
class addPeople;
}

class addPeople : public QDialog
{
    Q_OBJECT

public:
    explicit addPeople(QWidget *parent = 0);
    ~addPeople();

private slots:
    void on_student_clicked();

    void on_teacher_clicked();

    void on_cancel_clicked();

    void on_ensured_clicked();

private:
    Ui::addPeople *ui;
};

#endif // ADDPEOPLE_H
