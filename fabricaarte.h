#ifndef FABRICAARTE_H
#define FABRICAARTE_H

#include "globals.h"

extern bool aleatorioBooleanoGlobal64(void);

struct NodoArte{
    bool completo;
    NodoArte * siguiente;

    NodoArte(bool _completo){
        completo = _completo;
        siguiente = nullptr;
    }
};

struct ColaFabricaArte {
    NodoArte * frente;
    int limite;
    int espacioOcupado = 0;

    ColaFabricaArte(int _limite){
        limite = _limite;
        frente = nullptr;
    }

    void encolar(NodoArte*);
    NodoArte* desencolar(void);
    NodoArte* verFrente(void);
    bool vacia(void);
    void imprimir(void);
    bool llena(void);
};

class FabricaArte : public QThread
{
public:
    QMutex * mutex;

    bool encendido;

    int intervalo;

    ColaFabricaArte * colaFabricaArte;

    QLabel *labelPrimero,*labelSegundo,*labelTercero,*labelEstado,*labelEspacioOcupado,*labelIntervalo;

    //int w,h;

    FabricaArte(){};

    //void init(bool,int,int,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QMutex*);

    void init(bool,int,int,QLabel*,QLabel*,QLabel*,QMutex*);

    void run();

    void refrescarLabels(void);
};

#endif // FABRICAARTE_H
