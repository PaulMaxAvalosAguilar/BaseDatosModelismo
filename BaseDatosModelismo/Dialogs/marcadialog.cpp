#include "marcadialog.h"
#include "ui_marcadialog.h"
#include <memory>

MarcaDialog::MarcaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MarcaDialog),
    man(DatabaseManager::instance()),
    marcaid(0)
{
    ui->setupUi(this);
}

MarcaDialog::MarcaDialog(QWidget *parent, int id):
    QDialog(parent),
    ui(new Ui::MarcaDialog),
    man(DatabaseManager::instance()),
    marcaid(id)
{
    ui->setupUi(this);

    //Fill data with searched value
    setInputWidgetsData(id);
}

MarcaDialog::MarcaDialog(QWidget *parent, int id, bool visibility):
    QDialog(parent),
    ui(new Ui::MarcaDialog),
    man(DatabaseManager::instance()),
    marcaid(id)
{
    ui->setupUi(this);

    std::unique_ptr<Marca> marca =std::move(man.marcadao.getRecord(id)->at(0));

    ui->marcale->setText(marca->getNombre());

    ui->buttonBox->setVisible(visibility);
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

void MarcaDialog::setInputWidgetsData(int id)
{
    std::unique_ptr<Marca> marca= std::move(man.marcadao.getRecord(id)->at(0));

    ui->marcale->setText(marca->getNombre());

}

void MarcaDialog::on_buttonBox_accepted()
{
    accept();
}

void MarcaDialog::on_buttonBox_rejected()
{
    reject();
}
