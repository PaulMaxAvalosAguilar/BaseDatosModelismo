#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"
#include "BaseDatos/modelo.h"
#include <memory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DatabaseManager &man = DatabaseManager::instance();
    listaMarcas(man.marcadao.getAllRecords());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    DatabaseManager &man = DatabaseManager::instance();

    Modelo *modelo = new Modelo();

    modelo->setMarca(ui->marcaCB->itemText(ui->marcaCB->currentIndex()));
    modelo->setCodigo(ui->codigole->text());
    modelo->setNombre(ui->nombrele->text());
    modelo->setEscala(ui->escalale->text());
    modelo->setNumeroUnidades(ui->unidadesSpinBox->value());

    man.modelodao.addRecord(*modelo);

    delete modelo;

}
