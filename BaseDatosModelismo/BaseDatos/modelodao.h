#ifndef MODELODAO_H
#define MODELODAO_H
#include <memory>
#include <vector>
#include <QObject>

class QSqlDatabase;
class Modelo;

class ModeloDao : public QObject
{

Q_OBJECT

public:
    explicit ModeloDao(QSqlDatabase& database);
    void init() const;

    void addRecord(Modelo& record);
    void updateRecord(Modelo& record);
    void removeRecord(int recordId);
    std::unique_ptr<std::vector<std::unique_ptr<Modelo>>> getAllRecords() const;

    std::unique_ptr<Modelo> getRecord(int recordId) const;


signals:
    void addedRecord();
    void updatedRecord();
    void removedRecord();

private:
    QSqlDatabase& mDatabase;
};

#endif // PICTUREDAO_H
