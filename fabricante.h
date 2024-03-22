#ifndef FABRICANTE_H
#define FABRICANTE_H

#include "globals.h"
#include "bebe.h"
#include "fabricaamor.h"
#include "fabricaarte.h"
#include "fabricaodio.h"

struct NodoBebeDefectuoso{
    QString descripcion;
    NodoBebeDefectuoso * siguiente;

    NodoBebeDefectuoso(QString _descripcion){
        this->descripcion = _descripcion;
        siguiente = nullptr;
    }
};

struct ListaBebesMalos{
    int tamano = 0;
    NodoBebeDefectuoso * primerNodo;

    ListaBebesMalos(){
        primerNodo = nullptr;
    }

    void insertar(NodoBebeDefectuoso*);
    bool isEmpty(void);
    void imprimir(void);
};

struct TablaDecision {
public :
    TablaDecision(){}
    static int crearBebe(NodoAmor*,NodoArte*,NodoOdio*);
};

class Fabricante : public QThread
{
public:
    ListaBebesMalos * listaBebesMalos;

    QMutex * mutexColaAmor;
    QMutex * mutexColaArte;
    QMutex * mutexColaOdio;
    QMutex * mutexColaBebes;

    bool encendido;

    int intervalo;

    ColaFabricaAmor * colaFabricaAmor;
    ColaFabricaArte * colaFabricaArte;
    ColaFabricaOdio * colaFabricaOdio;

    ColaBebes * colaBebesFabricados;

    QLabel *labelAmor,*labelArte,*labelOdio,*labelIntervalo,*labelProbabilidad,*labelEstado;

    //int w,h;

    Fabricante(){};

//    void init(bool,int,ColaFabricaAmor*,ColaFabricaArte*,ColaFabricaOdio*,
//              QMutex*,QMutex*,QMutex*,QMutex*,
//              QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*);

    void init(bool,int,int,ColaFabricaAmor*,ColaFabricaArte*,ColaFabricaOdio*,
              QMutex*,QMutex*,QMutex*,QMutex*,
              QLabel*,QLabel*,QLabel*);

    void run();

    void refrescarLabels(int,enum NodoAmor::Tipo,bool,bool);

    static int cantidadBebes(void);
};

#endif // FABRICANTE_H
