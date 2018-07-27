#include "modelosmanager.h"
#include "ui_modelosmanager.h"
#include "Dialogs/modelodialog.h"
#include "BaseDatos/modelo.h"
#include "BaseDatos/modelodao.h"
#include "BaseDatos/marca.h"
#include "BaseDatos/escala.h"
#include <QScrollBar>
#include <memory>
#include <QMessageBox>


ModelosManager::ModelosManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelosManager),
    man(DatabaseManager::instance()),
    listaModelos()
{
    ui->setupUi(this);

    //Set table format
    configureTablesettings();

    //Read all registers into table
    updateTable();

    //Check needed updates of table
    connect(&man.modelodao, SIGNAL(addedRecord()),this, SLOT(updateTable()));
    connect(&man.modelodao, SIGNAL(updatedRecord()),this, SLOT(updateTable()));
    connect(&man.modelodao, SIGNAL(removedRecord()),this, SLOT(updateTable()));

}

ModelosManager::~ModelosManager()
{
    delete ui;
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

    //Create list of dependencies for testing emptiness
    std::unique_ptr<std::vector<std::unique_ptr<Marca>>> marca;
    std::unique_ptr<std::vector<std::unique_ptr<Escala>>> escala;


    //Set table contents
    for(uint i = 0; i < listaModelos->size(); i++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        //Save current object dependencies numbers
        int numeromarcaBuscada = listaModelos->at(i)->getMarca();
        int numeroescalaBuscada = listaModelos->at(i)->getEscala();

        //Search for dependencies if exist
        marca  = std::move(man.marcadao.getRecord(numeromarcaBuscada));
        escala = std::move(man.escaladao.getRecord(numeroescalaBuscada));


        if(marca->empty()){
            numeromarcaBuscada = -1;
        }

        if(escala->empty()){
            numeroescalaBuscada = -1;
        }
        //Search for dependencies if exist


        //Fill dependencies properly
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 Marcac, new QTableWidgetItem(

                                     (numeromarcaBuscada == -1)?
                                         0
                                       :marca->at(0)->getNombre()

                                         ));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 Escalac, new QTableWidgetItem(

                                     (numeroescalaBuscada == -1)?
                                         0
                                       :escala->at(0)->getValor()

                                         ));
        //Fill dependencies properly

        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 id, new QTableWidgetItem(
                                     QString::number(
                                         listaModelos->at(i)->getId())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 Codigo, new QTableWidgetItem(
                                     listaModelos->at(i)->getCodigo()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                 Nombre, new QTableWidgetItem(
                                     listaModelos->at(i)->getNombre()));
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

void ModelosManager::on_addPB_clicked()
{
    int result;

    //Launch dialog
    ModeloDialog dal(this);
    dal.setWindowTitle("Añadir Modelo");
    result = dal.exec();

    //Check if dialog was accepted
    if(result == QDialog::Rejected){
        return;
    }

    //Check if dependencies have records: Not null values
    //Not null Marca, codigo, nombre, escala

    //Checking not null marcas or escalas
    if(!(dal.getListaMarcas()->empty() || dal.getListaEscalas()->empty())){

        //Persist modelo dao
        Modelo modelo = dal.modelo();

        if(modelo.getCodigo().isEmpty() || modelo.getNombre().isEmpty()){
            //Checking not null nombre o escalas
            QMessageBox box;
            box.setText("Tienes que escribir un código y un nombre válidos");
            box.exec();
            return;
        }

        man.modelodao.addRecord(modelo);
    }else{
        QMessageBox box;
        box.setText("No puedes guardar un registro con marcas o escalas vacías");
        box.exec();
    }

}


void ModelosManager::on_updPB_clicked()
{
    //Check if there is something selected
    if(ui->tableWidget->selectedItems().empty()){
        return;
    }else{

        int result;

        //Get id of object for being searched and filled into dialog
        int row = ui->tableWidget->selectedItems().at(0)->row();
        QTableWidgetItem *iditem = ui->tableWidget->item(row,0);
        int id = iditem->data(0).toInt();

        //Launch dialog with filled values of id
        ModeloDialog dal(this, id);
        dal.setWindowTitle("Actualizar Modelo");
        result = dal.exec();

        //Check if dialog was accepted
        if(result == QDialog::Rejected){
            return;
        }

        //Update object
        Modelo modelo =  dal.modelo();
        man.modelodao.updateRecord(modelo);

    }
}

void ModelosManager::on_delPB_clicked()
{
    //Check if there is something selected
    if(ui->tableWidget->selectedItems().empty()){
        return;
    }else {

        int result;

        //Get id of object for being searched and filled into dialog
        int row = ui->tableWidget->selectedItems().at(0)->row();
        QTableWidgetItem *iditem = ui->tableWidget->item(row,0);
        int id = iditem->data(0).toInt();

        //Launch dialog with filled values of id
        ModeloDialog dal(this, id, true);
        dal.setWindowTitle("Eliminar Modelo");
        result = dal.exec();

        //Check if dialog was accepted
        if(result == QDialog::Rejected){
            return;
        }

        //Remove object
        Modelo modelo = dal.modelo();
        man.modelodao.removeRecord(modelo.getId());
    }
}


void ModelosManager::on_tableWidget_cellDoubleClicked(int row, int column)
{
    int result;
    (void) column;//Used value for suprressing warnings

    //Get id of object for being searched and filled into dialog
    QTableWidgetItem *iditem = ui->tableWidget->item(row,0);
    int id = iditem->data(0).toInt();

    //Launch dialog with filled values of id / hide buttons
    ModeloDialog dal(this,id, false);
    dal.setWindowTitle("Leer Modelo");
    result = dal.exec();

    //Check if dialog was accepted
    if(result == QDialog::Rejected){
        return;//Dialog should be rejected in all cases
    }
}
