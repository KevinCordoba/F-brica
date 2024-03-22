#include "hilopedidoespecial.h"

hiloPedidoEspecial::hiloPedidoEspecial()
{
    this->running = true;
}

void hiloPedidoEspecial::__init__(QMutex* mutexPE, ColaBebes* colabb){
    this->mutPE = mutexPE;
    this->colabbPE = colabb;
    this->running = true;
}

void hiloPedidoEspecial::run(){
    while (!(this->running)){
        //sleep(1);
    }
    //encolar al bebé
    //sleep(1);
}

void hiloPedidoEspecial::stop(){
    this->running = false;
}

void hiloPedidoEspecial::continuar(){
    this->running = true;
}

void hiloPedidoEspecial::setTiempo(int _tiempo){
    pedido->tiempoLectura = _tiempo;
}
