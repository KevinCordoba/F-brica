#include "simulacion.h"
#include "ui_simulacion.h"

simulacion::simulacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::simulacion)
{
    ui->setupUi(this);
}

simulacion::~simulacion()
{
    delete ui;
}

void simulacion::on_btnIniciar_clicked()
{
//    fabricaAmor->init(true,
//                      limiteFabricaAmor,
//                      intervaloFabricaAmor,
//                      ui->lblPrimeroAmor,
//                      ui->lblSegundoAmor,
//                      ui->lblTerceroAmor,
//                      ui->lblEstadoFabricaAmor,
//                      ui->lblCantidadAmor,
//                      &mutexFabricante_FabricaAmor);
//    fabricaArte->init(true,
//                      limiteFabricaArte,
//                      intervaloFabricaArte,
//                      ui->lblPrimeroArte,
//                      ui->lblSegundoArte,
//                      ui->lblTerceroArte,
//                      ui->lblEstadoFabricaArte,
//                      ui->lblCantidadArte,
//                      &mutexFabricante_FabricaArte);
//    fabricaOdio->init(true,
//                      limiteFabricaOdio,
//                      intervaloFabricaOdio,
//                      ui->lblPrimeroOdio,
//                      ui->lblSegundoOdio,
//                      ui->lblTerceroOdio,
//                      ui->lblEstadoFabricaOdio,
//                      ui->lblCantidadOdio,
//                      &mutexFabricante_FabricaOdio);
//    fabricaAmor->start();
//    fabricaArte->start();
//    fabricaOdio->start();
}

void simulacion::on_btnPausar_clicked()
{
    pausa = true;
}

void simulacion::on_btnReanudar_clicked()
{
    if (pausa)
        pausa = false;
}

void simulacion::on_btnDetener_clicked()
{
    detener = true;
}

void simulacion::on_btnPausarFabricaAmor_clicked()
{
    qDebug() << "Fabrica de amor pausar!";
}

void simulacion::on_btnPausarFabricaArte_clicked()
{
    qDebug() << "Fabrica de arte pausar!";
}

void simulacion::on_btnPausarFabricaOdio_clicked()
{
    qDebug() << "Fabrica de odio pausar!";
}



/* Setters */
void simulacion::setPropiedades(int _intervaloFabricaAmor,
                                int _intervaloFabricaArte,
                                int _intervaloFabricaOdio,
                                int _limiteFabricaAmor,
                                int _limiteFabricaArte,
                                int _limiteFabricaOdio){
    this->intervaloFabricaAmor = _intervaloFabricaAmor;
    this->intervaloFabricaArte = _intervaloFabricaArte;
    this->intervaloFabricaOdio = _intervaloFabricaOdio;
    this->limiteFabricaAmor = _limiteFabricaAmor;
    this->limiteFabricaArte = _limiteFabricaArte;
    this->limiteFabricaOdio = _limiteFabricaOdio;
}
