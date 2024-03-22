#ifndef FABRICAOdio_H
#define FABRICAOdio_H

#include "globals.h"

extern bool aleatorioBooleanoGlobal64(void);

struct NodoOdio{
    bool completo;
    NodoOdio * siguiente;

    NodoOdio(bool _completo){
        completo = _completo;
        siguiente = nullptr;
    }
};

struct ColaFabricaOdio {
    NodoOdio * frente;
    int limite;
    int espacioOcupado = 0;

    ColaFabricaOdio(int _limite) {
        frente = nullptr;
        limite = _limite;
    }

    void encolar(NodoOdio*);
    NodoOdio* desencolar(void);
    NodoOdio* verFrente(void);
    bool vacia(void);
    void imprimir(void);
    bool llena(void);
};

class FabricaOdio : public QThread
{
public:
    QMutex * mutex;

    bool encendido;

    int intervalo;

    ColaFabricaOdio * colaFabricaOdio;

    QLabel *labelPrimero,*labelSegundo,*labelTercero,*labelEstado,*labelEspacioOcupado,*labelIntervalo;

    //int w,h;

    FabricaOdio(){};

    //void init(bool,int,int,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QMutex*);

    void init(bool,int,int,QLabel*,QLabel*,QLabel*,QMutex*);

    void run();

    void refrescarLabels(void);
};

#endif // FABRICAOdio_H
