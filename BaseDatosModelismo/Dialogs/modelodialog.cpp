#include "modelodialog.h"
#include "ui_modelodialog.h"
#include "QDebug"
#include <memory>
#include <vector>
#include <QDebug>

using namespace std;

//Add new model dialog variant
ModeloDialog::ModeloDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AniadirDialog),
    listaMarcas(),
    listaEscalas(),
    man(DatabaseManager::instance()),
    modeloid(0)
{
    ui->setupUi(this);

    //Fill comboboxes
    ReadDependencies();

}

//Update model dialog variant
ModeloDialog::ModeloDialog(QWidget *parent, int id):
    QDialog(parent),
    ui(new Ui::AniadirDialog),
    listaMarcas(),
    listaEscalas(),
    man(DatabaseManager::instance()),
    modeloid(id)
{
    ui->setupUi(this);

    //Fill combo boxes
    ReadDependencies();
    //Fill data with searched value
    setInputWidgetsData(id);
}

//Read only model dialog variant
ModeloDialog::ModeloDialog(QWidget *parent, int id, bool visibility):
    QDialog(parent),
    ui(new Ui::AniadirDialog),
    listaMarcas(),
    listaEscalas(),
    man(DatabaseManager::instance()),
    modeloid(id)
{
    ui->setupUi(this);

    unique_ptr<Modelo> modelo =std::move(man.modelodao.getRecord(id)->at(0));
    int numeroMarca = modelo->getMarca();
    int numeroEscala = modelo->getEscala();

    unique_ptr<Marca> marca = std::move(
                man.marcadao.getRecord(numeroMarca)->at(0));
    unique_ptr<Escala> escala = std::move(
                man.escaladao.getRecord(numeroEscala)->at(0));

    ui->marcaCB->addItem(marca->getNombre(), QVariant::fromValue(*marca));
    ui->escalaCB->addItem(escala->getValor(), QVariant::fromValue(*escala));

    //Fill combo boxes
    setInputWidgetsData(id);
    ui->buttonBox->setVisible(visibility);

}

ModeloDialog::~ModeloDialog()
{
    delete ui;
}

Modelo ModeloDialog::modelo()
{
    Modelo model;

    model.setId(modeloid);
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

void ModeloDialog::setInputWidgetsData(int id)
{
    //Read database / Object source charged in RAM
    unique_ptr<Modelo> modeloptr=
            std::move(man.modelodao.getRecord(id)->at(0));

    //Get current object foreign keys values
    int numeromarcaBuscada = modeloptr->getMarca();
    int numeroescalaBuscada = modeloptr->getEscala();

    //Create a list of dependencies for testing emptiness
    unique_ptr<vector<unique_ptr<Marca>>> marca;
    unique_ptr<vector<unique_ptr<Escala>>> escala;

    //Search whether dependencies exist or not
    marca = std::move(man.marcadao.getRecord(numeromarcaBuscada));
    escala = std::move(man.escaladao.getRecord(numeroescalaBuscada));



    unique_ptr<Marca> marcaptr = (marca->empty())? nullptr
                                                 : std::move(marca->at(0)) ;
    unique_ptr<Escala> escalaptr = (marca->empty())? nullptr
                                                   :std::move(escala->at(0));
    //Search wheter dependencies exist or not

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

void ModeloDialog::on_buttonBox_accepted()
{
    accept();
}

void ModeloDialog::on_buttonBox_rejected()
{
    reject();
}

const std::unique_ptr<std::vector<std::unique_ptr<Escala> > > &ModeloDialog::getListaEscalas()
{
    return listaEscalas;
}

const std::unique_ptr<std::vector<std::unique_ptr<Marca> > > &ModeloDialog::getListaMarcas()
{
    return listaMarcas;
}


