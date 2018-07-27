#include "escaladialog.h"
#include "ui_escaladialog.h"

EscalaDialog::EscalaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EscalaDialog),
    escalaid(0)
{
    ui->setupUi(this);
}

EscalaDialog::~EscalaDialog()
{
    delete ui;
}

Escala EscalaDialog::escala()
{
    Escala escala;

    escala.setId(escalaid);
    //Get dialog values and add them to Modelo object
    escala.setValor(ui->valorle->text());

    return escala;
}

void EscalaDialog::on_buttonBox_accepted()
{
    accept();
}

void EscalaDialog::on_buttonBox_rejected()
{
    reject();
}
