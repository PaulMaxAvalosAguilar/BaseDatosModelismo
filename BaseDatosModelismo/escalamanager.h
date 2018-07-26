#ifndef ESCALAMANAGER_H
#define ESCALAMANAGER_H

#include <QWidget>

namespace Ui {
class EscalaManager;
}

class EscalaManager : public QWidget
{
    Q_OBJECT

public:
    explicit EscalaManager(QWidget *parent = 0);
    ~EscalaManager();

private:
    Ui::EscalaManager *ui;
};

#endif // ESCALAMANAGER_H
