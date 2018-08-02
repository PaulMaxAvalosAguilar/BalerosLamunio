#include "reglasvista.h"
#include "ui_reglasvista.h"
#include <QDebug>

ReglasVista::ReglasVista(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReglasVista)
{
    ui->setupUi(this);
    controlador.reset(new ReglasVistaController(this));

    configureTreeWidget();

}

ReglasVista::~ReglasVista()
{
    delete ui;
}

void ReglasVista::configureTreeWidget()
{
    ui->treeWidget->setColumnCount(1);
}

void ReglasVista::clearTreeWidget()
{
    ui->treeWidget->clear();
}

void ReglasVista::addTopLevelItem(QTreeWidgetItem *item)
{
    ui->treeWidget->addTopLevelItem(item);
}

void ReglasVista::addChildToParent(QTreeWidgetItem *parent, QTreeWidgetItem *child)
{
    parent->addChild(child);
}

void ReglasVista::on_treeWidget_doubleClicked(const QModelIndex &index)
{
    controlador->showAddDialog(index);
}
