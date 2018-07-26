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
    ReadDependencies();

    unique_ptr<Modelo> modeloptr=
            std::move(man.modelodao.getRecord(id)->at(0));

    int numeroMarca = modeloptr->getMarca();
    int numeroEscala = modeloptr->getEscala();

    unique_ptr<Marca> marcaptr =
            std::move(man.marcadao.getRecord(numeroMarca)->at(0));

    unique_ptr<Escala> escalaptr =
            std::move(man.escaladao.getRecord(numeroEscala)->at(0));



    QVariant variant = QVariant::fromValue(*marcaptr);


    int marcaIndex = ui->marcaCB->findData(variant);
    int escalaIndex = ui->marcaCB->findData(QVariant::fromValue(*escalaptr));

    qDebug()<<marcaptr->getId();
    qDebug()<< variant.value<Marca>().getId();
    qDebug()<<marcaptr->getNombre();
    qDebug()<< variant.value<Marca>().getNombre();
    qDebug()<<marcaIndex;

    if(marcaIndex != -1){

        ui->marcaCB->setCurrentIndex(marcaIndex);

    }

    if(escalaIndex != -1){
        ui->escalaCB->setCurrentIndex(escalaIndex);
    }


    ui->codigole->setText(modeloptr->getCodigo());
    ui->nombrele->setText(modeloptr->getNombre());
    ui->unidadesSpinBox->setValue(modeloptr->getNumeroUnidades());

}

ModeloDialog::~ModeloDialog()
{
    delete ui;
}

Modelo ModeloDialog::modelo()
{
    Modelo model;


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


