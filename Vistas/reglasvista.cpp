#include "reglasvista.h"
#include "ui_reglasvista.h"
#include <QScrollBar>
#include <QDebug>

ReglasVista::ReglasVista(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReglasVista)
{
    ui->setupUi(this);
    configureTreeWidget();
    configureTableWidget();

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

void ReglasVista::configureTableWidget()
{
    //Empty no configurations required
}

void ReglasVista::addDatatoTable()
{

    //GET CURRENT SCROLLBARS POSITIONS
    QScrollBar *verticalScroll = ui->tableWidget->verticalScrollBar();
    QScrollBar *horizontalScroll = ui->tableWidget->verticalScrollBar();
    int lastVscrollposition = verticalScroll->value();
    int lastHscrollposition = horizontalScroll->value();
    //GET CURRENT SCROLLBARS POSITIONS


    //RESET SCROLLBARS POSITIONS
    verticalScroll->setValue(lastVscrollposition);
    horizontalScroll->setValue(lastHscrollposition);
    //RESET SCROLLBARS POSIITONS
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
    controlador->removeAction(ui->treeWidget->currentIndex());
}
