#include "modelosmanager.h"
#include "ui_modelosmanager.h"
#include "aniadirdialog.h"

ModelosManager::ModelosManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelosManager)
{
    ui->setupUi(this);
}

ModelosManager::~ModelosManager()
{
    delete ui;
}

void ModelosManager::on_addPB_clicked()
{
    AniadirDialog dal(this);
    dal.exec();


    /*
    Modelo modelo;

        modelo.setMarca(ui->marcaCB->itemData(ui->marcaCB->currentIndex())
                         .value<Marca>().getNombre());

        modelo.setCodigo(ui->codigole->text());
        modelo.setNombre(ui->nombrele->text());

        modelo.setEscala(ui->escalaCB->itemData(ui->escalaCB->currentIndex())
                         .value<Escala>().getValor());

        modelo.setNumeroUnidades(ui->unidadesSpinBox->value());

        man.modelodao.addRecord(modelo);*/
}
