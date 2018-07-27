#ifndef ESCALADIALOG_H
#define ESCALADIALOG_H

#include <QDialog>

namespace Ui {
class EscalaDialog;
}

class EscalaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EscalaDialog(QWidget *parent = 0);
    ~EscalaDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::EscalaDialog *ui;
};

#endif // ESCALADIALOG_H
