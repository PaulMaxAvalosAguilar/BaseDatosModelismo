#ifndef MARCADAO_H
#define MARCADAO_H
#include <memory>
#include <vector>
#include <QObject>

class QSqlDatabase;
class Marca;

class MarcaDao : public QObject
{

Q_OBJECT

public:
    explicit MarcaDao(QSqlDatabase& database);
    void init() const;

    void addRecord(Marca& record);
    void updateRecord(Marca& record);
    void removeRecord(int recordId);
    std::unique_ptr<std::vector<std::unique_ptr<Marca>>> getAllRecords() const;

    std::unique_ptr<std::vector<std::unique_ptr<Marca>>> getRecord(int recordId) const;


signals:
    void addedRecord();
    void updatedRecord();
    void removedRecord();

private:
    QSqlDatabase& mDatabase;
};

#endif // PICTUREDAO_H
