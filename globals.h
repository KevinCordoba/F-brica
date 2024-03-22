#ifndef GLOBALS_H
#define GLOBALS_H

#include <QLabel>
#include <random>
#include <QThread>
#include <mutex>
#include <QMutex>
#include <QRandomGenerator64>
#include <iostream>
#include <QDebug>
#include <QPixmap>


int aleatorio(int min,int max);
bool aleatorioBooleanoSystem64(void);
bool aleatorioBooleanoGlobal64(void);

extern QMutex mutexFabricante_FabricaAmor;
extern QMutex mutexFabricante_FabricaArte;
extern QMutex mutexFabricante_FabricaOdio;
extern QMutex mutexColaBebesFabricados;

extern bool detener;
extern bool pausa;

#endif // GLOBALS_H
