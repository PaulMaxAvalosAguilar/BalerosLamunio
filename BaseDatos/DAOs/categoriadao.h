#ifndef CATEGORIADAO_H
#define CATEGORIADAO_H
#include <memory>
#include <vector>
#include <QObject>

class QSqlDatabase;
class Categoria;

class CategoriaDao : public QObject
{

Q_OBJECT

public:
    explicit CategoriaDao(QSqlDatabase& database);
    void init() const;

    void addRecord(Categoria& record);
    void updateRecord(Categoria& record);
    void removeRecord(int recordId);
    std::unique_ptr<std::vector<std::unique_ptr<Categoria>>> getRecord(int recordId) const;

    void removeAllRecords();
    std::unique_ptr<std::vector<std::unique_ptr<Categoria>>> getAllRecords() const;
    std::unique_ptr<std::vector<std::unique_ptr<Categoria>>>
    getAllRecordsByRegla(int recordId) const;

    void createIndexonColumnNombre() const;
    void createIndexonColumnRegla_ID() const;

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
