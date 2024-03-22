#include "fabricaodio.h"

bool ColaFabricaOdio::vacia(void){
    return frente == nullptr;
}

void ColaFabricaOdio::encolar(NodoOdio * nodoArte){
    if (vacia())
        frente = nodoArte;
    else {
        NodoOdio * tmp = frente;
        while (tmp->siguiente != nullptr){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = nodoArte;
    }
    espacioOcupado++;
}

NodoOdio* ColaFabricaOdio::desencolar(void){
    if (vacia())
        return nullptr;
    else {
        NodoOdio * borrado = frente;
        frente = frente->siguiente;
        borrado->siguiente = nullptr;
        espacioOcupado--;
        return borrado;
    }
}

NodoOdio* ColaFabricaOdio::verFrente(void){
    return frente;
}

bool ColaFabricaOdio::llena(void){
    return espacioOcupado >= limite;
}

void ColaFabricaOdio::imprimir(void){
    QString texto = "[ ";
    if (!vacia()){
        NodoOdio * tmp = frente;
        while (tmp->siguiente != nullptr){
            if (tmp->completo)
                texto.append(" Odio completo, ");
            else
                texto.append(" Odio vacio, ");
            tmp = tmp->siguiente;
        }
        if (tmp->completo)
            texto.append(" Odio completo ");
        else
            texto.append(" Odio vacio ");
    }
    texto.append(" ]");
    qDebug() << texto;
}

/* Este init es para la version extensa de la ventana Simulacion */
//void FabricaOdio::init(bool _encendido,
//                       int _limiteCola,
//                       int _intervalo,
//                       QLabel * _labelPrimero,
//                       QLabel * _labelSegundo,
//                       QLabel * _labelTercero,
//                       QLabel * _labelEstado,
//                       QLabel * _labelEspacioOcupado,
//                       QMutex * _mutex){
//    encendido = _encendido;
//    colaFabricaOdio = new ColaFabricaOdio(_limiteCola);
//    intervalo = _intervalo;
//    labelPrimero = _labelPrimero;
//    labelSegundo = _labelSegundo;
//    labelTercero = _labelTercero;
//    labelEstado = _labelEstado;
//    labelEspacioOcupado = _labelEspacioOcupado;
//    mutex = _mutex;
//    w = labelPrimero->width();
//    h = labelPrimero->height();
//}

/* Version minima */
void FabricaOdio::init(bool _encendido,
                       int _limiteCola,
                       int _intervalo,
                       QLabel * _labelEstado,
                       QLabel * _labelEspacioOcupado,
                       QLabel * _labelIntervalo,
                       QMutex * _mutex){
    this->encendido = _encendido;
    this->colaFabricaOdio = new ColaFabricaOdio(_limiteCola);
    this->intervalo = _intervalo;
    this->labelEstado = _labelEstado;
    this->labelEspacioOcupado = _labelEspacioOcupado;
    this->labelIntervalo = _labelIntervalo;
    this->mutex = _mutex;
}

void FabricaOdio::run() {
    while (!detener) {
        while (pausa){
            labelEstado->setText("Simulacion pausada");
            //qDebug() << "Fabrica Odio : Simulacion en pausa.";
            sleep(1);
        }
        if (encendido){
            labelEstado->setText("Estado : ON");
            refrescarLabels();
            if (colaFabricaOdio->llena())
                encendido = false;
            else {
                mutex->lock();
                NodoOdio * nuevoOdio = new NodoOdio(aleatorioBooleanoGlobal64());
                colaFabricaOdio->encolar(nuevoOdio);
                colaFabricaOdio->imprimir();
                //qDebug() << "Nuevo Odio agregado : " << nuevoOdio->completo;
                mutex->unlock();
                sleep(intervalo);
            }
        } else {
            labelEstado->setText("Estado : OFF");
            labelIntervalo->setText(QString::number(intervalo));
            sleep(1);
            //qDebug() << "Fabrica Odio : Apagada.";
        }
    }
    labelEstado->setText("Fabrica detenida");
    //qDebug() << "Fabrica Odio : Simulacion detenida";
}

/* Version extensa de Simulacion */
//void FabricaOdio::refrescarLabels(void){
//    labelPrimero->clear();
//    labelSegundo->clear();
//    labelTercero->clear();
//    labelEspacioOcupado->setText(QString::number(colaFabricaOdio->espacioOcupado));
//    int indice = 0;
//    NodoOdio * tmp = colaFabricaOdio->frente;
//    while (indice < 3 && tmp != nullptr) {
//        QPixmap pix;
//        if (tmp->completo)
//            pix = QPixmap(":/Recursos/ImagenesProyecto/evil.png");
//        else
//            pix = QPixmap(":/Recursos/ImagenesProyecto/angel.png");
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
void FabricaOdio::refrescarLabels(void){
    labelEspacioOcupado->setText(QString::number(colaFabricaOdio->espacioOcupado));
    labelIntervalo->setText(QString::number(intervalo));
    return;
}
