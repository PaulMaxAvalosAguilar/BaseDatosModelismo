#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    man(new ModelosManager)
{
    ui->setupUi(this);


    ui->centralWidget->layout()->addWidget(man);

}

MainWindow::~MainWindow()
{
    delete ui;
}


