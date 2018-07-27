#ifndef ESCALADIALOG_H
#define ESCALADIALOG_H

#include <QDialog>
#include "BaseDatos/escala.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"

namespace Ui {
class EscalaDialog;
}

class EscalaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EscalaDialog(QWidget *parent = 0);
    EscalaDialog(QWidget *parent, int id);
    ~EscalaDialog();

    Escala escala();
    void setInputWidgetsData(int id);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::EscalaDialog *ui;
    DatabaseManager &man;
    int escalaid;
};

#endif // ESCALADIALOG_H
