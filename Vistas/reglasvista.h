#ifndef REGLASVISTA_H
#define REGLASVISTA_H

#include <QWidget>
#include <QTreeWidgetItem>
#include "Controllers/reglasvistacontroller.h"
#include <memory>

namespace Ui {
class ReglasVista;
}

class ReglasVista : public QWidget
{

    Q_OBJECT

public:
    explicit ReglasVista(QWidget *parent = 0);
    ~ReglasVista();

    void configureTreeWidget();
    void clearTreeWidget();
    void addTopLevelItem(QTreeWidgetItem *item);
    void addChildToParent(QTreeWidgetItem *parent,
                          QTreeWidgetItem *child);

private slots:

    void on_addpB_clicked();

    void on_updatepB_clicked();

    void on_removepB_clicked();

private:
    Ui::ReglasVista *ui;
    std::unique_ptr<ReglasVistaController> controlador;

};

#endif // REGLASVISTA_H
