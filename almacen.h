#ifndef ALMACEN_H
#define ALMACEN_H

#include "bebe.h"

struct Almacen {
    NodoBebe * frente;
    int espacioOcupado = 0;

    int cantidadMorenos = 0;
    int cantidadAfrodescendientes = 0;
    int cantidadRubios = 0;
    int cantidadCastanos = 0;
    int cantidadPelirrojos= 0;
    int cantidadPinks = 0;
    int cantidadBadBunnys = 0;
    int cantidadPitufos = 0;
    int cantidadDefectuosos = 0;

    Almacen(){
        frente = nullptr;
    }

    void encolar(NodoBebe*);
    NodoBebe* desencolar(void);
    NodoBebe* verFrente(void);
    bool vacio(void);
    void imprimir(void);
    void registrarEncolado(NodoBebe::Tipo);
    void imprimirRegistro(void);
};

#endif // ALMACEN_H
