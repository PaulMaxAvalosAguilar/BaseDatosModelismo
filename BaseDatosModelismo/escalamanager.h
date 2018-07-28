#ifndef ESCALAMANAGER_H
#define ESCALAMANAGER_H

#include <QWidget>
#include "BaseDatos/DatabaseManager/databasemanager.h"
#include "BaseDatos/escala.h"
#include "BaseDatos/modelo.h"
#include <memory>

namespace Ui {
class EscalaManager;
}

class EscalaManager : public QWidget
{
    Q_OBJECT

public:
    explicit EscalaManager(QWidget *parent = 0);
    ~EscalaManager();
    void configureTablesettings();

private slots:
    void updateTable();

    void on_addButton_clicked();

    void on_updateButton_clicked();

    void on_deleteButton_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

private:

    Ui::EscalaManager *ui;
    DatabaseManager &man;
    std::unique_ptr<std::vector<std::unique_ptr<Escala>>> listaEscalas;
    enum Columna{
        id,
        valor,
    };

};

#endif // ESCALAMANAGER_H
