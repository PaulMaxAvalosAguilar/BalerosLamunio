#ifndef COREPLUSMODIFIERDAO_H
#define COREPLUSMODIFIERDAO_H
#include <memory>
#include <vector>
#include <QObject>

class QSqlDatabase;
class Coreplusmodifier;

class CoreplusmodifierDao : public QObject
{

Q_OBJECT

public:
    explicit CoreplusmodifierDao(QSqlDatabase& database);
    void init() const;

    void addRecord(Coreplusmodifier& record);
    void updateRecord(Coreplusmodifier& record);
    void removeRecord(int recordId);
    std::unique_ptr<std::vector<std::unique_ptr<Coreplusmodifier>>> getRecord(int recordId) const;

    void removeAllRecords();
    std::unique_ptr<std::vector<std::unique_ptr<Coreplusmodifier>>> getAllRecords() const;

    void createIndexonColumnFullNombre();
    void createIndexonColumnCoreBearing_ID();

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
