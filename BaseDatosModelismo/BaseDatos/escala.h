#ifndef ESCALA_H
#define ESCALA_H

#include <QString>
#include <QMetaType>

class Escala
{
public:
    Escala();
    int getId() const;
    void setId(int value);

    QString getValor() const;
    void setValor(const QString &value);

private:
    int id;
    QString valor;
};

#endif // ESCALA_H

Q_DECLARE_METATYPE(Escala)
