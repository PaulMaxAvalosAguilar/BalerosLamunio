#-------------------------------------------------
#
# Project created by QtCreator 2018-07-29T18:01:32
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Serie6000
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    BaseDatos/DatabaseManager/databasemanager.cpp \
    BaseDatos/ENTITIES/regla.cpp \
    BaseDatos/DAOs/regladao.cpp \
    BaseDatos/ENTITIES/categoria.cpp \
    BaseDatos/DAOs/categoriadao.cpp \
    BaseDatos/ENTITIES/subcategoria.cpp \
    BaseDatos/DAOs/subcategoriadao.cpp \
    BaseDatos/ENTITIES/codigo.cpp \
    BaseDatos/DAOs/codigodao.cpp \
    BaseDatos/ENTITIES/corebearing.cpp \
    BaseDatos/DAOs/corebearingdao.cpp \
    BaseDatos/ENTITIES/coreplusmodifier.cpp \
    BaseDatos/DAOs/coreplusmodifierdao.cpp \
    BaseDatos/ENTITIES/clasificacion.cpp \
    BaseDatos/DAOs/clasificaciondao.cpp \
    Controllers/DatabaseLogic/databaselogiccontroller.cpp \
    Controllers/reglasvistacontroller.cpp \
    Vistas/reglasvista.cpp \
    Vistas/Dialog/categoriadialog.cpp \
    Vistas/Dialog/regladialog.cpp \
    Vistas/Dialog/subcategoriadialog.cpp \
    Vistas/Dialog/codigodialog.cpp \
    Vistas/searchervista.cpp \
    Controllers/searchervistacontroller.cpp

HEADERS  += mainwindow.h \
    BaseDatos/DatabaseManager/databasemanager.h \
    BaseDatos/ENTITIES/regla.h \
    BaseDatos/DAOs/regladao.h \
    BaseDatos/ENTITIES/categoria.h \
    BaseDatos/DAOs/categoriadao.h \
    BaseDatos/ENTITIES/subcategoria.h \
    BaseDatos/DAOs/subcategoriadao.h \
    BaseDatos/ENTITIES/codigo.h \
    BaseDatos/DAOs/codigodao.h \
    BaseDatos/ENTITIES/corebearing.h \
    BaseDatos/DAOs/corebearingdao.h \
    BaseDatos/ENTITIES/coreplusmodifier.h \
    BaseDatos/DAOs/coreplusmodifierdao.h \
    BaseDatos/ENTITIES/clasificacion.h \
    BaseDatos/DAOs/clasificaciondao.h \
    Controllers/DatabaseLogic/databaselogiccontroller.h \
    Controllers/reglasvistacontroller.h \
    Vistas/reglasvista.h \
    Vistas/Dialog/categoriadialog.h \
    Vistas/Dialog/regladialog.h \
    Vistas/Dialog/subcategoriadialog.h \
    Vistas/Dialog/codigodialog.h \
    Controllers/searchervistacontroller.h \
    Vistas/searchervista.h

FORMS    += mainwindow.ui \
    Vistas/reglasvista.ui \
    Vistas/Dialog/categoriadialog.ui \
    Vistas/Dialog/regladialog.ui \
    Vistas/Dialog/subcategoriadialog.ui \
    Vistas/Dialog/codigodialog.ui \
    Vistas/searchervista.ui
