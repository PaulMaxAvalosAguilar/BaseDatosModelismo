#ifndef ESCALAMANAGER_H
#define ESCALAMANAGER_H

#include <QWidget>
#include "BaseDatos/DatabaseManager/databasemanager.h"

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
    DatabaseManager &man;

    enum Columna{
        id,
        valor,
    };

};

#endif // ESCALAMANAGER_H
