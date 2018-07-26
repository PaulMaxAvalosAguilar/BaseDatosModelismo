#include "marca.h"

Marca::Marca()
{

}

Marca::~Marca()
{

}

int Marca::getId() const
{
    return id;
}

void Marca::setId(int value)
{
    id = value;
}

QString Marca::getNombre() const
{
    return nombre;
}

void Marca::setNombre(const QString &value)
{
    nombre = value;
}

bool Marca::operator ==(const Marca &marca)const
{
    if(marca.getId() == this->getId()){
        return true;
    }else{
        return false;
    }
}

bool Marca::operator <(const Marca &marca) const
{
    if(marca.getId() < (this->getId())){
        return true;
    }else{
        return false;
    }
}
