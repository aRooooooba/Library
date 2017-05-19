#include "mainwindow.h"
#include "login.h"
#include "functions.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login L;
    while(QDialog::Accepted==L.exec())
    {
        MainWindow w;
        w.show();
        a.exec();
    }
    return 0;
}
