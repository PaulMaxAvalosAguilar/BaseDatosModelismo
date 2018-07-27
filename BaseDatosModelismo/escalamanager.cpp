#include "escalamanager.h"
#include "ui_escalamanager.h"
#include <QScrollBar>

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
