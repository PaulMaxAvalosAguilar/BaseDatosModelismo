#include "escaladialog.h"
#include "ui_escaladialog.h"

EscalaDialog::EscalaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EscalaDialog)
{
    ui->setupUi(this);
}

EscalaDialog::~EscalaDialog()
{
    delete ui;
}

void EscalaDialog::on_buttonBox_accepted()
{
    accept();
}

void EscalaDialog::on_buttonBox_rejected()
{
    reject();
}
