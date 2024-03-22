#ifndef SIMULACIONMINIMA_H
#define SIMULACIONMINIMA_H

#include <QDialog>
#include "fabricaamor.h"
#include "fabricaarte.h"
#include "fabricaodio.h"
#include "fabricante.h"
#include "hilopedidoespecial.h"

namespace Ui {
class SimulacionMinima;
}

class SimulacionMinima : public QDialog
{
    Q_OBJECT

public:

    explicit SimulacionMinima(QWidget *parent = nullptr);
    ~SimulacionMinima();

    void setPropiedades(int,int,int,int,int,int,int,int);

private slots:
    void on_btnPausarFabricaAmor_clicked();

    void on_btnReiniciarFabricaAmor_clicked();

    void on_btnPausarFabricaArte_clicked();

    void on_btnReiniciarFabricaOdio_clicked();

    void on_btnReiniciarFabricaArte_clicked();

    void on_btnPausarFabricaOdio_clicked();

    void on_btnConfigurarFabricaAmor_clicked();

    void on_btnConfigurarFabricaArte_clicked();

    void on_btnConfigurarFabricaOdio_clicked();

    void on_btnConfigurarFabricante_clicked();

    void on_btnPausarFabricante_clicked();

    void on_btnReiniciarFabricante_clicked();

    void on_btnIniciar_clicked();

    void on_btnPausar_clicked();

    void on_btnReanudar_clicked();

    void on_btnDetener_clicked();

    void on_btn_PausarEspecial_clicked();

    void on_btn_ReanudarEspecial_clicked();

    void on_box_TiempoEspecial_valueChanged(int arg1);

private:
    Ui::SimulacionMinima *ui;

    FabricaAmor * fabricaAmor = new FabricaAmor();

    FabricaArte * fabricaArte = new FabricaArte();

    FabricaOdio * fabricaOdio = new FabricaOdio();

    Fabricante * fabricante = new Fabricante();

    hiloPedidoEspecial * SpecialOreder = new hiloPedidoEspecial();

    int intervaloFabricaAmor,intervaloFabricaArte,intervaloFabricaOdio,intervaloFabricante;

    int limiteFabricaAmor,limiteFabricaArte,limiteFabricaOdio,limiteColaBebes;

};

#endif // SIMULACIONMINIMA_H
