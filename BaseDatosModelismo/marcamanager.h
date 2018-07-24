#ifndef MARCAMANAGER_H
#define MARCAMANAGER_H

#include <QWidget>


namespace Ui {
class MarcaManager;
}

class MarcaManager : public QWidget
{
    Q_OBJECT

public:
    explicit MarcaManager(QWidget *parent = 0);
    ~MarcaManager();

private slots:
    void on_marcapushButton_clicked();

private:
    Ui::MarcaManager *ui;

};

#endif // MARCAMANAGER_H
