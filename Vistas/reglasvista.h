#ifndef REGLASVISTA_H
#define REGLASVISTA_H

#include <QWidget>
#include <QTreeWidgetItem>

namespace Ui {
class ReglasVista;
}

class ReglasVista : public QWidget
{
    Q_OBJECT

public:
    explicit ReglasVista(QWidget *parent = 0);
    ~ReglasVista();

    void clearTreeWidget();
    void addTopLevelItem(QTreeWidgetItem *item);
    void addChildToParent(QTreeWidgetItem *parent,
                          QTreeWidgetItem *child);

private:
    Ui::ReglasVista *ui;
};

#endif // REGLASVISTA_H
