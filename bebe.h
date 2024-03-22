#ifndef BEBE_H
#define BEBE_H

#include "globals.h"

struct NodoBebe
{
    NodoBebe * siguiente;
    enum Tipo{Moreno = 0,
              Afrodescendiente,
              Rubio,
              Castano,
              Pelirrojo,
              Pink,
              BadBunny,
              Pitufo,
              Defectuoso} tipo;

    NodoBebe(int _tipo){
        this->tipo = (Tipo)_tipo;
        siguiente = nullptr;
    }
};

struct ColaBebes {
    NodoBebe * frente;
    int limite;
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

    int cantMorenosDesencolados = 0;
    int cantAfrodescendientesDesencolados = 0;
    int cantRubiosDesencolados = 0;
    int cantCastanosDesencolados = 0;
    int cantPelirrojosDesencolados = 0;
    int cantPinksDesencolados = 0;
    int cantBadBunnysDesencolados = 0;
    int cantPitufosDesencolados = 0;
    int cantDefectuososDesencolados = 0;

    ColaBebes(int _limite){
        this->limite = _limite;
        frente = nullptr;
    }

    void encolar(NodoBebe*);
    NodoBebe* desencolar(void);
    NodoBebe* verFrente(void);
    bool vacia(void);
    void imprimir(void);
    bool llena(void);
    void registrarEncolado(NodoBebe::Tipo);
    void registrarDesencolado(NodoBebe::Tipo);
    void imprimirRegistro(void);
};

#endif // BEBE_H
