#include "pedidoespecial.h"

pedidoEspecial::pedidoEspecial()
{
    QStringList listaS;
    QString cadena;
    QFile archivo;
    existe = false;
    tiempoLectura = 2;
}

//void pedidoEspecial::__init__()

void pedidoEspecial::leerArchivo(){
    archivo.setFileName("C:/Users/kevin/Desktop/I Semestre 2021/Estructura de Datos/Proyectos/FabricaBebes/PedidoEspecial/pedidos.txt");
    if (!archivo.exists()){
        this->existe = false;
    }
    else{
        archivo.open(QIODevice::ReadOnly | QIODevice::Text);
        if(!archivo.isOpen()){
            //qDebug() << "No se pudo abrir";
        }
        else{
            existe = true;
            cadena = archivo.readAll();
            //qDebug() << cadena;
            listaS = cadena.split(";");
            //qDebug() << listaS;
        }
    }
}
