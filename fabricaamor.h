#ifndef FABRICAAMOR_H
#define FABRICAAMOR_H

#include "globals.h"
#include <QThread>

extern int aleatorio(int,int);

struct NodoAmor {
    enum Tipo{VACIO, MEDIO, COMPLETO} tipo;
    NodoAmor* siguiente;

    NodoAmor(int _tipo){
        siguiente = nullptr;
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
        }
    }

    void setTipo(int _tipo);
};

struct ColaFabricaAmor {
    NodoAmor * frente;
    int limite;
    int espacioOcupado = 0;

    ColaFabricaAmor(int _limite){
        limite = _limite;
        frente = nullptr;
    }

    void encolar(NodoAmor*);
    NodoAmor* desencolar(void);
    NodoAmor* verFrente(void);
    bool vacia(void);
    void imprimir(void);
    bool llena(void);
};

class FabricaAmor : public QThread
{
public:
    QMutex * mutex;

    bool encendido;

    ColaFabricaAmor * colaFabricaAmor;

    int intervalo;

    QLabel *labelPrimero,*labelSegundo,*labelTercero,*labelEstado,*labelEspacioOcupado,*labelIntervalo;

    //int w,h;

    FabricaAmor(){};

    //void init(bool,int,int,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QLabel*,QMutex*);

    void init(bool,int,int,QLabel*,QLabel*,QLabel*,QMutex*);

    void run();

    void refrescarLabels(void);
};

#endif // FABRICAAMOR_H
