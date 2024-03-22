#include "simulacionminima.h"
#include "ui_simulacionminima.h"

SimulacionMinima::SimulacionMinima(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimulacionMinima)
{
    ui->setupUi(this);
}

SimulacionMinima::~SimulacionMinima()
{
    delete ui;
}

void SimulacionMinima::setPropiedades(int _intervaloFabricaAmor,
                                      int _intervaloFabricaArte,
                                      int _intervaloFabricaOdio,
                                      int _intervaloFabricante,
                                      int _limiteFabricaAmor,
                                      int _limiteFabricaArte,
                                      int _limiteFabricaOdio,
                                      int _limiteColaBebes){
    this->intervaloFabricaAmor = _intervaloFabricaAmor;
    this->intervaloFabricaArte = _intervaloFabricaArte;
    this->intervaloFabricaOdio = _intervaloFabricaOdio;
    this->intervaloFabricante = _intervaloFabricante;
    this->limiteFabricaAmor = _limiteFabricaAmor;
    this->limiteFabricaArte = _limiteFabricaArte;
    this->limiteFabricaOdio = _limiteFabricaOdio;
    this->limiteColaBebes = _limiteColaBebes;
    fabricaAmor->init(true,
                      limiteFabricaAmor,
                      intervaloFabricaAmor,
                      ui->lblEstadoFabricaAmor,
                      ui->lblCantidadAmor,
                      ui->lblTiempoFabricaAmor,
                      &mutexFabricante_FabricaAmor);
    fabricaArte->init(true,
                      limiteFabricaArte,
                      intervaloFabricaArte,
                      ui->lblEstadoFabricaArte,
                      ui->lblCantidadArte,
                      ui->lblTiempoFabricaArte,
                      &mutexFabricante_FabricaArte);
    fabricaOdio->init(true,
                      limiteFabricaOdio,
                      intervaloFabricaOdio,
                      ui->lblEstadoFabricaOdio,
                      ui->lblCantidadOdio,
                      ui->lblTiempoFabricaOdio,
                      &mutexFabricante_FabricaOdio);
    fabricante->init(true,
                     intervaloFabricante,
                     limiteColaBebes,
                     fabricaAmor->colaFabricaAmor,
                     fabricaArte->colaFabricaArte,
                     fabricaOdio->colaFabricaOdio,
                     &mutexFabricante_FabricaAmor,
                     &mutexFabricante_FabricaArte,
                     &mutexFabricante_FabricaOdio,
                     &mutexColaBebesFabricados,
                     ui->lblTiempoFabricante,
                     ui->lblAleatorioFabricante,
                     ui->lblEstadoFabricante);
}

/* Simulacion */
void SimulacionMinima::on_btnIniciar_clicked()
{
    if (!fabricaAmor->isRunning())
        fabricaAmor->start();
    if (!fabricaArte->isRunning())
        fabricaArte->start();
    if (!fabricaOdio->isRunning())
        fabricaOdio->start();
    if (!fabricante->isRunning())
        fabricante->start();
   /* if ((SpecialOreder->running = false)){
        SpecialOreder->running = true;
    }*/
}

void SimulacionMinima::on_btnPausar_clicked()
{
    pausa = true;
}

void SimulacionMinima::on_btnReanudar_clicked()
{
    if (pausa)
        pausa = false;
}

void SimulacionMinima::on_btnDetener_clicked()
{
    detener = true;
}

/* Fabrica Amor */
void SimulacionMinima::on_btnPausarFabricaAmor_clicked()
{
    fabricaAmor->encendido = false;
}

void SimulacionMinima::on_btnReiniciarFabricaAmor_clicked()
{
    qDebug() << "Reiniciar fabrica amor";
    //verificar si se refiere a reanudar (pausa) o reiniciar la fabrica (limpiar cola,etc)
}

void SimulacionMinima::on_btnConfigurarFabricaAmor_clicked()
{
    qDebug() << "Configurar fabrica amor";
    //crear una ventana emergente para editar conf. fabrica amor
}

/* Fabrica Arte */
void SimulacionMinima::on_btnPausarFabricaArte_clicked()
{
    fabricaArte->encendido = false;
}

void SimulacionMinima::on_btnReiniciarFabricaArte_clicked()
{
    qDebug() << "Reiniciar fabrica arte";
}

void SimulacionMinima::on_btnConfigurarFabricaArte_clicked()
{
    qDebug() << "Configurar fabrica arte";
}

/* Fabrica Odio */
void SimulacionMinima::on_btnPausarFabricaOdio_clicked()
{
    fabricaOdio->encendido = false;
}

void SimulacionMinima::on_btnReiniciarFabricaOdio_clicked()
{
    qDebug() << "Reiniciar fabrica odio";
}

void SimulacionMinima::on_btnConfigurarFabricaOdio_clicked()
{
    qDebug() << "Configurar fabrica odio";
}

/* Fabricante Bebes */
void SimulacionMinima::on_btnPausarFabricante_clicked()
{
    qDebug() << "Pausar fabricante";
}

void SimulacionMinima::on_btnReiniciarFabricante_clicked()
{
    qDebug() << "Reiniciar fabricante";
}

void SimulacionMinima::on_btnConfigurarFabricante_clicked()
{
    qDebug() << "Configurar fabricante";
}

void SimulacionMinima::on_btn_PausarEspecial_clicked()
{
    this->SpecialOreder->stop();
}

void SimulacionMinima::on_btn_ReanudarEspecial_clicked()
{
    this->SpecialOreder->continuar();
}

void SimulacionMinima::on_box_TiempoEspecial_valueChanged(int arg1)
{
    SpecialOreder->setTiempo(arg1);
}
