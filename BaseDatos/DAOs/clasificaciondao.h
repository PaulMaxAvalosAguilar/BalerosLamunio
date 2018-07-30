#ifndef CLASIFICACIONDAO_H
#define CLASIFICACIONDAO_H
#include <memory>
#include <vector>
#include <QObject>

class QSqlDatabase;
class Clasificacion;

class ClasificacionDao : public QObject
{

Q_OBJECT

public:
    explicit ClasificacionDao(QSqlDatabase& database);
    void init() const;

    void addRecord(Clasificacion& record);
    void updateRecord(Clasificacion& record);
    void removeRecord(int recordId);
    std::unique_ptr<std::vector<std::unique_ptr<Clasificacion>>> getRecord(int recordId) const;

    void removeAllRecords();
    std::unique_ptr<std::vector<std::unique_ptr<Clasificacion>>> getAllRecords() const;

    void createIndexonColumnSubcategoria_ID();
    void createIndexonColumnCoreplusmodifier_ID();

signals:
    void addedRecord();
    void updatedRecord();
    void removedRecord();

    void updatedManyRecords();
    void removedAllRecords();

private:
    QSqlDatabase& mDatabase;
};

#endif
