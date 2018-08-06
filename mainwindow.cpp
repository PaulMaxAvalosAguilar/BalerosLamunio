#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    reglasvista(new ReglasVista),
    searcher(new Searcher)
{
    ui->setupUi(this);

    ui->Reglas->layout()->addWidget(reglasvista);
    ui->Searcher->layout()->addWidget(searcher);
}

MainWindow::~MainWindow()
{

}



