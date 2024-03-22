#ifndef SIMULACION_H
#define SIMULACION_H

#include "fabricaamor.h"
#include "fabricaarte.h"
#include "fabricaodio.h"
#include <QDialog>


namespace Ui {
class simulacion;
}

class simulacion : public QDialog
{
    Q_OBJECT

public:

    FabricaAmor * fabricaAmor = new FabricaAmor();

    FabricaArte * fabricaArte = new FabricaArte();

    FabricaOdio * fabricaOdio = new FabricaOdio();

    int intervaloFabricaAmor,intervaloFabricaArte,intervaloFabricaOdio;

    int limiteFabricaAmor,limiteFabricaArte,limiteFabricaOdio;

    explicit simulacion(QWidget *parent = nullptr);
    ~simulacion();

    void setPropiedades(int,int,int,int,int,int);

    void returnQMetaType(void);


private slots:


    void on_btnIniciar_clicked();

    void on_btnPausar_clicked();

    void on_btnReanudar_clicked();

    void on_btnDetener_clicked();

    void on_btnPausarFabricaAmor_clicked();

    void on_btnPausarFabricaArte_clicked();

    void on_btnPausarFabricaOdio_clicked();

private:
    Ui::simulacion *ui;
};

#endif // SIMULACION_H
