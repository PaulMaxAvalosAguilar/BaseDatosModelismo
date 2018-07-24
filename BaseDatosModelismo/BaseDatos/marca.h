#ifndef MARCA_H
#define MARCA_H

#include <QString>

class Marca
{
public:
    Marca();
    int getId() const;
    void setId(int value);

    QString getNombre() const;
    void setNombre(const QString &value);

private:
    int id;
    QString nombre;
};

#endif // MARCA_H
