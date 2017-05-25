#include "mainwindow.h"
#include "login.h"
#include "functions.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    warningBorrower->nextWarningBorrower=NULL;
    alertReserver->nextAlertReserver=NULL;
    login L;
    while(QDialog::Accepted==L.exec())
    {
        MainWindow w;
        w.show();
        a.exec();
    }
    return 0;
}
