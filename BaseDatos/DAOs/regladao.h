#ifndef REGLADAO_H
#define REGLADAO_H
#include <memory>
#include <vector>
#include <QObject>

class QSqlDatabase;
class Regla;

class ReglaDao : public QObject
{

Q_OBJECT

public:
    explicit ReglaDao(QSqlDatabase& database);
    void init() const;

    void addRecord(Regla& record);
    void updateRecord(Regla& record);
    void removeRecord(int recordId);
    std::unique_ptr<std::vector<std::unique_ptr<Regla>>> getRecord(int recordId) const;

    void removeAllRecords();
    std::unique_ptr<std::vector<std::unique_ptr<Regla>>> getAllRecords() const;

    void createIndexonColumnNombre();

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
