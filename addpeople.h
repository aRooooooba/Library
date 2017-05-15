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

private:
    Ui::addPeople *ui;
};

#endif // ADDPEOPLE_H
