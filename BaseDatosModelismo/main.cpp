#include "mainwindow.h"
#include <QApplication>
#include "BaseDatos/marca.h"
#include "BaseDatos/escala.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Registration of custom types for comparisons as QVariant objects
    qRegisterMetaType<Marca>();
    QMetaType::registerComparators<Marca>();
    qRegisterMetaType<Escala>();
    QMetaType::registerComparators<Escala>();

    //Show Main window
    MainWindow w;
    w.show();

    return a.exec();
}
