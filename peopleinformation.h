#ifndef PEOPLEINFORMATION_H
#define PEOPLEINFORMATION_H

#include <QDialog>

namespace Ui {
class PeopleInformation;
}

class PeopleInformation : public QDialog
{
    Q_OBJECT

public:
    explicit PeopleInformation(QWidget *parent = 0);
    ~PeopleInformation();

private:
    Ui::PeopleInformation *ui;
};

#endif // PEOPLEINFORMATION_H
