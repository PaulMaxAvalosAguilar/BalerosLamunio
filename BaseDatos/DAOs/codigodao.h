#ifndef CODIGODAO_H
#define CODIGODAO_H
#include <memory>
#include <vector>
#include <QObject>

class QSqlDatabase;
class Codigo;

class CodigoDao : public QObject
{

Q_OBJECT

public:
    explicit CodigoDao(QSqlDatabase& database);
    void init() const;

    void addRecord(Codigo& record);
    void updateRecord(Codigo& record);
    void removeRecord(int recordId);
    std::unique_ptr<std::vector<std::unique_ptr<Codigo>>> getRecord(int recordId) const;

    void removeAllRecords();
    std::unique_ptr<std::vector<std::unique_ptr<Codigo>>> getAllRecords() const;
    std::unique_ptr<std::vector<std::unique_ptr<Codigo>>>
    getAllRecordsbySubcategoria(int recordId) const;

    void createIndexonColumnCaracteres();
    void createIndexonColumnSubcategoria_ID();

signals:
    void addedRecord();
    void updatedRecord();
    void removedRecord();

    void updatedManyRecords();
    void removedAllRecords();

private:
    QSqlDatabase& mDatabase;
};

#endif // PICTUREDAO_H
