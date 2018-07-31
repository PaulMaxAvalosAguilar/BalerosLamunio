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

}

MainWindow::~MainWindow()
{
    delete ui;
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
