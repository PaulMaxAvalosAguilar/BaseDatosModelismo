#include "marcamanager.h"
#include "ui_marcamanager.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"
#include "BaseDatos/marca.h"

MarcaManager::MarcaManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarcaManager)
{
    ui->setupUi(this);
    DatabaseManager::instance();
}

MarcaManager::~MarcaManager()
{
    delete ui;
}

void MarcaManager::on_marcapushButton_clicked()
{
    DatabaseManager &man = DatabaseManager::instance();

    Marca marca;

    marca.setNombre(std::move(ui->marcalineEdit->text()));

    man.marcadao.addRecord(marca);


}
