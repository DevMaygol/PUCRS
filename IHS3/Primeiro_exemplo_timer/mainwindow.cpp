#include "mainwindow.h"
#include "ui_mainwindow.h"

unsigned long int cont = 0;
int timer_id = -1; // Guarda o numero do timer

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setNum((int)cont);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_iniciar_clicked()
{
    if(timer_id == -1){
        timer_id = startTimer(1);
        ui->iniciar->setText("PAUSAR");
}
        else{
        killTimer(timer_id);
        timer_id = -1;
        ui->iniciar->setText("INICIAR");
    }
}

void MainWindow::timerEvent(QTimerEvent *event){
    cont++;
    ui->label->setNum((int)cont);
}

void MainWindow::on_parar_clicked()
{
    killTimer(timer_id);
    timer_id = -1;
    cont = 0;
    ui->label->setNum((int)cont);
    ui->iniciar->setText("INICIAR");
}
