#include "fabricante.h"

bool ListaBebesMalos::isEmpty(){
    return primerNodo == nullptr;
}

void ListaBebesMalos::insertar(NodoBebeDefectuoso * nuevoBebeMalo){
    if (isEmpty())
        primerNodo = nuevoBebeMalo;
    else {
        NodoBebeDefectuoso * tmp = primerNodo;
        while (tmp->siguiente != nullptr)
            tmp = tmp->siguiente;
        tmp->siguiente = nuevoBebeMalo;
    }
    tamano++;
}

void ListaBebesMalos::imprimir(void){
    QString texto = "Cantidad de bebes defectuosos [" + QString::number(tamano) + "] : [ ";
    if (!isEmpty()) {
        NodoBebeDefectuoso * tmp = primerNodo;
        while (tmp != nullptr){
            texto.append(tmp->descripcion + " ,");
        }
    }
    texto.append(" ]");
    qDebug() << texto;
}

int TablaDecision::crearBebe(NodoAmor* nodoAmor,NodoArte* nodoArte,NodoOdio* nodoOdio){
    if (nodoAmor->tipo == NodoAmor::COMPLETO && nodoArte->completo && !nodoOdio->completo)
        return 0;
    else if (nodoAmor->tipo == NodoAmor::COMPLETO && nodoArte->completo && nodoOdio->completo)
        return 1;
    else if (nodoAmor->tipo == NodoAmor::COMPLETO && !nodoArte->completo && !nodoOdio->completo)
        return 2;
    else if (nodoAmor->tipo == NodoAmor::COMPLETO && !nodoArte->completo && nodoOdio->completo)
        return 3;
    else if (nodoAmor->tipo == NodoAmor::VACIO && !nodoArte->completo && !nodoOdio->completo)
        return 4;
    else if (nodoAmor->tipo == NodoAmor::VACIO && !nodoArte->completo && nodoOdio->completo)
        return 5;
    else if (nodoAmor->tipo == NodoAmor::MEDIO && nodoArte->completo && !nodoOdio->completo)
        return 6;
    else if (nodoAmor->tipo == NodoAmor::MEDIO && nodoArte->completo && nodoOdio->completo)
        return 7;
    else {
        return 8; // Bebe defectuoso = 8
    }
}

/* Este init es para la version extensa de la ventana Simulacion */
//void Fabricante::init(bool _encendido,
//                      int _intervalo,
//                      ColaFabricaAmor * _colaFabricaAmor,
//                      ColaFabricaArte * _colaFabricaArte,
//                      ColaFabricaOdio * _colaFabricaOdio,
//                      QMutex * _mutexColaAmor,
//                      QMutex * _mutexColaArte,
//                      QMutex * _mutexColaOdio,
//                      QMutex * _mutexColaBebes,
//                      QLabel * _labelIntervalo,
//                      QLabel * _labelProbabilidad,
//                      QLabel * _labelEstado,
//                      QLabel * _labelAmor,
//                      QLabel * _labelArte,
//                      QLabel * _labelOdio)
//{
//    this->encendido = _encendido;
//    this->intervalo = _intervalo;
//    this->colaFabricaAmor = _colaFabricaAmor;
//    this->colaFabricaArte = _colaFabricaArte;
//    this->colaFabricaOdio = _colaFabricaOdio;
//    this->mutexColaAmor = _mutexColaAmor;
//    this->mutexColaArte = _mutexColaArte;
//    this->mutexColaOdio = _mutexColaOdio;
//    this->mutexColaBebes = _mutexColaBebes;
//    this->labelIntervalo = _labelIntervalo;
//    this->labelProbabilidad = _labelProbabilidad;
//    this->labelEstado = _labelEstado;
//    this->labelAmor = _labelAmor;
//    this->labelArte = _labelArte;
//    this->labelOdio = _labelOdio;
//    this->listaBebesMalos = new ListaBebesMalos();
//    this->w = labelAmor->width();
//    this->h = labelAmor->height();
//}

void Fabricante::init(bool _encendido,
                      int _intervalo,
                      int _limiteColaBebes,
                      ColaFabricaAmor * _colaFabricaAmor,
                      ColaFabricaArte * _colaFabricaArte,
                      ColaFabricaOdio * _colaFabricaOdio,
                      QMutex * _mutexColaAmor,
                      QMutex * _mutexColaArte,
                      QMutex * _mutexColaOdio,
                      QMutex * _mutexColaBebes,
                      QLabel * _labelIntervalo,
                      QLabel * _labelProbabilidad,
                      QLabel * _labelEstado)
{
    this->encendido = _encendido;
    this->intervalo = _intervalo;
    this->colaFabricaAmor = _colaFabricaAmor;
    this->colaFabricaArte = _colaFabricaArte;
    this->colaFabricaOdio = _colaFabricaOdio;
    this->mutexColaAmor = _mutexColaAmor;
    this->mutexColaArte = _mutexColaArte;
    this->mutexColaOdio = _mutexColaOdio;
    this->mutexColaBebes = _mutexColaBebes;
    this->labelIntervalo = _labelIntervalo;
    this->labelProbabilidad = _labelProbabilidad;
    this->labelEstado = _labelEstado;
    this->listaBebesMalos = new ListaBebesMalos();
    this->colaBebesFabricados = new ColaBebes(_limiteColaBebes);
}

void Fabricante::run(){
    while (!detener) {
        while (pausa){
            labelEstado->setText("Fabrica pausada");
            qDebug() << "Fabricante : Simulacion en pausa.";
            sleep(1);
        }
        if (encendido){
            /* ----- Labels ----- */
            labelProbabilidad->setText("");
            labelEstado->setText("Estado : ON");
            labelIntervalo->setText(QString::number(intervalo));
            /* ----------------- */
            // solo desencole sentimientos cuando las 3 fabricas NO estan vacias
            mutexColaAmor->lock();
            mutexColaArte->lock();
            mutexColaOdio->lock();
            mutexColaBebes->lock();
            if (!colaFabricaAmor->vacia() && !colaFabricaArte->vacia() && !colaFabricaOdio->vacia()){
                qDebug() << "Hay para hacer bebe";
                NodoAmor * nodoAmor = colaFabricaAmor->desencolar();
                NodoArte * nodoArte = colaFabricaArte->desencolar();
                NodoOdio * nodoOdio = colaFabricaOdio->desencolar();
                int cantBebes = cantidadBebes();
                //refrescarLabels(cantBebes,nodoAmor->tipo,nodoArte->completo,nodoOdio->completo);
                qDebug() << "Cantidad de bebes : " << cantBebes;
                labelProbabilidad->setText(QString::number(cantBebes));
                for (int i = 0; i < cantBebes; i++){
                    if (TablaDecision::crearBebe(nodoAmor,nodoArte,nodoOdio) == NodoBebe::Defectuoso) {
                        listaBebesMalos->insertar(new NodoBebeDefectuoso("Descripcion : Combinacion invalida"));
                        qDebug() << "El bebe es un bebe defectuoso";
                    } else {
                        /* Si no hay campo en la cola de bebes fabricados, los que no quepan,
                         * se convertiran en bebes malos */
                        if (colaBebesFabricados->llena()){
                            listaBebesMalos->insertar(new NodoBebeDefectuoso("Descripcion : Cola de Bebes llena"));
                            qDebug() << "El bebe esta bien pero no hay campo en la cola de bebes";
                        } else {
                            colaBebesFabricados->encolar(new NodoBebe(TablaDecision::crearBebe(nodoAmor,nodoArte,nodoOdio)));
                            qDebug() << "El bebe esta bien y fue encolado a la cola de bebes";
                        }
                    }
                    colaBebesFabricados->imprimir();
                }
            } else {
                qDebug() << "No hay para hacer bebe";
            }
            mutexColaAmor->unlock();
            mutexColaArte->unlock();
            mutexColaOdio->unlock();
            mutexColaBebes->unlock();
            sleep(intervalo);
        } else {
            sleep(1);
            labelEstado->setText("Estado : OFF");
            labelIntervalo->setText(QString::number(intervalo));
            qDebug() << "Fabricante : apagada.";
        }
    }
    labelEstado->setText("Fabrica detenida");
    qDebug() << "Fabricante : Simulacion detenida";
}

//void Fabricante::refrescarLabels(int cantBebes,enum NodoAmor::Tipo tipo, bool arteCompleto,bool odioCompleto){
//    labelProbabilidad->setText(QString::number(cantBebes));
//    /* Label Amor */
//    if (tipo == NodoAmor::COMPLETO)
//        labelAmor->setPixmap(QPixmap(":/Recursos/ImagenesProyecto/amorCompleto.png").scaled(w,h,Qt::KeepAspectRatio));
//    else if (tipo == NodoAmor::MEDIO)
//        labelAmor->setPixmap(QPixmap(":/Recursos/ImagenesProyecto/amorMedio.png").scaled(w,h,Qt::KeepAspectRatio));
//    else if (tipo == NodoAmor::VACIO)
//        labelAmor->setPixmap(QPixmap(":/Recursos/ImagenesProyecto/amorVacio.png").scaled(w,h,Qt::KeepAspectRatio));
//    /* Label Arte */
//    if (arteCompleto)
//        labelArte->setPixmap(QPixmap(":/Recursos/ImagenesProyecto/arteCompleto.png").scaled(w,h,Qt::KeepAspectRatio));
//    else
//        labelArte->setPixmap(QPixmap(":/Recursos/ImagenesProyecto/arteVacio.png").scaled(w,h,Qt::KeepAspectRatio));
//    /* Label Odio */
//    if (odioCompleto)
//        labelOdio->setPixmap(QPixmap(":/Recursos/ImagenesProyecto/evil.png").scaled(w,h,Qt::KeepAspectRatio));
//    else
//        labelOdio->setPixmap(QPixmap(":/Recursos/ImagenesProyecto/angel.png").scaled(w,h,Qt::KeepAspectRatio));
//    return;
//}

int Fabricante::cantidadBebes(void){
    int numeroAleatorio = aleatorio(0,1000);
    if (numeroAleatorio >= 0 && numeroAleatorio <= 900)
        return 1;
    else if (numeroAleatorio > 900 && numeroAleatorio <= 950)
        return 2;
    else if (numeroAleatorio > 950 && numeroAleatorio <= 980)
        return 3;
    else
        return aleatorio(4,6); /* Otra cantidad entre 4 a 6 bebes */
}
