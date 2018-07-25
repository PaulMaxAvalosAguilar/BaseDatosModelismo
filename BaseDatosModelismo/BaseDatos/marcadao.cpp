#include "BaseDatos/marcadao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "BaseDatos/marca.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"

using namespace std;

MarcaDao::MarcaDao(QSqlDatabase& database) :
    QObject(),
    mDatabase(database)
{
}

void MarcaDao::init() const
{
    if (!mDatabase.tables().contains("Marca")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE Marca (id INTEGER PRIMARY KEY AUTOINCREMENT, nombre TEXT)");
        DatabaseManager::debugQuery(query);
    }
}

void MarcaDao::addRecord(Marca& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO Marca (nombre)  VALUES  (:nombre)");
    query.bindValue(":nombre", record.getNombre());
    query.exec();
    record.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
    emit addedRecord();
}

void MarcaDao::updateRecord(Marca& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE Marca (nombre) = (:nombre) WHERE  id = (:id)");
    query.bindValue(":nombre", record.getNombre());
    query.bindValue(":id", record.getId());
    query.exec();
    DatabaseManager::debugQuery(query);
    emit updatedRecord();
}

void MarcaDao::removeRecord(int recordId)
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM Marca WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedRecord();
}

unique_ptr<vector<unique_ptr<Marca>>> MarcaDao::getAllRecords() const
{
    QSqlQuery query("SELECT * FROM Marca", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Marca>>> list(new vector<unique_ptr<Marca>>());
    while(query.next()) {
        unique_ptr<Marca> marca(new Marca());
        marca->setId(query.value("id").toInt());
        marca->setNombre(query.value("nombre").toString());
        list->push_back(move(marca));
    }
    return list;
}

unique_ptr<vector<unique_ptr<Marca>>> MarcaDao::getRecord(int recordId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Marca WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Marca>>> list(new vector<unique_ptr<Marca>>());
    while(query.next()){
        std::unique_ptr<Marca> marca(new Marca());
        marca->setId(query.value("id").toInt());
        marca->setNombre(query.value("nombre").toString());
        list->push_back(move(marca));
    }
    return list;
}
