#ifndef COREBEARINGDAO_H
#define COREBEARINGDAO_H
#include <memory>
#include <vector>
#include <QObject>

class QSqlDatabase;
class Corebearing;

class CorebearingDao : public QObject
{

Q_OBJECT

public:
    explicit CorebearingDao(QSqlDatabase& database);
    void init() const;

    void addRecord(Corebearing& record);
    void updateRecord(Corebearing& record);
    void removeRecord(int recordId);
    std::unique_ptr<std::vector<std::unique_ptr<Corebearing>>> getRecord(int recordId) const;

    void removeAllRecords();
    std::unique_ptr<std::vector<std::unique_ptr<Corebearing>>> getAllRecords() const;

    void createIndexonColumnCoreValue();
    void createIndexonColumnDiamInterno();
    void createIndexonColumnDiamExterno();
    void createIndexonColumnEspesura();
    void createIndexonColumnRegla_ID();

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

