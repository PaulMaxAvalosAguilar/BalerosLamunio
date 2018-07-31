#include "reglas.h"
#include "ui_reglas.h"

Reglas::Reglas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reglas)
{
    ui->setupUi(this);
}

Reglas::~Reglas()
{
    delete ui;
}

void Reglas::clearTreeWidget()
{
    ui->treeWidget->clear();
}

void Reglas::addTopLevelItem(QTreeWidgetItem *item)
{
    ui->treeWidget->addTopLevelItem(item);
}

void Reglas::addChildToParent(QTreeWidgetItem *parent, QTreeWidgetItem *child)
{
    parent->addChild(child);
}
