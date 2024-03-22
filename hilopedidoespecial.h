#ifndef HILOPEDIDOESPECIAL_H
#define HILOPEDIDOESPECIAL_H

#include "pedidoespecial.h"
#include <QtCore>
#include "bebe.h"

class hiloPedidoEspecial
{
public:

    bool running;
    pedidoEspecial * pedido;
    QStringList lista;
    QMutex* mutPE;
    ColaBebes* colabbPE;

    hiloPedidoEspecial();

    void __init__(QMutex* mutexPE, ColaBebes* colabb );
    void run();
    void stop();
    void continuar();
    void setTiempo(int _tiempo);

};

#endif // HILOPEDIDOESPECIAL_H
