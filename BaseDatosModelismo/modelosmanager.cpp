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

    configureTablesettings();
    updateTable();

    connect(&man.modelodao, SIGNAL(addedRecord()),this, SLOT(updateTable()));
    connect(&man.modelodao, SIGNAL(updatedRecord()),this, SLOT(updateTable()));
    connect(&man.modelodao, SIGNAL(removedRecord()),this, SLOT(updateTable()));

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

    //GET CURRENT SCROLLBARS POSITIONS
    QScrollBar *verticalScroll = ui->tableWidget->verticalScrollBar();
    QScrollBar *horizontalScroll = ui->tableWidget->verticalScrollBar();
    int lastVscrollposition = verticalScroll->value();
    int lastHscrollposition = horizontalScroll->value();
    //GET CURRENT SCROLLBARS POSITIONS

    //Read database
    listaModelos = man.modelodao.getAllRecords();

    //Erase table contents
    ui->tableWidget->setRowCount(0);

    //Set table contents
    for(uint i = 0; i < listaModelos->size(); i++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 id, new QTableWidgetItem(
                                     QString::number(
                                         listaModelos->at(i)->getId())));
        //look into foreign key desired value
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
        //look into foreign key desired value
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

    //RESET SCROLLBARS POSITIONS
    verticalScroll->setValue(lastVscrollposition);
    horizontalScroll->setValue(lastHscrollposition);
    //RESET SCROLLBARS POSIITONS
}

void ModelosManager::configureTablesettings()
{
    ui->tableWidget->horizontalHeader()->setStretchLastSection(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch);
    ui->tableWidget->setColumnWidth(0, 10);
    ui->tableWidget->hideColumn(0);
}



void ModelosManager::on_tableWidget_cellDoubleClicked(int row, int column)
{
    int result;
    (void) column;
    QTableWidgetItem *iditem = ui->tableWidget->item(row,0);

    int id = iditem->data(0).toInt();
    ModeloDialog dal(this,id, false);
    dal.setWindowTitle("Leer Modelo");
    result = dal.exec();

    if(result == QDialog::Rejected){
        return;
    }


}

void ModelosManager::on_updPB_clicked()
{
    if(ui->tableWidget->selectedItems().empty()){
        return;
    }else{


        int result;
        int row = ui->tableWidget->selectedItems().at(0)->row();
        QTableWidgetItem *iditem = ui->tableWidget->item(row,0);

        int id = iditem->data(0).toInt();

        ModeloDialog dal(this, id);
        dal.setWindowTitle("Actualizar Modelo");
        result = dal.exec();
        if(result == QDialog::Rejected){
            return;
        }
        Modelo modelo =  dal.modelo();
        man.modelodao.updateRecord(modelo);

    }
}

void ModelosManager::on_delPB_clicked()
{
    if(ui->tableWidget->selectedItems().empty()){
        return;
    }else {
        int result;
        int row = ui->tableWidget->selectedItems().at(0)->row();
        QTableWidgetItem *iditem = ui->tableWidget->item(row,0);

        int id = iditem->data(0).toInt();
        ModeloDialog dal(this, id, true);
        dal.setWindowTitle("Eliminar Modelo");
        result = dal.exec();
        if(result == QDialog::Rejected){
            return;
        }
    }
}
