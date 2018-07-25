#include "modelo.h"

Modelo::Modelo():
    id(0)
{

}

int Modelo::getId() const
{
    return id;
}

void Modelo::setId(int value)
{
    id = value;
}

int Modelo::getMarca() const
{
    return marca;
}

void Modelo::setMarca(int value)
{
    marca = value;
}

QString Modelo::getCodigo() const
{
    return codigo;
}

void Modelo::setCodigo(const QString &value)
{
    codigo = value;
}

QString Modelo::getNombre() const
{
    return nombre;
}

void Modelo::setNombre(const QString &value)
{
    nombre = value;
}

int Modelo::getEscala() const
{
    return escala;
}

void Modelo::setEscala(int value)
{
    escala = value;
}

int Modelo::getNumeroUnidades() const
{
    return numeroUnidades;
}

void Modelo::setNumeroUnidades(int value)
{
    numeroUnidades = value;
}

