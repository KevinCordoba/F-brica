#include "bebe.h"

bool ColaBebes::vacia(void){
    return frente == nullptr;
}

void ColaBebes::registrarEncolado(NodoBebe::Tipo tipo){
    switch (tipo) {
    case NodoBebe::Moreno:
        cantidadMorenos++;
        break;
    case NodoBebe::Afrodescendiente:
        cantidadAfrodescendientes++;
        break;
    case NodoBebe::Rubio:
        cantidadRubios++;
        break;
    case NodoBebe::Castano:
        cantidadCastanos++;
        break;
    case NodoBebe::Pelirrojo:
        cantidadPelirrojos++;
        break;
    case NodoBebe::Pink:
        cantidadPinks++;
        break;
    case NodoBebe::BadBunny:
        cantidadBadBunnys++;
        break;
    case NodoBebe::Pitufo:
        cantidadPitufos++;
        break;
    case NodoBebe::Defectuoso:
        cantidadDefectuosos++;
        break;
    default:
        break;
    }
    return;
}

void ColaBebes::registrarDesencolado(NodoBebe::Tipo tipo){
    switch(tipo){
    case NodoBebe::Moreno:
        cantMorenosDesencolados++;
        break;
    case NodoBebe::Afrodescendiente:
        cantAfrodescendientesDesencolados++;
        break;
    case NodoBebe::Rubio:
        cantRubiosDesencolados++;
        break;
    case NodoBebe::Castano:
        cantCastanosDesencolados++;
        break;
    case NodoBebe::Pelirrojo:
        cantPelirrojosDesencolados++;
        break;
    case NodoBebe::Pink:
        cantPinksDesencolados++;
        break;
    case NodoBebe::BadBunny:
        cantBadBunnysDesencolados++;
        break;
    case NodoBebe::Pitufo:
        cantPitufosDesencolados++;
        break;
    case NodoBebe::Defectuoso:
        cantDefectuososDesencolados++;
        break;
    default:
        break;
    }
    return;
}

void ColaBebes::imprimirRegistro(void){
    QString registro = "";
    /* Encolados */
    registro.append("Encolados\n");
    registro.append("Bebes morenos : " + QString::number(cantidadMorenos));
    registro.append("\nBebes afros : " + QString::number(cantidadAfrodescendientes));
    registro.append("\nBebes rubios : " + QString::number(cantidadRubios));
    registro.append("\nBebes castanos : " + QString::number(cantidadCastanos));
    registro.append("\nBebes pelirrojos : " + QString::number(cantidadPelirrojos));
    registro.append("\nBebes pinks : " + QString::number(cantidadPinks));
    registro.append("\nBebes badbunnys : " + QString::number(cantidadBadBunnys));
    registro.append("\nBebes pitufos : " + QString::number(cantidadPitufos));
    /* La cantidad de bebes defectuosos encolados deberia ser cero por la logica
     * del fabricante */
    registro.append("\nBebes defectuosos : " + QString::number(cantidadDefectuosos));
    registro.append("\nTotal : " + QString::number(cantidadMorenos+
                                                   cantidadAfrodescendientes+
                                                   cantidadRubios+
                                                   cantidadCastanos+
                                                   cantidadPelirrojos+
                                                   cantidadPinks+
                                                   cantidadBadBunnys+
                                                   cantidadPitufos+
                                                   cantidadDefectuosos));
    /* Desencolados */
    registro.append("Desencolados\n");
    registro.append("Bebes morenos : " + QString::number(cantMorenosDesencolados));
    registro.append("\nBebes afros : " + QString::number(cantAfrodescendientesDesencolados));
    registro.append("\nBebes rubios : " + QString::number(cantRubiosDesencolados));
    registro.append("\nBebes castanos : " + QString::number(cantCastanosDesencolados));
    registro.append("\nBebes pelirrojos : " + QString::number(cantPelirrojosDesencolados));
    registro.append("\nBebes pinks : " + QString::number(cantPinksDesencolados));
    registro.append("\nBebes badbunnys : " + QString::number(cantBadBunnysDesencolados));
    registro.append("\nBebes pitufos : " + QString::number(cantPitufosDesencolados));
    registro.append("\nBebes defectuosos : " + QString::number(cantDefectuososDesencolados));
    registro.append("\nTotal : " + QString::number(cantMorenosDesencolados+
                                                   cantAfrodescendientesDesencolados+
                                                   cantRubiosDesencolados+
                                                   cantCastanosDesencolados+
                                                   cantPelirrojosDesencolados+
                                                   cantPinksDesencolados+
                                                   cantBadBunnysDesencolados+
                                                   cantPitufosDesencolados+
                                                   cantDefectuososDesencolados));
    qDebug() << registro;
}

void ColaBebes::encolar(NodoBebe * nodoBebe){
    registrarEncolado(nodoBebe->tipo);
    if (vacia())
        frente = nodoBebe;
    else {
        NodoBebe * tmp = frente;
        while (tmp->siguiente != nullptr){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = nodoBebe;
    }
    espacioOcupado++;
}

NodoBebe* ColaBebes::desencolar(void){
    if (vacia())
        return nullptr;
    else {
        NodoBebe * borrado = frente;
        frente = frente->siguiente;
        borrado->siguiente = nullptr;
        espacioOcupado--;
        registrarDesencolado(borrado->tipo);
        return borrado;
    }
}

NodoBebe* ColaBebes::verFrente(void){
    return frente;
}

bool ColaBebes::llena(void){
    return espacioOcupado >= limite;
}

void ColaBebes::imprimir(void){
    QString texto = "[ ";
    if (!vacia()){
        NodoBebe * tmp = frente;
        while (tmp->siguiente != nullptr){
            switch (tmp->tipo) {
            case 0:
                texto.append("Bebe Moreno,");
                break;
            case 1:
                texto.append("Bebe Afrodescendiente,");
                break;
            case 2:
                texto.append("Bebe Rubio,");
                break;
            case 3:
                texto.append("Bebe Castano,");
                break;
            case 4:
                texto.append("Bebe Pelirrojo,");
                break;
            case 5:
                texto.append("Bebe Pink,");
                break;
            case 6:
                texto.append("Bebe BadBunny,");
                break;
            case 7:
                texto.append("Bebe Pitufo,");
                break;
            case 8:
                texto.append("Bebe Malo,");
                break;
            default:
                texto.append("Bebe desconocido,");
            }
            tmp = tmp->siguiente;
        }
        switch (tmp->tipo) {
        case 0:
            texto.append("Bebe Moreno ");
            break;
        case 1:
            texto.append("Bebe Afrodescendiente ");
            break;
        case 2:
            texto.append("Bebe Rubio ");
            break;
        case 3:
            texto.append("Bebe Castano ");
            break;
        case 4:
            texto.append("Bebe Pelirrojo ");
            break;
        case 5:
            texto.append("Bebe Pink ");
            break;
        case 6:
            texto.append("Bebe BadBunny ");
            break;
        case 7:
            texto.append("Bebe Pitufo ");
            break;
        case 8:
            texto.append("Bebe Malo ");
            break;
        default:
            texto.append("Bebe desconocido ");
        }
    }
    texto.append(" ]");
    qDebug() << texto;
}
