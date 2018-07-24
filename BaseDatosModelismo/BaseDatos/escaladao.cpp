#include "BaseDatos/escaladao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "BaseDatos/escala.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"

using namespace std;

EscalaDao::EscalaDao(QSqlDatabase& database) :
    QObject(),
    mDatabase(database)
{
}

void EscalaDao::init() const
{
    if (!mDatabase.tables().contains("Escala")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE Escala (id INTEGER PRIMARY KEY AUTOINCREMENT, valor TEXT)");
        DatabaseManager::debugQuery(query);
    }
}

void EscalaDao::addRecord(Escala& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO Escala (valor)  VALUES  (:valor)");
    query.bindValue(":valor", record.getValor());
    query.exec();
    record.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
    emit addedRecord();
}

void EscalaDao::updateRecord(Escala& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE Escala (valor) = (:valor) WHERE  id = (:id)");
    query.bindValue(":valor", record.getValor());
    query.bindValue(":id", record.getId());
    query.exec();
    DatabaseManager::debugQuery(query);
    emit updatedRecord();
}

void EscalaDao::removeRecord(int recordId)
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM Escala WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedRecord();
}

unique_ptr<vector<unique_ptr<Escala>>> EscalaDao::getAllRecords() const
{
    QSqlQuery query("SELECT * FROM Escala", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Escala>>> list(new vector<unique_ptr<Escala>>());
    while(query.next()) {
        unique_ptr<Escala> escala(new Escala());
        escala->setId(query.value("id").toInt());
        escala->setValor(query.value("valor").toString());
        list->push_back(move(escala));
    }
    return list;
}

std::unique_ptr<Escala> EscalaDao::getRecord(int recordId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Escala WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    std::unique_ptr<Escala> escala(new Escala());
    escala->setId(query.value("id").toInt());
    escala->setValor(query.value("valor").toString());
    return escala;
}


