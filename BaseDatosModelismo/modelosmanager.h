#ifndef MODELOSMANAGER_H
#define MODELOSMANAGER_H

#include <QWidget>

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

private:
    Ui::ModelosManager *ui;
};

#endif // MODELOSMANAGER_H
