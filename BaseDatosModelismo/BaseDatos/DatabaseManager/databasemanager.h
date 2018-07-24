#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <memory>
#include <QString>
#include "BaseDatos/modelodao.h"
#include "BaseDatos/marcadao.h"
#include "BaseDatos/escaladao.h"

class QSqlQuery;
class QSqlDatabase;

const QString DATABASE_FILENAME = "BaseDatosModelos";

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    ~DatabaseManager();

    static void debugQuery(const QSqlQuery& query);

protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
private:
    std::unique_ptr<QSqlDatabase> mDatabase;

public://Add your DAO's as public members
    ModeloDao modelodao;
    MarcaDao marcadao;
    EscalaDao escaladao;
};

#endif // DATABASEMANAGER_H
