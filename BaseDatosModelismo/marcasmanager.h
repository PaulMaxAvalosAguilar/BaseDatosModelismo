#ifndef MARCASMANAGER_H
#define MARCASMANAGER_H

#include <QWidget>
#include "BaseDatos/DatabaseManager/databasemanager.h"

namespace Ui {
class MarcasManager;
}

class MarcasManager : public QWidget
{
    Q_OBJECT

public:
    explicit MarcasManager(QWidget *parent = 0);
    ~MarcasManager();

private:
    Ui::MarcasManager *ui;
    DatabaseManager &man;
    enum Columna{
        id,
        marcas,
    };
};

#endif // MARCASMANAGER_H
