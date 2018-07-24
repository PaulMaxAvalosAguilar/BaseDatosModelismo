#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BaseDatos/DatabaseManager/databasemanager.h"
#include "BaseDatos/marca.h"
#include <vector>
#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<std::vector<std::unique_ptr<Marca>>> listaMarcas;
    std::unique_ptr<std::vector<std::unique_ptr<Escala>>> listaEscalas;
    DatabaseManager &man;
};


#endif // MAINWINDOW_H
