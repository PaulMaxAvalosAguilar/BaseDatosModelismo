#include "mainwindow.h"
#include "escalamanager.h"
#include "marcamanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MarcaManager w;

    //EscalaManager w;

    MainWindow w;
    w.show();


    return a.exec();
}
