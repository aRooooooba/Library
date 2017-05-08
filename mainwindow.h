#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);
    ~MainWindow();

private slots:
    void on_editPassword_clicked();

    void on_myInformation_clicked();

    void on_manageBook_clicked();

    void on_managePeople_clicked();

private:
    Ui::MainWindow *ui;

protected:
    void timerEvent(QTimerEvent *);
    int begin;
};

#endif // MAINWINDOW_H
