#ifndef MARCASMANAGER_H
#define MARCASMANAGER_H

#include <QWidget>

namespace Ui {
class MarcasManager;
}

class MarcasManager : public QWidget
{
    Q_OBJECT

public:
    explicit MarcasManager(QWidget *parent = 0);
    ~MarcasManager();

private:
    Ui::MarcasManager *ui;
};

#endif // MARCASMANAGER_H
