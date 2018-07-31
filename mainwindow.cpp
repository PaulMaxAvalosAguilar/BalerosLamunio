#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BaseDatos/ENTITIES/regla.h"
#include "BaseDatos/ENTITIES/categoria.h"
#include <QDebug>
#include <QList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setColumnHidden(1,true);



    for(int i = 0; i< 50; i++){
        ui->comboBox->addItem("Paul");

    }




    Regla *regla1 = new Regla();
    regla1->setId(1);
    regla1->setNombre("Paul");
    Regla *regla2 = new Regla();
    regla2->setId(2);
    regla2->setNombre("Max");



    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setData(0,Qt::UserRole, QVariant::fromValue(*regla1));
    item->setText(0,"regla1");
    item->setExpanded(true);

    addTopLevelItem(item);

    QTreeWidgetItem *item2 = new QTreeWidgetItem();
    item2->setData(0,Qt::UserRole, QVariant::fromValue(*regla2));
    item2->setText(0,"regla2");

    addTopLevelItem(item2);

    for(int i = 0; i< 10; i++){
        Categoria cat;
        cat.setId(2);
        cat.setNombre("Categoría");

        QTreeWidgetItem *childItem = new QTreeWidgetItem();
        childItem->setText(0, "hijo");
        childItem->setText(1, "padre");
        childItem->setData(0, Qt::UserRole, QVariant::fromValue(cat));

        QTreeWidgetItem *secondChildItem = new QTreeWidgetItem();
        secondChildItem->setText(0,"HOLO");
        addChildToParent(childItem,secondChildItem);

        addChildToParent(item, childItem);

    }




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTopLevelItem(QTreeWidgetItem *item)
{
    ui->treeWidget->addTopLevelItem(item);

}

void MainWindow::addChildToParent(QTreeWidgetItem *parent, QTreeWidgetItem *child)
{
    parent->addChild(child);
}

void MainWindow::on_treeWidget_clicked(const QModelIndex &index)
{



    const Regla &regla = index.data(Qt::UserRole).value<Regla>();
    const Categoria &cat = index.data(Qt::UserRole).value<Categoria>();

    if(index.data(Qt::UserRole).canConvert<Categoria>())
        qDebug()<<cat.getNombre();

    if(index.data(Qt::UserRole).canConvert<Regla>())
        qDebug()<<regla.getNombre();



}
