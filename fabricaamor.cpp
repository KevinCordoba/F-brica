#include "fabricaamor.h"

void NodoAmor::setTipo(int _tipo){
    switch(_tipo){
    case 0:
        tipo = VACIO;
        break;
    case 1:
        tipo = MEDIO;
        break;
    case 2:
        tipo = COMPLETO;
        break;
    default:
        qDebug() << "Tipo invalido";
    }
}

bool ColaFabricaAmor::vacia(void){
    return frente == nullptr;
}

void ColaFabricaAmor::encolar(NodoAmor * nodoAmor){
    if (vacia())
        frente = nodoAmor;
    else {
        NodoAmor * tmp = frente;
        while (tmp->siguiente != nullptr){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = nodoAmor;
    }
    espacioOcupado++;
}

NodoAmor* ColaFabricaAmor::desencolar(void){
    if (vacia())
        return nullptr;
    else {
        NodoAmor * borrado = frente;
        frente = frente->siguiente;
        borrado->siguiente = nullptr;
        espacioOcupado--;
        return borrado;
    }
}

NodoAmor* ColaFabricaAmor::verFrente(void){
    return frente;
}

bool ColaFabricaAmor::llena(void){
    return espacioOcupado >= limite;
}

void ColaFabricaAmor::imprimir(void){
    QString texto = "[ ";
    if (!vacia()){
        NodoAmor* tmp = frente;
        while (tmp->siguiente != nullptr) {
            if (tmp->tipo == NodoAmor::COMPLETO)
                texto.append(" Amor completo, ");
            if (tmp->tipo == NodoAmor::MEDIO)
                texto.append(" Amor medio, ");
            if (tmp->tipo == NodoAmor::VACIO)
                texto.append(" Amor vacio, ");
            tmp = tmp->siguiente;
        }
        if (tmp->tipo == NodoAmor::COMPLETO)
            texto.append(" Amor completo");
        if (tmp->tipo == NodoAmor::MEDIO)
            texto.append(" Amor medio");
        if (tmp->tipo == NodoAmor::VACIO)
            texto.append(" Amor vacio ");
    }
    texto.append(" ]");
    qDebug() << texto;
}

/* Este init es para la version extensa de la ventana Simulacion */
//void FabricaAmor::init(bool _encendido,
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
//    this->colaFabricaAmor = new ColaFabricaAmor(_limite);
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
void FabricaAmor::init(bool _encendido,
                       int _limite,
                       int _intervalo,
                       QLabel * _labelEstado,
                       QLabel * _labelEspacioOcupado,
                       QLabel * _labelIntervalo,
                       QMutex * _mutex){
    this->encendido = _encendido;
    this->colaFabricaAmor = new ColaFabricaAmor(_limite);
    this->intervalo = _intervalo;
    this->labelEstado = _labelEstado;
    this->labelEspacioOcupado = _labelEspacioOcupado;
    this->labelIntervalo = _labelIntervalo;
    this->mutex = _mutex;
}

void FabricaAmor::run(){
    while (!detener) {
        while(pausa){
            labelEstado->setText("Simulacion pausada");
            //qDebug() << "Fabrica Amor : Simulacion en pausa.";
            sleep(1);
        }
        if (encendido){
            labelEstado->setText("Estado : ON");
            refrescarLabels();
            /* Si la cola de una fabrica se llena detiene automaticamente la
             * fabrica */
            if (colaFabricaAmor->llena()){
                encendido = false;
            } else {
                mutex->lock();
                NodoAmor * nuevoSentimientoAmor = new NodoAmor(aleatorio(0,2));
                colaFabricaAmor->encolar(nuevoSentimientoAmor);
                colaFabricaAmor->imprimir();
                //qDebug() << "Nuevo sentimiento de amor agregado : " << nuevoSentimientoAmor->tipo;
                mutex->unlock();
                sleep(intervalo);
            }
        } else {
            sleep(1);
            labelEstado->setText("Estado : OFF");
            labelIntervalo->setText(QString::number(intervalo));
            //qDebug() << "Fabrica Amor : apagada.";
        }
    }
    labelEstado->setText("Fabrica detenida");
    //qDebug() << "FabricaAmor : Simulacion detenida.";
}

/* Version extensa de Simulacion */
//void FabricaAmor::refrescarLabels(void){
//    labelPrimero->clear();
//    labelSegundo->clear();
//    labelTercero->clear();
//    labelEspacioOcupado->setText(QString::number(colaFabricaAmor->espacioOcupado));
//    labelIntervalo->setText(QString::number(intervalo));
//    int indice = 0;
//    NodoAmor * tmp = colaFabricaAmor->frente;
//    while (indice < 3 && tmp != nullptr){
//        QPixmap pix;
//        if (tmp->tipo == NodoAmor::COMPLETO)
//            pix = QPixmap(":/Recursos/ImagenesProyecto/amorCompleto.png");
//        else if (tmp->tipo == NodoAmor::MEDIO)
//            pix = QPixmap(":/Recursos/ImagenesProyecto/amorMedio.png");
//        else if (tmp->tipo == NodoAmor::VACIO)
//            pix = QPixmap(":/Recursos/ImagenesProyecto/amorVacio.png");
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

void FabricaAmor::refrescarLabels(void){
    labelEspacioOcupado->setText(QString::number(colaFabricaAmor->espacioOcupado));
    labelIntervalo->setText(QString::number(intervalo));
    return;
}
