#ifndef PEDIDOESPECIAL_H
#define PEDIDOESPECIAL_H

#include <QFile>
#include<QString>
#include <QDebug>

class pedidoEspecial
{
public:
    QStringList listaS;
    QString cadena;
    QFile archivo;
    bool existe;
    int tiempoLectura;
    pedidoEspecial();
    void __init__();
    void leerArchivo();
};

#endif // PEDIDOESPECIAL_H
