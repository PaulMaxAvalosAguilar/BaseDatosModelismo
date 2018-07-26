#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    man(new ModelosManager),
    marcas(new MarcasManager)
{
    ui->setupUi(this);


    ui->modelostab->layout()->addWidget(man);
    ui->marcaTab->layout()->addWidget(marcas);

}

MainWindow::~MainWindow()
{
    delete ui;
}


