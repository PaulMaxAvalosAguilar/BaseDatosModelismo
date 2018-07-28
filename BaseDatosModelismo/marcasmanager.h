#ifndef MARCASMANAGER_H
#define MARCASMANAGER_H

#include <QWidget>
#include "BaseDatos/DatabaseManager/databasemanager.h"
#include "BaseDatos/marca.h"
#include "BaseDatos/modelo.h"
#include <memory>

namespace Ui {
class MarcasManager;
}

class MarcasManager : public QWidget
{
    Q_OBJECT

public:
    explicit MarcasManager(QWidget *parent = 0);
    ~MarcasManager();

    void configureTablesettings();

private slots:
    void updateTable();

    void on_addButton_clicked();

    void on_updateButton_clicked();

    void on_deleteButton_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::MarcasManager *ui;
    DatabaseManager &man;
    std::unique_ptr<std::vector<std::unique_ptr<Marca>>> listaMarcas;
    enum Columna{
        id,
        Nombre,
    };
};

#endif // MARCASMANAGER_H
