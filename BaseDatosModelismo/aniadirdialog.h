#ifndef ANIADIRDIALOG_H
#define ANIADIRDIALOG_H

#include <QDialog>
#include <memory>
#include <vector>
#include "BaseDatos/DatabaseManager/databasemanager.h"
#include "BaseDatos/marca.h"
#include "BaseDatos/escala.h"
#include "BaseDatos/modelo.h"



namespace Ui {
class AniadirDialog;
}

class AniadirDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AniadirDialog(QWidget *parent = 0);
    ~AniadirDialog();

    Modelo modelo();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AniadirDialog *ui;
    std::unique_ptr<std::vector<std::unique_ptr<Marca>>> listaMarcas;
    std::unique_ptr<std::vector<std::unique_ptr<Escala>>> listaEscalas;
    DatabaseManager &man;
};

#endif // ANIADIRDIALOG_H
