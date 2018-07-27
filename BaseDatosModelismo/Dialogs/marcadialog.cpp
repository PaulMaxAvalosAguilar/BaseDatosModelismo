#include "marcadialog.h"
#include "ui_marcadialog.h"

MarcaDialog::MarcaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MarcaDialog),
    marcaid(0)
{
    ui->setupUi(this);
}

MarcaDialog::~MarcaDialog()
{
    delete ui;
}

Marca MarcaDialog::marca()
{
    Marca marca;
    marca.setId(marcaid);
    //Get dialog values and add them to Modelo object
    marca.setNombre(ui->marcale->text());

    return marca;
}

void MarcaDialog::on_buttonBox_accepted()
{
    accept();
}

void MarcaDialog::on_buttonBox_rejected()
{
    reject();
}
