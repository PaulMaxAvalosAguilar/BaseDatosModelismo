#include "escaladialog.h"
#include "ui_escaladialog.h"
#include <memory>

EscalaDialog::EscalaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EscalaDialog),
    man(DatabaseManager::instance()),
    escalaid(0)
{
    ui->setupUi(this);
}

EscalaDialog::EscalaDialog(QWidget *parent, int id):
    QDialog(parent),
    ui(new Ui::EscalaDialog),
    man(DatabaseManager::instance()),
    escalaid(id)
{
    ui->setupUi(this);

    //Fill data with searched value
    setInputWidgetsData(id);
}

EscalaDialog::EscalaDialog(QWidget *parent, int id, bool visibility):
    QDialog(parent),
    ui(new Ui::EscalaDialog),
    man(DatabaseManager::instance()),
    escalaid(id)
{
    ui->setupUi(this);

    std::unique_ptr<Escala> escala = std::move(man.escaladao.getRecord(id)->at(0));

    ui->valorle->setText(escala->getValor());

    ui->buttonBox->setVisible(visibility);

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

void EscalaDialog::setInputWidgetsData(int id)
{
    std::unique_ptr<Escala> escala =  std::move(man.escaladao.getRecord(id)->at(0));

    ui->valorle->setText(escala->getValor());

}

void EscalaDialog::on_buttonBox_accepted()
{
    accept();
}

void EscalaDialog::on_buttonBox_rejected()
{
    reject();
}
