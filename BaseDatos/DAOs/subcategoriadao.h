#ifndef SUBCATEGORIADAO_H
#define SUBCATEGORIADAO_H
#include <memory>
#include <vector>
#include <QObject>

class QSqlDatabase;
class Subcategoria;

class SubcategoriaDao : public QObject
{

Q_OBJECT

public:
    explicit SubcategoriaDao(QSqlDatabase& database);
    void init() const;

    void addRecord(Subcategoria& record);
    void updateRecord(Subcategoria& record);
    void removeRecord(int recordId);
    std::unique_ptr<std::vector<std::unique_ptr<Subcategoria>>> getRecord(int recordId) const;

    void removeAllRecords();
    std::unique_ptr<std::vector<std::unique_ptr<Subcategoria>>> getAllRecords() const;

    void createIndexonColumnNombre();
    void createIndexonColumnCategoria_ID();

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
