#include "globals.h"

int aleatorio(int min, int max){
    std::uniform_int_distribution<int> distribucion(min, max);
    return distribucion(*QRandomGenerator::global());
}

/* ... The object returned by this function is thread-safe and may be used in any thread without locks.
 *  It may also be copied and the resulting QRandomGenerator will also access the operating system facilities,
 *  but they will not generate the same sequence.
Note: This function is thread-safe. */
bool aletorioBooleanoSystem64(void){
    std::uniform_int_distribution<int> distribucion(0,1);
    return (bool) distribucion(*QRandomGenerator64::system());
}

/* ...Accesses to this object are thread-safe and it may therefore be used in any thread without locks.
 *  The object may also be copied and the sequence produced by the copy will be the same as the shared object will produce.
 *  Note, however, that if there are other threads accessing the global object, those threads may obtain samples
 *  at unpredictable intervals.
Note: This function is thread-safe. */
bool aleatorioBooleanoGlobal64(void){
    std::uniform_int_distribution<int> distribucion(0,1);
    return (bool) distribucion(*QRandomGenerator64::global());
}

QMutex mutexFabricante_FabricaAmor;
QMutex mutexFabricante_FabricaArte;
QMutex mutexFabricante_FabricaOdio;
QMutex mutexColaBebesFabricados;

bool detener = false;
bool pausa = false;
