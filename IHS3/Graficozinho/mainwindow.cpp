#include "mainwindow.h"
#include "ui_mainwindow.h"

int aux;
//unsigned long int cont = 0;
//int timer_id = -1; // Guarda o numero do timer

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QVector<double> x(1000), y(1000);

    ui->setupUi(this); // Esta linha já estava aqui no tamplate. =)
    for(int k = 0; k < 1000; k++)
    {
        x[k] = k*0.001;
        y[k] = sin(aux*x[k]);
    }
    ui->horizontalSlider->value();
    ui->areaGrafico->addGraph(); // Cria curva no gráfico
    ui->areaGrafico->graph(0)->setData(x,y);
    ui->areaGrafico->xAxis->setRange(0,1);
    ui->areaGrafico->yAxis->setRange(-1.1, 1.1);
    startTimer(100);

}


void MainWindow::timerEvent(QTimerEvent *event)
{
    aux++;
    ui->horizontalSlider->setValue(aux);
    if(aux >= 50) aux = 10;
}





void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    QVector<double> x(1000), y(1000);
    for(int k = 0; k < 1000; k++)
    {
        x[k] = k*0.001;
        y[k] = sin(aux*x[k]);
    }
    ui->horizontalSlider->value();
    ui->areaGrafico->addGraph(); // Cria curva no gráfico
    ui->areaGrafico->graph(0)->setData(x,y);
    ui->areaGrafico->xAxis->setRange(0,1);
    ui->areaGrafico->yAxis->setRange(-1.1, 1.1);
    ui->areaGrafico->replot();
}
MainWindow::~MainWindow()
{
    delete ui;
}

