#include "aniadirdialog.h"
#include "ui_aniadirdialog.h"


AniadirDialog::AniadirDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AniadirDialog),
    listaMarcas(),
    listaEscalas(),
    man(DatabaseManager::instance())
{
    ui->setupUi(this);

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

AniadirDialog::~AniadirDialog()
{
    delete ui;
}

Modelo AniadirDialog::modelo()
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

void AniadirDialog::on_buttonBox_accepted()
{
    modelo();

    accept();
}

void AniadirDialog::on_buttonBox_rejected()
{
    reject();
}


