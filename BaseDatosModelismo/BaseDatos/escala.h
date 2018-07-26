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

    bool operator==(const Escala &escala) const;
    bool operator< (const Escala  &escala) const;

private:
    int id;
    QString valor;
};

#endif // ESCALA_H

Q_DECLARE_METATYPE(Escala)
