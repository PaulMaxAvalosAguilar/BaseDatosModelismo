#ifndef ESCALADAO_H
#define ESCALADAO_H
#include <memory>
#include <vector>
#include <QObject>

class QSqlDatabase;
class Escala;

class EscalaDao : public QObject
{

Q_OBJECT

public:
    explicit EscalaDao(QSqlDatabase& database);
    void init() const;

    void addRecord(Escala& record);
    void updateRecord(Escala& record);
    void removeRecord(int recordId);
    std::unique_ptr<std::vector<std::unique_ptr<Escala>>> getAllRecords() const;

    std::unique_ptr<std::vector<std::unique_ptr<Escala>>> getRecord(int recordId) const;



signals:
    void addedRecord();
    void updatedRecord();
    void removedRecord();

private:
    QSqlDatabase& mDatabase;
};

#endif // PICTUREDAO_H
