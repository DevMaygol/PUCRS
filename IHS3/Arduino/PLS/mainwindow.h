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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BLigar_clicked();

    void on_BDesligar_clicked();

    void on_BInverter_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
