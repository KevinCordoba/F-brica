#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "simulacion.h"
#include "simulacionminima.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCancelar_clicked()
{
    this->close();
}

void MainWindow::on_btnSiguiente_clicked()
{
    int intervaloFabricaAmor = this->ui->leTiempoProduccionAmor->text().toInt(),
            intervaloFabricaArte = this->ui->leTiempoProduccionArte->text().toInt(),
            intervaloFabricaOdio = this->ui->leTiempoProduccionOdio->text().toInt(),
            intervaloFabricante = this->ui->leTiempoProduccionFabricante->text().toInt();
    int limiteFabricaAmor = this->ui->leLimiteProduccionAmor->text().toInt(),
            limiteFabricaArte = this->ui->leLimiteProduccionArte->text().toInt(),
            limiteFabricaOdio = this->ui->leLimiteProduccionOdio->text().toInt(),
            limiteColaDeBebes = this->ui->leLimiteColaBebes->text().toInt();

    //simulacion *ventanaSimulacion = new simulacion();
    SimulacionMinima * ventanaSimulacion = new SimulacionMinima();
    ventanaSimulacion->setPropiedades(intervaloFabricaAmor,
                                      intervaloFabricaArte,
                                      intervaloFabricaOdio,
                                      intervaloFabricante,
                                      limiteFabricaAmor,
                                      limiteFabricaArte,
                                      limiteFabricaOdio,
                                      limiteColaDeBebes);
    this->close();
    ventanaSimulacion->show();
}
