#include "mainwindow.h"
#include <QApplication>
#include "BaseDatos/marca.h"
#include "BaseDatos/escala.h"
#include <QDesktopWidget>
#include <QStyle>
#include <QScreen>
#include <QGuiApplication>

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


    //Set window in the center
    QRect screenGeometry = QGuiApplication::screens().at(0)->geometry();
    int x = (screenGeometry.width()- w.width()) / 2;
    int y = (screenGeometry.height()- w.height()) / 2;
    w.move(x, y);


    w.show();

    return a.exec();
}
