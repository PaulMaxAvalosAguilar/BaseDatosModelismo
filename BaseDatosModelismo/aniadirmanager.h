#ifndef ANIADIRMANAGER_H
#define ANIADIRMANAGER_H

#include <QWidget>

namespace Ui {
class Aniadirmanager;
}

class Aniadirmanager : public QWidget
{
    Q_OBJECT

public:
    explicit Aniadirmanager(QWidget *parent = 0);
    ~Aniadirmanager();

private:
    Ui::Aniadirmanager *ui;
};

#endif // ANIADIRMANAGER_H
