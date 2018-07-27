#ifndef MARCADIALOG_H
#define MARCADIALOG_H

#include <QDialog>

namespace Ui {
class MarcaDialog;
}

class MarcaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MarcaDialog(QWidget *parent = 0);
    ~MarcaDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::MarcaDialog *ui;
};

#endif // MARCADIALOG_H
