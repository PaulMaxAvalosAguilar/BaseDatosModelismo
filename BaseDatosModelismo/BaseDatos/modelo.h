#ifndef MODELO_H
#define MODELO_H

#include <QString>

class Modelo
{
public:
    Modelo();



    int getId() const;
    void setId(int value);

    int getMarca() const;
    void setMarca(int value);

    QString getCodigo() const;
    void setCodigo(const QString &value);

    QString getNombre() const;
    void setNombre(const QString &value);

    int getEscala() const;
    void setEscala(int value);

    int getNumeroUnidades() const;
    void setNumeroUnidades(int value);

private:
    int id;
    int marca;
    QString codigo;
    QString nombre;
    int escala;
    int numeroUnidades;
};

#endif // MODELO_H
