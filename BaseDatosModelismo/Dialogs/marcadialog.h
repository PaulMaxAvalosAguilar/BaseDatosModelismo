#ifndef MARCADIALOG_H
#define MARCADIALOG_H

#include <QDialog>
#include <BaseDatos/marca.h>
#include <BaseDatos/DatabaseManager/databasemanager.h>

namespace Ui {
class MarcaDialog;
}

class MarcaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MarcaDialog(QWidget *parent = 0);
    MarcaDialog(QWidget *parent, int id);
    MarcaDialog(QWidget *parent, int id, bool visibility);
    ~MarcaDialog();

    Marca marca();
    void setInputWidgetsData(int id);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::MarcaDialog *ui;
    DatabaseManager &man;
    int marcaid;
};

#endif // MARCADIALOG_H
