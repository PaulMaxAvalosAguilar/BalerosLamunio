#include "reglasvista.h"
#include "ui_reglasvista.h"
#include <QDebug>

ReglasVista::ReglasVista(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReglasVista)
{
    ui->setupUi(this);
    configureTreeWidget();

    controlador.reset(new ReglasVistaController(this));

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



void ReglasVista::on_addpB_clicked()
{
    controlador->showAddDialog(ui->treeWidget->currentIndex());
}

void ReglasVista::on_updatepB_clicked()
{
    controlador->showupdateDialog(ui->treeWidget->currentIndex());
}

void ReglasVista::on_removepB_clicked()
{

}
