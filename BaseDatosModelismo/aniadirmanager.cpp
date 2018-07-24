#include "aniadirmanager.h"
#include "ui_aniadirmanager.h"

Aniadirmanager::Aniadirmanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Aniadirmanager)
{
    ui->setupUi(this);
}

Aniadirmanager::~Aniadirmanager()
{
    delete ui;
}
