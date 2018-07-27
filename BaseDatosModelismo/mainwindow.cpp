#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    man(new ModelosManager),
    marcas(new MarcasManager),
    escalas(new EscalaManager)
{
    ui->setupUi(this);

    //Add widgets to Gui
    ui->modelostab->layout()->addWidget(man);
    ui->marcaTab->layout()->addWidget(marcas);
    ui->escalasTab->layout()->addWidget(escalas);
}

MainWindow::~MainWindow()
{
    delete ui;
}


