#include "mainwindow.h"
#include "fabricaamor.h"
#include "globals.h"
#include <QApplication>
#include <QDebug>
#include "fabricaodio.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
