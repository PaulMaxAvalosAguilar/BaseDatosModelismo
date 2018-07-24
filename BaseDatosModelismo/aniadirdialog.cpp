#include "aniadirdialog.h"
#include "ui_aniadirdialog.h"

AniadirDialog::AniadirDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AniadirDialog)
{
    ui->setupUi(this);

}

AniadirDialog::~AniadirDialog()
{
    delete ui;
}
