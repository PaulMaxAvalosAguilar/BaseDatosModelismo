#ifndef MODELOSMANAGER_H
#define MODELOSMANAGER_H

#include <QWidget>
#include "BaseDatos/DatabaseManager/databasemanager.h"
#include "BaseDatos/modelo.h"
#include <vector>
#include <memory>

namespace Ui {
class ModelosManager;
}

class ModelosManager : public QWidget
{
    Q_OBJECT


public:
    explicit ModelosManager(QWidget *parent = 0);
    ~ModelosManager();

private slots:
    void on_addPB_clicked();
    void updateTable();

    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::ModelosManager *ui;
    DatabaseManager &man;
    std::unique_ptr<std::vector<std::unique_ptr<Modelo>>> listaModelos;

    enum Columna{
        id,
        Marca,
        Codigo,
        Nombre,
        Escala,
        Unidades,
    };
};

#endif // MODELOSMANAGER_H
