#include "mainwindow.h"
#include <QApplication>
#include "BaseDatos/marca.h"
#include "BaseDatos/escala.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<Marca>();
    QMetaType::registerComparators<Marca>();
    qRegisterMetaType<Escala>();
    QMetaType::registerComparators<Escala>();

    MainWindow w;
    w.show();

    return a.exec();
}
