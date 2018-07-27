#include "marcadialog.h"
#include "ui_marcadialog.h"

MarcaDialog::MarcaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MarcaDialog)
{
    ui->setupUi(this);
}

MarcaDialog::~MarcaDialog()
{
    delete ui;
}

void MarcaDialog::on_buttonBox_accepted()
{
    accept();
}

void MarcaDialog::on_buttonBox_rejected()
{
    reject();
}
