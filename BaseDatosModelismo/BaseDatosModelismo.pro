#-------------------------------------------------
#
# Project created by QtCreator 2018-07-19T20:17:36
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BaseDatosModelismo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    BaseDatos/DatabaseManager/databasemanager.cpp \
    BaseDatos/modelo.cpp \
    BaseDatos/modelodao.cpp \
    BaseDatos/marca.cpp \
    BaseDatos/marcadao.cpp \
    BaseDatos/escala.cpp \
    BaseDatos/escaladao.cpp \
    escalamanager.cpp \
    marcamanager.cpp


HEADERS += \
        mainwindow.h \
    BaseDatos/DatabaseManager/databasemanager.h \
    BaseDatos/modelo.h \
    BaseDatos/modelodao.h \
    BaseDatos/marca.h \
    BaseDatos/marcadao.h \
    BaseDatos/escala.h \
    BaseDatos/escaladao.h \
    escalamanager.h \
    marcamanager.h


FORMS += \
        mainwindow.ui \
    escalamanager.ui \
    marcamanager.ui

