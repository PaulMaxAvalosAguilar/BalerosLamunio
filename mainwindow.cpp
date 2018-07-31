#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    reglasvista(new ReglasVista)
{
    ui->setupUi(this);

    ui->centralWidget->layout()->addWidget(reglasvista);
}

MainWindow::~MainWindow()
{

}



