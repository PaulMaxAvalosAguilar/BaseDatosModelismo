#include "marcasmanager.h"
#include "ui_marcasmanager.h"

MarcasManager::MarcasManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarcasManager),
    man(DatabaseManager::instance())
{
    ui->setupUi(this);
}

MarcasManager::~MarcasManager()
{
    delete ui;
}
