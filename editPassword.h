#ifndef EDITPASSWORD_H
#define EDITPASSWORD_H

#include <QDialog>

namespace Ui {
class Editpassword;
}

class Editpassword : public QDialog
{
    Q_OBJECT

public:
    explicit Editpassword(QWidget *parent = 0);
    ~Editpassword();

private slots:
    void on_ensured_clicked();

private:
    Ui::Editpassword *ui;
};

#endif // EDITPASSWORD_H
