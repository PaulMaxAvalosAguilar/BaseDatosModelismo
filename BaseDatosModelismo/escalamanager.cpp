#include "escalamanager.h"
#include "ui_escalamanager.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"
#include "BaseDatos/escala.h"

EscalaManager::EscalaManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EscalaManager)
{
    ui->setupUi(this);
    DatabaseManager::instance();

}

EscalaManager::~EscalaManager()
{
    delete ui;
}


void EscalaManager::on_escalaButton_clicked()
{
    DatabaseManager &man = DatabaseManager::instance();

    Escala escala;

    escala.setValor(std::move(
                        ui->escalalineEdit->text()));

    man.escaladao.addRecord(escala);
}
