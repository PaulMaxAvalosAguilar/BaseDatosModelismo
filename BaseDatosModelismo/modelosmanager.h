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

    void configureTablesettings();

private slots:

    void updateTable();


    void on_addPB_clicked();



    void on_updPB_clicked();

    void on_delPB_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::ModelosManager *ui;
    DatabaseManager &man;
    std::unique_ptr<std::vector<std::unique_ptr<Modelo>>> listaModelos;


    enum Columna{
            id,
            Marcac,
            Codigo,
            Nombre,
            Escalac,
            Unidades,
        };
};

#endif // MODELOSMANAGER_H
