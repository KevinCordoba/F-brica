#include "fabricaarte.h"

bool ColaFabricaArte::vacia(void){
    return frente == nullptr;
}

void ColaFabricaArte::encolar(NodoArte * nodoArte){
    if (vacia())
        frente = nodoArte;
    else {
        NodoArte * tmp = frente;
        while (tmp->siguiente != nullptr){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = nodoArte;
    }
    espacioOcupado++;
}

NodoArte* ColaFabricaArte::desencolar(void){
    if (vacia())
        return nullptr;
    else {
        NodoArte * borrado = frente;
        frente = frente->siguiente;
        borrado->siguiente = nullptr;
        espacioOcupado--;
        return borrado;
    }
}

NodoArte* ColaFabricaArte::verFrente(void){
    return frente;
}

bool ColaFabricaArte::llena(void){
    return espacioOcupado >= limite;
}

void ColaFabricaArte::imprimir(void){
    QString texto = "[ ";
    if (!vacia()){
        NodoArte* tmp = frente;
        while (tmp->siguiente != nullptr) {
            if (tmp->completo)
                texto.append(" Arte completo,");
            else
                texto.append(" Arte vacio,");
            tmp = tmp->siguiente;
        }
        if (tmp->completo)
            texto.append(" Arte completo");
        else
            texto.append(" Arte vacio ");
    }
    texto.append(" ]");
    qDebug() << texto;
}

/* Este init es para la version extensa de la ventana Simulacion */
//void FabricaArte::init(bool _encendido,
//                       int _limite,
//                       int _intervalo,
//                       QLabel * _labelPrimero,
//                       QLabel * _labelSegundo,
//                       QLabel * _labelTercero,
//                       QLabel * _labelEstado,
//                       QLabel * _labelEspacioOcupado,
//                       QLabel * _labelIntervalo,
//                       QMutex * _mutex){
//    this->encendido = _encendido;
//    this->colaFabricaArte = new ColaFabricaArte(_limite);
//    this->intervalo = _intervalo;
//    this->labelPrimero = _labelPrimero;
//    this->labelSegundo = _labelSegundo;
//    this->labelTercero = _labelTercero;
//    this->labelEstado = _labelEstado;
//    this->labelEspacioOcupado = _labelEspacioOcupado;
//    this->labelIntervalo = _labelIntervalo;
//    this->mutex = _mutex;
//    this->w = labelPrimero->width();
//    this->h = labelPrimero->height();
//}

/* Version minima */
void FabricaArte::init(bool _encendido,
                       int _limite,
                       int _intervalo,
                       QLabel * _labelEstado,
                       QLabel * _labelEspacioOcupado,
                       QLabel * _labelIntervalo,
                       QMutex * _mutex){
    this->encendido = _encendido;
    this->colaFabricaArte = new ColaFabricaArte(_limite);
    this->intervalo = _intervalo;
    this->labelEstado = _labelEstado;
    this->labelEspacioOcupado = _labelEspacioOcupado;
    this->labelIntervalo = _labelIntervalo;
    this->mutex = _mutex;
}

void FabricaArte::run(){
    while (!detener) {
        while(pausa){
            labelEstado->setText("Simulacion pausada");
            //qDebug() << "Fabrica Arte : Simulacion en pausa.";
            sleep(1);
        }
        if (encendido){
            labelEstado->setText("Estado : ON");
            refrescarLabels();
            if (colaFabricaArte->llena()){
                encendido = false;
            } else {
                mutex->lock();
                NodoArte * nuevoSentimientoArte = new NodoArte(aleatorioBooleanoGlobal64());
                colaFabricaArte->encolar(nuevoSentimientoArte);
                colaFabricaArte->imprimir();
                //qDebug() << "Nuevo sentimiento de Arte agregado : " << nuevoSentimientoArte->completo;
                mutex->unlock();
                sleep(intervalo);
            }
        } else {
            labelEstado->setText("Estado : OFF");
            labelIntervalo->setText(QString::number(intervalo));
            sleep(1);
            //qDebug() << "Fabrica Arte : apagada.";
        }
    }
    labelEstado->setText("Fabrica detenida");
    //qDebug() << "FabricaArte : Simulacion detenida.";
}

/* Version extensa de Simulacion */
//void FabricaArte::refrescarLabels(void){
//    labelPrimero->clear();
//    labelSegundo->clear();
//    labelTercero->clear();
//    labelEspacioOcupado->setText(QString::number(colaFabricaArte->espacioOcupado));
//    int indice = 0;
//    NodoArte * tmp = colaFabricaArte->frente;
//    while (indice < 3 && tmp != nullptr){
//        QPixmap pix;
//        if (tmp->completo)
//            pix = QPixmap(":/Recursos/ImagenesProyecto/arteCompleto.png");
//        else
//            pix = QPixmap(":/Recursos/ImagenesProyecto/arteVacio.png");
//        if (indice == 0)
//            labelPrimero->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
//        if (indice == 1)
//            labelSegundo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
//        if (indice == 2)
//            labelTercero->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
//        tmp = tmp->siguiente;
//        indice++;
//    }
//    return;
//}

/* Version minima */
void FabricaArte::refrescarLabels(void){
    labelEspacioOcupado->setText(QString::number(colaFabricaArte->espacioOcupado));
    labelIntervalo->setText(QString::number(intervalo));
    return;
}
