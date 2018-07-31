#include "reglasvista.h"
#include "ui_reglasvista.h"

ReglasVista::ReglasVista(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReglasVista),
    controlador()
{
    ui->setupUi(this);
}

ReglasVista::~ReglasVista()
{
    delete ui;
}

void ReglasVista::configureController()
{
    controlador.configureVista(this);
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
