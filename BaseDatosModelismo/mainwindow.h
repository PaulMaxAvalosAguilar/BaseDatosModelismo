#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modelosmanager.h"
#include "marcasmanager.h"
#include "escalamanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ModelosManager *man;
    MarcasManager *marcas;
    EscalaManager *escalas;
};


#endif // MAINWINDOW_H
