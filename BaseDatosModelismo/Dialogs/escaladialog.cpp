#include "escaladialog.h"
#include "ui_escaladialog.h"

EscalaDialog::EscalaDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EscalaDialog)
{
    ui->setupUi(this);
}

EscalaDialog::~EscalaDialog()
{
    delete ui;
}
