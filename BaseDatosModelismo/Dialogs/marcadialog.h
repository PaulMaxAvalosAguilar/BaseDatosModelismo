#ifndef MARCADIALOG_H
#define MARCADIALOG_H

#include <QWidget>

namespace Ui {
class MarcaDialog;
}

class MarcaDialog : public QWidget
{
    Q_OBJECT

public:
    explicit MarcaDialog(QWidget *parent = 0);
    ~MarcaDialog();

private:
    Ui::MarcaDialog *ui;
};

#endif // MARCADIALOG_H
