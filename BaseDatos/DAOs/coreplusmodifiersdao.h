#ifndef COREPLUSMODIFIERSDAO_H
#define COREPLUSMODIFIERSDAO_H
#include <memory>
#include <vector>
#include <QObject>

class QSqlDatabase;
class Coreplusmodifiers;

class CoreplusmodifiersDao : public QObject
{

Q_OBJECT

public:
    explicit CoreplusmodifiersDao(QSqlDatabase& database);
    void init() const;

    void addRecord(Coreplusmodifiers& record);
    void updateRecord(Coreplusmodifiers& record);
    void removeRecord(int recordId);
    std::unique_ptr<std::vector<std::unique_ptr<Coreplusmodifiers>>> getRecord(int recordId) const;

    void removeAllRecords();
    std::unique_ptr<std::vector<std::unique_ptr<Coreplusmodifiers>>> getAllRecords() const;

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
