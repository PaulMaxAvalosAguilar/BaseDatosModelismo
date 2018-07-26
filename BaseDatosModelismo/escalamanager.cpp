#include "escalamanager.h"
#include "ui_escalamanager.h"

EscalaManager::EscalaManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EscalaManager),
    man(DatabaseManager::instance())
{
    ui->setupUi(this);
}

EscalaManager::~EscalaManager()
{
    delete ui;
}
