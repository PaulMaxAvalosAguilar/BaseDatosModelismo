#ifndef MODELO_H
#define MODELO_H

#include <QString>

class Modelo
{
public:
    Modelo();

    int getId() const;
    void setId(int value);

    QString getMarca() const;
    void setMarca(const QString &value);

    QString getCodigo() const;
    void setCodigo(const QString &value);

    QString getNombre() const;
    void setNombre(const QString &value);

    int getNumeroUnidades() const;
    void setNumeroUnidades(int value);

    QString getEscala() const;
    void setEscala(const QString &value);

private:
    int id;
    QString marca;
    QString codigo;
    QString nombre;
    QString escala;
    int numeroUnidades;
};

#endif // MODELO_H
