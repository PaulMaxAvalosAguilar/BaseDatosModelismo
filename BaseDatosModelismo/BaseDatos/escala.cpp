#include "escala.h"

Escala::Escala()
{

}

int Escala::getId() const
{
    return id;
}

void Escala::setId(int value)
{
    id = value;
}

QString Escala::getValor() const
{
    return valor;
}

void Escala::setValor(const QString &value)
{
    valor = value;
}
