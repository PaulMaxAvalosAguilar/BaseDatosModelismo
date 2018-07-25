#include "modelosmanager.h"
#include "ui_modelosmanager.h"
#include "aniadirdialog.h"
#include "BaseDatos/modelo.h"

ModelosManager::ModelosManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelosManager),
    man(DatabaseManager::instance())
{
    ui->setupUi(this);
}

ModelosManager::~ModelosManager()
{
    delete ui;
}

void ModelosManager::on_addPB_clicked()
{
    int result;
    AniadirDialog dal(this);
    dal.setWindowTitle("Añadir Modelo");
    result = dal.exec();

    if(result == QDialog::Rejected){
        return;
    }

    Modelo modelo = dal.modelo();
    man.modelodao.addRecord(modelo);
}
