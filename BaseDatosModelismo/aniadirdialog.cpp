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

void AniadirDialog::on_buttonBox_accepted()
{
    accept();
}

void AniadirDialog::on_buttonBox_rejected()
{
    reject();
}

int AniadirDialog::getNumeroUnidades() const
{
    return numeroUnidades;
}

QString AniadirDialog::getEscala() const
{
    return escala;
}

QString AniadirDialog::getNombre() const
{
    return nombre;
}

QString AniadirDialog::getCodigo() const
{
    return codigo;
}

QString AniadirDialog::getMarca() const
{
    return marca;
}

