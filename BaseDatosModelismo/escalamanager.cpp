#include "escalamanager.h"
#include "ui_escalamanager.h"
#include "Dialogs/escaladialog.h"
#include <QScrollBar>
#include <QMessageBox>

EscalaManager::EscalaManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EscalaManager),
    man(DatabaseManager::instance())
{
    ui->setupUi(this);

    //Set table format
    configureTablesettings();

    //Read all registers into table
    updateTable();

    //Check needed updates of table
    connect(&man.escaladao, SIGNAL(addedRecord()),this, SLOT(updateTable()));
    connect(&man.escaladao, SIGNAL(updatedRecord()),this, SLOT(updateTable()));
    connect(&man.escaladao, SIGNAL(removedRecord()),this, SLOT(updateTable()));
}

EscalaManager::~EscalaManager()
{
    delete ui;
}

void EscalaManager::configureTablesettings()
{
    ui->tableWidget->horizontalHeader()->setStretchLastSection(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->setColumnWidth(0, 10);
    ui->tableWidget->hideColumn(0);
}

void EscalaManager::updateTable()
{

    //GET CURRENT SCROLLBARS POSITIONS
    QScrollBar *verticalScroll = ui->tableWidget->verticalScrollBar();
    QScrollBar *horizontalScroll = ui->tableWidget->verticalScrollBar();
    int lastVscrollposition = verticalScroll->value();
    int lastHscrollposition = horizontalScroll->value();
    //GET CURRENT SCROLLBARS POSITIONS


    //Read database
    listaEscalas = man.escaladao.getAllRecords();

    //Erase table contents
    ui->tableWidget->setRowCount(0);

    //Set table contents
    for(uint i = 0; i < listaEscalas->size(); i++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, id,
                                 new QTableWidgetItem(
                                     QString::number(listaEscalas->at(i)->getId()
                                     )));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, valor,
                                 new QTableWidgetItem(
                                     listaEscalas->at(i)->getValor()
                                     ));
    }


    //RESET SCROLLBARS POSITIONS
    verticalScroll->setValue(lastVscrollposition);
    horizontalScroll->setValue(lastHscrollposition);
    //RESET SCROLLBARS POSIITONS
}

void EscalaManager::on_addButton_clicked()
{
    int result;

    //Launch dialog
    EscalaDialog dal(this);
    dal.setWindowTitle("Añadir Escala");
    result = dal.exec();

    //Check if dialog was accepted
    if(result == QDialog::Rejected){
        return;
    }


    //Check if dependencies have records: Not null values
    //Not null valor

    //Persist marca
    Escala escala = dal.escala();

    if(escala.getValor().isEmpty()){
        //Checking not null nombre
        QMessageBox box;
        box.setText("Tienes que escribir un valor válido");
        box.exec();
        return;
    }

    man.escaladao.addRecord(escala);
}


void EscalaManager::on_updateButton_clicked()
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
        EscalaDialog dal(this,id);
        dal.setWindowTitle("Actualizar escala");
        result = dal.exec();

        if(result == QDialog::Rejected){
            return;
        }

        //Check if dependencies have records: Not null values
        //Not null valor

        //Persist marca
        Escala escala = dal.escala();

        if(escala.getValor().isEmpty()){
            //Checking not null nombre
            QMessageBox box;
            box.setText("Tienes que escribir un valor válido");
            box.exec();
            return;
        }

        man.escaladao.updateRecord(escala);
    }
}


void EscalaManager::on_deleteButton_clicked()
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
        EscalaDialog dal(this, id, true);
        dal.setWindowTitle("Eliminar Escala");
        result = dal.exec();

        //Check if dialog was accepted
        if(result == QDialog::Rejected){
            return;
        }

        //Remove object
        Escala escala = dal.escala();
        man.escaladao.removeRecord(escala.getId());
    }
}

void EscalaManager::on_tableWidget_cellDoubleClicked(int row, int column)
{
    int result;
    (void) column;//Used value for suprressing warnings

    //Get id of object for being searched and filled into dialog
    QTableWidgetItem *iditem = ui->tableWidget->item(row,0);
    int id = iditem->data(0).toInt();


    //Launch dialog with filled values of id / hide buttons
    EscalaDialog dal(this,id, false);
    dal.setWindowTitle("Leer Modelo");
    result = dal.exec();

    //Check if dialog was accepted
    if(result == QDialog::Rejected){
        return;//Dialog should be rejected in all cases
    }
}
