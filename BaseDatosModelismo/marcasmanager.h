#ifndef MARCASMANAGER_H
#define MARCASMANAGER_H

#include <QWidget>
#include "BaseDatos/DatabaseManager/databasemanager.h"
#include "BaseDatos/marca.h"
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
