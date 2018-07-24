#ifndef ANIADIRDIALOG_H
#define ANIADIRDIALOG_H

#include <QDialog>

namespace Ui {
class AniadirDialog;
}

class AniadirDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AniadirDialog(QWidget *parent = 0);
    ~AniadirDialog();

private:
    Ui::AniadirDialog *ui;
};

#endif // ANIADIRDIALOG_H
