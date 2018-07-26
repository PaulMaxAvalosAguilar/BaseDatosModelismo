#include "mainwindow.h"
#include "escalamanager.h"
#include "marcamanager.h"
#include <QApplication>
#include "BaseDatos/marca.h"
#include "BaseDatos/escala.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MarcaManager w;

    //EscalaManager w;

    qRegisterMetaType<Marca>();
    QMetaType::registerComparators<Marca>();
    qRegisterMetaType<Escala>();
    QMetaType::registerComparators<Escala>();

    MainWindow w;
    w.show();


    return a.exec();
}
