#ifndef ESCALADIALOG_H
#define ESCALADIALOG_H

#include <QDialog>
#include "BaseDatos/escala.h"

namespace Ui {
class EscalaDialog;
}

class EscalaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EscalaDialog(QWidget *parent = 0);
    ~EscalaDialog();
    Escala escala();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::EscalaDialog *ui;

    int escalaid;
};

#endif // ESCALADIALOG_H
