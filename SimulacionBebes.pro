QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    almacen.cpp \
    bebe.cpp \
    fabricaamor.cpp \
    fabricaarte.cpp \
    fabricante.cpp \
    fabricaodio.cpp \
    globals.cpp \
    hilopedidoespecial.cpp \
    main.cpp \
    mainwindow.cpp \
    pedidoespecial.cpp \
    simulacion.cpp \
    simulacionminima.cpp

HEADERS += \
    almacen.h \
    bebe.h \
    fabricaamor.h \
    fabricaarte.h \
    fabricante.h \
    fabricaodio.h \
    globals.h \
    hilopedidoespecial.h \
    mainwindow.h \
    pedidoespecial.h \
    simulacion.h \
    simulacionminima.h

FORMS += \
    mainwindow.ui \
    simulacion.ui \
    simulacionminima.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos.qrc
