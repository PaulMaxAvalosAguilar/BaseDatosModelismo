#include "marcadialog.h"
#include "ui_marcadialog.h"

MarcaDialog::MarcaDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarcaDialog)
{
    ui->setupUi(this);
}

MarcaDialog::~MarcaDialog()
{
    delete ui;
}
