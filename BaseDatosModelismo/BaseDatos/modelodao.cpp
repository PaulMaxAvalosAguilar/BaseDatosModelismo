#include "BaseDatos/modelodao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "BaseDatos/modelo.h"
#include "BaseDatos/DatabaseManager/databasemanager.h"

using namespace std;

ModeloDao::ModeloDao(QSqlDatabase& database) :
    QObject(),
    mDatabase(database)
{
}

void ModeloDao::init() const
{
    if (!mDatabase.tables().contains("Modelo")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE Modelo (id INTEGER PRIMARY KEY AUTOINCREMENT, marca INTEGER,codigo TEXT,nombre TEXT,escala INTEGER,numeroUnidades INTEGER)");
        DatabaseManager::debugQuery(query);
    }
}

void ModeloDao::addRecord(Modelo& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO Modelo (marca,codigo,nombre,escala,numeroUnidades)  VALUES  (:marca,:codigo,:nombre,:escala,:numeroUnidades)");
    query.bindValue(":marca", record.getMarca());
    query.bindValue(":codigo", record.getCodigo());
    query.bindValue(":nombre", record.getNombre());
    query.bindValue(":escala", record.getEscala());
    query.bindValue(":numeroUnidades", record.getNumeroUnidades());
    query.exec();
    record.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
    emit addedRecord();
}

void ModeloDao::updateRecord(Modelo& record)
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE Modelo SET (marca,codigo,nombre,escala,numeroUnidades) = (:marca,:codigo,:nombre,:escala,:numeroUnidades) WHERE  id = (:id)");
    query.bindValue(":marca", record.getMarca());
    query.bindValue(":codigo", record.getCodigo());
    query.bindValue(":nombre", record.getNombre());
    query.bindValue(":escala", record.getEscala());
    query.bindValue(":numeroUnidades", record.getNumeroUnidades());
    query.bindValue(":id", record.getId());
    query.exec();
    DatabaseManager::debugQuery(query);
    emit updatedRecord();
}

void ModeloDao::removeRecord(int recordId)
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM Modelo WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    emit removedRecord();
}

unique_ptr<vector<unique_ptr<Modelo>>> ModeloDao::getAllRecords() const
{
    QSqlQuery query("SELECT * FROM Modelo", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Modelo>>> list(new vector<unique_ptr<Modelo>>());
    while(query.next()) {
        unique_ptr<Modelo> modelo(new Modelo());
        modelo->setId(query.value("id").toInt());
        modelo->setMarca(query.value("marca").toInt());
        modelo->setCodigo(query.value("codigo").toString());
        modelo->setNombre(query.value("nombre").toString());
        modelo->setEscala(query.value("escala").toInt());
        modelo->setNumeroUnidades(query.value("numeroUnidades").toInt());
        list->push_back(move(modelo));
    }
    return list;
}

unique_ptr<vector<unique_ptr<Modelo>>> ModeloDao::getRecord(int recordId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Modelo WHERE id = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Modelo>>> list(new vector<unique_ptr<Modelo>>());
    while(query.next()) {
        std::unique_ptr<Modelo> modelo(new Modelo());
        modelo->setId(query.value("id").toInt());
        modelo->setMarca(query.value("marca").toInt());
        modelo->setCodigo(query.value("codigo").toString());
        modelo->setNombre(query.value("nombre").toString());
        modelo->setEscala(query.value("escala").toInt());
        modelo->setNumeroUnidades(query.value("numeroUnidades").toInt());
        list->push_back(move(modelo));
    }
    return list;
}

std::unique_ptr<std::vector<std::unique_ptr<Modelo> > > ModeloDao::getRecordbyMarca(int recordId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Modelo WHERE marca = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Modelo>>> list(new vector<unique_ptr<Modelo>>());
    while(query.next()) {
        std::unique_ptr<Modelo> modelo(new Modelo());
        modelo->setId(query.value("id").toInt());
        modelo->setMarca(query.value("marca").toInt());
        modelo->setCodigo(query.value("codigo").toString());
        modelo->setNombre(query.value("nombre").toString());
        modelo->setEscala(query.value("escala").toInt());
        modelo->setNumeroUnidades(query.value("numeroUnidades").toInt());
        list->push_back(move(modelo));
    }
    return list;
}

std::unique_ptr<std::vector<std::unique_ptr<Modelo> > > ModeloDao::getRecordbyEscala(int recordId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Modelo WHERE escala = (:id)");
    query.bindValue(":id", recordId);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Modelo>>> list(new vector<unique_ptr<Modelo>>());
    while(query.next()) {
        std::unique_ptr<Modelo> modelo(new Modelo());
        modelo->setId(query.value("id").toInt());
        modelo->setMarca(query.value("marca").toInt());
        modelo->setCodigo(query.value("codigo").toString());
        modelo->setNombre(query.value("nombre").toString());
        modelo->setEscala(query.value("escala").toInt());
        modelo->setNumeroUnidades(query.value("numeroUnidades").toInt());
        list->push_back(move(modelo));
    }
    return list;
}

std::unique_ptr<std::vector<std::unique_ptr<Modelo> > > ModeloDao::getRecordbyNombreLike(QString textoBuscado) const
{

    textoBuscado.append("%");
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM Modelo WHERE nombre like (:texto)");
    query.bindValue(":texto", textoBuscado);
    query.exec();
    DatabaseManager::debugQuery(query);
    unique_ptr<vector<unique_ptr<Modelo>>> list(new vector<unique_ptr<Modelo>>());
    while(query.next()) {
        std::unique_ptr<Modelo> modelo(new Modelo());
        modelo->setId(query.value("id").toInt());
        modelo->setMarca(query.value("marca").toInt());
        modelo->setCodigo(query.value("codigo").toString());
        modelo->setNombre(query.value("nombre").toString());
        modelo->setEscala(query.value("escala").toInt());
        modelo->setNumeroUnidades(query.value("numeroUnidades").toInt());
        list->push_back(move(modelo));
    }
    return list;
}

void ModeloDao::createIndexonColumnMarca(){
    QSqlQuery query("create index marca on Modelo(marca)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void ModeloDao::createIndexonColumnCodigo(){
    QSqlQuery query("create index codigo on Modelo(codigo)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void ModeloDao::createIndexonColumnNombre(){
    QSqlQuery query("create index nombre on Modelo(nombre)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void ModeloDao::createIndexonColumnEscala(){
    QSqlQuery query("create index escala on Modelo(escala)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}

void ModeloDao::createIndexonColumnNumeroUnidades(){
    QSqlQuery query("create index numeroUnidades on Modelo(numeroUnidades)", mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
}
