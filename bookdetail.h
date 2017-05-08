#ifndef BOOKDETAIL_H
#define BOOKDETAIL_H

#include <QDialog>

namespace Ui {
class BookDetail;
}

class BookDetail : public QDialog
{
    Q_OBJECT

public:
    explicit BookDetail(QWidget *parent = 0);
    ~BookDetail();

private:
    Ui::BookDetail *ui;
};

#endif // BOOKDETAIL_H
