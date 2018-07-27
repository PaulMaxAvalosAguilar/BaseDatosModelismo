#include "marcasmanager.h"
#include "ui_marcasmanager.h"
#include "Dialogs/marcadialog.h"
#include <QScrollBar>
#include <QDialog>

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
}

void MarcasManager::on_updateButton_clicked()
{

}

void MarcasManager::on_deleteButton_clicked()
{

}

void MarcasManager::on_tableWidget_cellDoubleClicked(int row, int column)
{

}
