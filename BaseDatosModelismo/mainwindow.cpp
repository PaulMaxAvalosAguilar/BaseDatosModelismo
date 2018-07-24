#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"
#include "BaseDatos/modelo.h"
#include <memory>
#include <QDebug>
#include <BaseDatos/marca.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    listaMarcas()
{
    ui->setupUi(this);
    DatabaseManager &man = DatabaseManager::instance();


    listaMarcas = man.marcadao.getAllRecords();
    for(uint i = 0; i < listaMarcas->size(); i++){


        ui->marcaCB->addItem(listaMarcas->at(i)->getNombre(), QVariant::fromValue(*listaMarcas->at(i)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    DatabaseManager &man = DatabaseManager::instance();

    Modelo *modelo = new Modelo();

    modelo->setMarca(ui->marcaCB->itemData(ui->marcaCB->currentIndex()).value<Marca>().getNombre());

    modelo->setCodigo(ui->codigole->text());
    modelo->setNombre(ui->nombrele->text());
    modelo->setEscala(ui->escalale->text());
    modelo->setNumeroUnidades(ui->unidadesSpinBox->value());

    man.modelodao.addRecord(*modelo);

    delete modelo;

}
