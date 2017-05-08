#include "mainwindow.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login L;
    MainWindow w;
    while(QDialog::Accepted==L.exec())
    {
        w.show();
        a.exec();
    }
    return 0;
}
