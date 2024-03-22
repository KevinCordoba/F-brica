#include "almacen.h"

bool Almacen::vacio(void){
    return frente == nullptr;
}

void Almacen::registrarEncolado(NodoBebe::Tipo tipo){
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

void Almacen::imprimirRegistro(void){
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
    qDebug() << registro;
}

void Almacen::encolar(NodoBebe * nodoBebe){
    if (vacio())
        frente = nodoBebe;
    else {
        NodoBebe * tmp = frente;
        while (tmp->siguiente != nullptr)
            tmp = tmp->siguiente;
        tmp->siguiente = nodoBebe;
    }
    espacioOcupado++;
}

NodoBebe* Almacen::desencolar(void){
    if (vacio())
        return nullptr;
    else {
        NodoBebe * borrado = frente;
        frente = frente->siguiente;
        borrado->siguiente = nullptr;
        espacioOcupado--;
        return borrado;
    }
}

NodoBebe* Almacen::verFrente(void){
    return frente;
}

void Almacen::imprimir(void){
    QString texto = "[ ";
    if (!vacio()){
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
                texto.append("Bebe Castaño,");
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
                break;
            }
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
            texto.append("Bebe Castaño ");
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
            break;
        }
    }
    texto.append(" ]");
    qDebug() << texto;
}
