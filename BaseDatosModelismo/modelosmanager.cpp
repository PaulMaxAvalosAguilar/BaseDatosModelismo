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

                                     man.marcadao.getRecord(listaModelos->at(i)->getMarca())
                                     ->at(0)->getNombre()

                                     ));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 Codigo, new QTableWidgetItem(
                                     listaModelos->at(i)->getCodigo()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 Nombre, new QTableWidgetItem(
                                     listaModelos->at(i)->getNombre()));

        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 Escala, new QTableWidgetItem(

                                     man.escaladao.getRecord(listaModelos->at(i)->getEscala())
                                     ->at(0)->getValor()

                                     ));
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


void ModelosManager::on_delPB_clicked()
{
    if(ui->tableWidget->selectedItems().empty()){
        return;
    }else{
        int result;
        int row = ui->tableWidget->selectedItems().at(0)->row();
        QTableWidgetItem *iditem = ui->tableWidget->item(row,0);
        QTableWidgetItem *marcaitem = ui->tableWidget->item(row,1);
        QTableWidgetItem *codigoitem = ui->tableWidget->item(row,2);
        QTableWidgetItem *nombreitem = ui->tableWidget->item(row,3);
        QTableWidgetItem *escalaitem = ui->tableWidget->item(row,4);
        QTableWidgetItem *numeroUnidadesitem = ui->tableWidget->item(row,5);


        int id = iditem->data(0).toInt();
        QString marca = marcaitem->data(0).toString();
        QString codigo = codigoitem->data(0).toString();
        QString nombre = nombreitem->data(0).toString();
        QString escala = escalaitem->data(0).toString();
        int numeroUnidades = numeroUnidadesitem->data(0).toInt();

        qDebug()<<marca;

        ModeloDialog dal(this, id, marca, codigo,nombre,
                         escala, numeroUnidades);
        dal.setWindowTitle("HOlo");
        dal.exec();

        if(result == QDialog::Rejected){
            return;
        }

    }



}
