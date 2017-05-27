#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dataStruct.h"
#include <QMainWindow>
#include <QSignalMapper>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void initializeUI();
    void initPersonInformation();
    void initBookInformation();
    void initPeopleList();
    void initBookList();
    void initWarningList();
    ~MainWindow();

private slots:
    void on_logout_clicked();

    void on_editPassword_clicked();

    void on_password_textChanged();

    void on_addPeople_clicked();

    void on_addBook_clicked();

    void on_myInformation_clicked();

    void locateB(int i);

    void locateP(int i);

    void on_editLimit_clicked();

    void on_ensured_clicked();

    void on_cancel_clicked();

    void on_allPeople_clicked();

    void on_allBook_clicked();

    void on_bookName_textEdited();

    void on_author_textEdited();

    void on_publisher_textEdited();

    void on_description_textChanged();

    void on_borrow_clicked();

    void on_return_2_clicked();

    void on_noReserve_clicked();

    void on_borrowerInformation_clicked();

    void on_reserverInformation_clicked();

    void on_borrowedInformation_clicked();

    void on_reservedInformation_clicked();

    void on_search_clicked();

    void on_administratorEditor_clicked();

private:
    Ui::MainWindow *ui;
    QSignalMapper *signalMapper;

protected:
    void timerEvent(QTimerEvent * event);
    int refresh;
};

#endif // MAINWINDOW_H
