#ifndef BOOKINFORMATION_H
#define BOOKINFORMATION_H

#include <QDialog>
#include <QSignalMapper>

namespace Ui {
class BookInformation;
}

class BookInformation : public QDialog
{
    Q_OBJECT

public:
    explicit BookInformation(QWidget *parent = 0);
    ~BookInformation();

private slots:
    void locateB(int i);

private:
    Ui::BookInformation *ui;
    QSignalMapper * signalMapper;
};

#endif // BOOKINFORMATION_H
