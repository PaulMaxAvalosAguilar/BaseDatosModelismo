#ifndef ESCALADIALOG_H
#define ESCALADIALOG_H

#include <QWidget>

namespace Ui {
class EscalaDialog;
}

class EscalaDialog : public QWidget
{
    Q_OBJECT

public:
    explicit EscalaDialog(QWidget *parent = 0);
    ~EscalaDialog();

private:
    Ui::EscalaDialog *ui;
};

#endif // ESCALADIALOG_H
