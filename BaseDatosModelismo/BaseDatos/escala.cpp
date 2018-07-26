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

bool Escala::operator==(const Escala &escala) const
{
    if(escala.getId() == this->getId()){
        return true;
    }else{
        return false;
    }
}

bool Escala::operator<(const Escala &escala) const
{
    if(escala.getId() < this->getId()){
        return true;
    }else{
        return false;
    }
}

