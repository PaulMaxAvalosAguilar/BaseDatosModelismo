#include "marcasmanager.h"
#include "ui_marcasmanager.h"
#include "Dialogs/marcadialog.h"
#include <QScrollBar>
#include <QMessageBox>

MarcasManager::MarcasManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarcasManager),
    man(DatabaseManager::instance()),
    listaMarcas()
{
    ui->setupUi(this);

    //Set table format
    configureTablesettings();

    //Read all registers into table
    updateTable();

    //Check needed updates of table
    connect(&man.marcadao, SIGNAL(addedRecord()),this, SLOT(updateTable()));
    connect(&man.marcadao, SIGNAL(updatedRecord()),this, SLOT(updateTable()));
    connect(&man.marcadao, SIGNAL(removedRecord()),this, SLOT(updateTable()));
}

MarcasManager::~MarcasManager()
{
    delete ui;
}

void MarcasManager::configureTablesettings()
{
    ui->tableWidget->horizontalHeader()->setStretchLastSection(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->setColumnWidth(0, 10);
    ui->tableWidget->hideColumn(0);
}

void MarcasManager::updateTable()
{
    //GET CURRENT SCROLLBARS POSITIONS
    QScrollBar *verticalScroll = ui->tableWidget->verticalScrollBar();
    QScrollBar *horizontalScroll = ui->tableWidget->verticalScrollBar();
    int lastVscrollposition = verticalScroll->value();
    int lastHscrollposition = horizontalScroll->value();
    //GET CURRENT SCROLLBARS POSITIONS

    //Read database
    listaMarcas = man.marcadao.getAllRecords();

    //Erase table contents
    ui->tableWidget->setRowCount(0);

    //Set table contents
    for(uint i = 0; i < listaMarcas->size(); i++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, id,
                                 new QTableWidgetItem(
                                     QString::number(listaMarcas->at(i)->getId())
                                     ));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, Nombre,
                                 new QTableWidgetItem(
                                     listaMarcas->at(i)->getNombre()
                                     ));
    }


    //RESET SCROLLBARS POSITIONS
    verticalScroll->setValue(lastVscrollposition);
    horizontalScroll->setValue(lastHscrollposition);
    //RESET SCROLLBARS POSIITONS


}

void MarcasManager::on_addButton_clicked()
{
    int result;

    //Launch dialog
    MarcaDialog dal(this);
    dal.setWindowTitle("Añadir Marca");
    result = dal.exec();

    //Check if dialog was accepted
    if(result == QDialog::Rejected){
        return;
    }

    //Check if dependencies have records: Not null values
    //Not null nombre

    //Persist marca
    Marca marca = dal.marca();

    if(marca.getNombre().isEmpty()){
        //Checking not null nombre
        QMessageBox box;
        box.setText("Tienes que escribir un nombre válido");
        box.exec();
        return;
    }

    man.marcadao.addRecord(marca);

}

void MarcasManager::on_updateButton_clicked()
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
        MarcaDialog dal(this,id);
        dal.setWindowTitle("Actualizar marca");
        result = dal.exec();

        if(result == QDialog::Rejected){
            return;
        }


        //Check if dependencies have records: Not null values
        //Not null nombre

        //Checking not null marcas or escalas

        //Persist modelo dao
        Marca marca = dal.marca();

        if(marca.getNombre().isEmpty()){
            //Checking not null nombre
            QMessageBox box;
            box.setText("Tienes que escribir un nombre válido");
            box.exec();
            return;
        }

        man.marcadao.updateRecord(marca);
    }
}

void MarcasManager::on_deleteButton_clicked()
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
        MarcaDialog dal(this, id, true);
        dal.setWindowTitle("Eliminar Marca");
        result = dal.exec();

        //Check if dialog was accepted
        if(result == QDialog::Rejected){
            return;
        }

        //Remove object
        Marca marca = dal.marca();
        man.marcadao.removeRecord(marca.getId());
    }
}

void MarcasManager::on_tableWidget_cellDoubleClicked(int row, int column)
{
    int result;
    (void) column;//Used value for suprressing warnings

    //Get id of object for being searched and filled into dialog
    QTableWidgetItem *iditem = ui->tableWidget->item(row,0);
    int id = iditem->data(0).toInt();


    //Launch dialog with filled values of id / hide buttons
    MarcaDialog dal(this,id, false);
    dal.setWindowTitle("Leer Modelo");
    result = dal.exec();

    //Check if dialog was accepted
    if(result == QDialog::Rejected){
        return;//Dialog should be rejected in all cases
    }
}
