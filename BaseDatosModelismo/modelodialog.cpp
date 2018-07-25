#include "modelodialog.h"
#include "ui_aniadirdialog.h"
#include "QDebug"

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

ModeloDialog::ModeloDialog(QWidget *parent, int id,
                             QString marca, QString codigo,
                             QString nombre, QString escala,
                             int numeroUnidades):
    QDialog(parent),
    ui(new Ui::AniadirDialog),
    listaMarcas(),
    listaEscalas(),
    man(DatabaseManager::instance())
{
    ui->setupUi(this);
    ReadDependencies();
    ui->codigole->setText(codigo);
    ui->nombrele->setText(nombre);
    ui->unidadesSpinBox->setValue(numeroUnidades);
}

ModeloDialog::~ModeloDialog()
{
    delete ui;
}

Modelo ModeloDialog::modelo()
{
    Modelo model;


    model.setMarca(ui->marcaCB->itemData(ui->marcaCB->currentIndex())
                   .value<Marca>().getNombre());

    model.setCodigo(ui->codigole->text());
    model.setNombre(ui->nombrele->text());

    model.setEscala(ui->escalaCB->itemData(ui->escalaCB->currentIndex())
                    .value<Escala>().getValor());

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


