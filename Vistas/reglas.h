#ifndef REGLAS_H
#define REGLAS_H

#include <QWidget>

namespace Ui {
class Reglas;
}

class Reglas : public QWidget
{
    Q_OBJECT

public:
    explicit Reglas(QWidget *parent = 0);
    ~Reglas();

    void clearTreeWidget();
    void addTopLevelItem(QTreeWidgetItem *item);
    void addChildToParent(QTreeWidgetItem *parent,
                          QTreeWidgetItem *child);


private:
    Ui::Reglas *ui;
};

#endif // REGLAS_H
