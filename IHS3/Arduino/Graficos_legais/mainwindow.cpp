#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "portaserial.h"

int xx, yy;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    xx = rand() % 10;
    yy = rand() % 10;
    ui -> vezes -> setText("X");
    ui -> label_3 -> setNum(xx);
    ui -> label_4 -> setNum(yy);
    ui -> label -> setText("OPERACAO");
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString str;
    int result;
    str = ui ->lineEdit -> text();
    result = str.toInt();
    if(result == (xx*yy)) ui -> gabarito -> setText ("Coreto");
            else
            ui -> gabarito -> setText ("errado");

}
