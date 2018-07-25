#include "modelosmanager.h"
#include "ui_modelosmanager.h"
#include "aniadirdialog.h"
#include "BaseDatos/modelo.h"
#include "BaseDatos/modelodao.h"

ModelosManager::ModelosManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelosManager),
    man(DatabaseManager::instance()),
    listaModelos()
{
    ui->setupUi(this);

    updateTable();

    connect(&man.modelodao, SIGNAL(addedRecord()),this, SLOT(updateTable()));

}

ModelosManager::~ModelosManager()
{
    delete ui;
}

void ModelosManager::on_addPB_clicked()
{
    int result;
    AniadirDialog dal(this);
    dal.setWindowTitle("Añadir Modelo");
    result = dal.exec();

    if(result == QDialog::Rejected){
        return;
    }

    Modelo modelo = dal.modelo();
    man.modelodao.addRecord(modelo);

}

void ModelosManager::updateTable()
{
    listaModelos = man.modelodao.getAllRecords();

    for(uint i = 0; i < listaModelos->size(); i++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 id, new QTableWidgetItem(
                                     QString::number(
                                         listaModelos->at(i)->getId())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 Marca, new QTableWidgetItem(
                                     listaModelos->at(i)->getMarca()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 Codigo, new QTableWidgetItem(
                                     listaModelos->at(i)->getCodigo()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 Nombre, new QTableWidgetItem(
                                     listaModelos->at(i)->getNombre()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 Escala, new QTableWidgetItem(
                                     listaModelos->at(i)->getNombre()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 Unidades, new QTableWidgetItem(
                                     QString::number(
                                         listaModelos->at(i)->getNumeroUnidades())));
    }
}
