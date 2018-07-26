#ifndef MARCA_H
#define MARCA_H

#include <QString>
#include <QMetaType>

class Marca
{


public:
    Marca();
    ~Marca();

    int getId() const;
    void setId(int value);

    QString getNombre() const;
    void setNombre(const QString &value);

    bool operator==(const Marca &marca) const;
    bool operator< (const Marca  &marca) const;

private:
    int id;
    QString nombre;
};


Q_DECLARE_METATYPE(Marca)

#endif // MARCA_H
