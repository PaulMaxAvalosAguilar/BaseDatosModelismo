#ifndef ANIADIRDIALOG_H
#define ANIADIRDIALOG_H

#include <QDialog>
#include <memory>
#include <vector>
#include <QString>
#include "BaseDatos/DatabaseManager/databasemanager.h"
#include "BaseDatos/marca.h"
#include "BaseDatos/escala.h"
#include "BaseDatos/modelo.h"



namespace Ui {
class AniadirDialog;
}

class ModeloDialog : public QDialog
{
    Q_OBJECT

public:
    //Add new Model Dialog variant
    explicit ModeloDialog(QWidget *parent = 0);
    //Update Model Dialog variant
    ModeloDialog(QWidget *parent, int id);
    //Read only Model Dialog variant
    ModeloDialog(QWidget *parent, int id, bool visibility);
    ~ModeloDialog();

    Modelo modelo();
    void ReadDependencies();
    void setInputWidgetsData(int id);


    const std::unique_ptr<std::vector<std::unique_ptr<Marca> > > &getListaMarcas();
    const std::unique_ptr<std::vector<std::unique_ptr<Escala> > > &getListaEscalas();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::AniadirDialog *ui;
    std::unique_ptr<std::vector<std::unique_ptr<Marca>>> listaMarcas;
    std::unique_ptr<std::vector<std::unique_ptr<Escala>>> listaEscalas;
    DatabaseManager &man;
    int modeloid;
};

#endif // ANIADIRDIALOG_H
