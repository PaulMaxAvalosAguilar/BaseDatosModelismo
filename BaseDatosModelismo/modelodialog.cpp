#include "modelodialog.h"
#include "ui_aniadirdialog.h"
#include "QDebug"
#include <memory>
#include <vector>
#include <QDebug>

using namespace std;

ModeloDialog::ModeloDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AniadirDialog),
    listaMarcas(),
    listaEscalas(),
    man(DatabaseManager::instance())
{
    ui->setupUi(this);
    ReadDependencies();

}

ModeloDialog::ModeloDialog(QWidget *parent, int id):
    QDialog(parent),
    ui(new Ui::AniadirDialog),
    listaMarcas(),
    listaEscalas(),
    man(DatabaseManager::instance())
{
    ui->setupUi(this);

    //Fill combo boxes
    ReadDependencies();

    //Get current object foreign keys
    unique_ptr<Modelo> modeloptr=
            std::move(man.modelodao.getRecord(id)->at(0));
    int numeroMarca = modeloptr->getMarca();
    int numeroEscala = modeloptr->getEscala();

    //Get foreign keys objects
    unique_ptr<Marca> marcaptr =
            std::move(man.marcadao.getRecord(numeroMarca)->at(0));
    unique_ptr<Escala> escalaptr =
            std::move(man.escaladao.getRecord(numeroEscala)->at(0));

    //Get combo box position of foreign keys
    int marcaIndex = ui->marcaCB->findData(QVariant::fromValue(*marcaptr));
    int escalaIndex = ui->escalaCB->findData(QVariant::fromValue(*escalaptr));


    //Set all dialog values
    if(marcaIndex != -1){
        ui->marcaCB->setCurrentIndex(marcaIndex);
    }

    if(escalaIndex != -1){
        ui->escalaCB->setCurrentIndex(escalaIndex);
    }

    ui->codigole->setText(modeloptr->getCodigo());
    ui->nombrele->setText(modeloptr->getNombre());
    ui->unidadesSpinBox->setValue(modeloptr->getNumeroUnidades());
    //set all dialog values
}

ModeloDialog::~ModeloDialog()
{
    delete ui;
}

Modelo ModeloDialog::modelo()
{
    Modelo model;

    //Get dialog values and add them to Modelo object
    model.setMarca(ui->marcaCB->itemData(ui->marcaCB->currentIndex())
                                     .value<Marca>().getId());
    model.setCodigo(ui->codigole->text());
    model.setNombre(ui->nombrele->text());
    model.setEscala(ui->escalaCB->itemData(ui->escalaCB->currentIndex())
                    .value<Escala>().getId());
    model.setNumeroUnidades(ui->unidadesSpinBox->value());

    return model;
}

void ModeloDialog::ReadDependencies()
{

    //Fill marcas and escalas combo boxes
    listaMarcas = man.marcadao.getAllRecords();
    for(uint i = 0; i < listaMarcas->size(); i++){
        ui->marcaCB->addItem(listaMarcas->at(i)->getNombre(),
                             QVariant::fromValue(*listaMarcas->at(i)));
    }

    listaEscalas = man.escaladao.getAllRecords();
    for(uint i = 0; i < listaEscalas->size(); i++){
        ui->escalaCB->addItem(listaEscalas->at(i)->getValor(),
                              QVariant::fromValue(*listaEscalas->at(i)));
    }
    //Fill marcas and escalas combo boxes
}

void ModeloDialog::on_buttonBox_accepted()
{
    modelo();
    accept();
}

void ModeloDialog::on_buttonBox_rejected()
{
    reject();
}


