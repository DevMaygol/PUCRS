#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "portaserial.h"

portaSerial ps;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ps.open("COM10", 9600);//abre a porta
}

MainWindow::~MainWindow()
{
    ps.close();
    delete ui;
}

void MainWindow::on_BLigar_clicked()
{
    ps.writeByte('L');
}

void MainWindow::on_BDesligar_clicked()
{
     ps.writeByte('D');
}

void MainWindow::on_BInverter_clicked()
{
   ps.writeByte('I');
}
