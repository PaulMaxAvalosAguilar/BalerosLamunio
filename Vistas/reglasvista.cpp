#include "reglasvista.h"
#include "ui_reglasvista.h"

ReglasVista::ReglasVista(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReglasVista),
    controlador(this)
{
    ui->setupUi(this);

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
