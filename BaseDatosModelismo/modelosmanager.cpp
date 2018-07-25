#include "modelosmanager.h"
#include "ui_modelosmanager.h"
#include "modelodialog.h"
#include "BaseDatos/modelo.h"
#include "BaseDatos/modelodao.h"
#include <QScrollBar>
#include <QDebug>

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
    ModeloDialog dal(this);
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

    QScrollBar *verticalScroll = ui->tableWidget->verticalScrollBar();
    QScrollBar *horizontalScroll = ui->tableWidget->verticalScrollBar();
    int lastVscrollposition = verticalScroll->value();
    int lastHscrollposition = horizontalScroll->value();



    listaModelos = man.modelodao.getAllRecords();

    ui->tableWidget->setRowCount(0);

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


    ui->tableWidget->horizontalHeader()->setStretchLastSection(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch);

    ui->tableWidget->setColumnWidth(0, 10);

    verticalScroll->setValue(lastVscrollposition);
    horizontalScroll->setValue(lastHscrollposition);
}



void ModelosManager::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QTableWidgetItem *item = ui->tableWidget->item(row,0);
    (void)column;

}

