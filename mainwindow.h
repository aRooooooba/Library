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
    void initializeUI();
    void initMyInformation();
    ~MainWindow();

private slots:
    void on_logout_clicked();

    void on_editPassword_clicked();

    void on_password_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
